#include <SapphireEngine/Resource.h>
#include <SapphireEngine/Private/BaseInterface.h>
#include <CoreLib/File.h>
#include <map>

#include <SapphireEngine/Node.h>

#include <SapphireEngine/Assets/_include.h>
#include <SapphireEngine/Components/MeshRenderer.h>

#include <ThirdParty/assimp/Importer.hpp>
#include <ThirdParty/assimp/scene.h>
#include <ThirdParty/assimp/postprocess.h>
#include <ThirdParty/glad/glad.h>

namespace SapphireEngine
{
    using namespace Private;
    using namespace std;

    static string read_path;
    void Resource::SetReadPath(const string& path)
    {
        read_path = path;
    }

    string Resource::GetReadPath()
    {
        return read_path;
    }

    static map<string, MObject*> cache;

    static Bitmap* LoadBitmap(const string& name)
    {
        int width, height, channel;
        unsigned char* data = ResourceInterface::LoadBitmap(name, &width, &height, &channel);
        Bitmap* bitmap = new Bitmap();
        bitmap->SetData(data, width, height, channel);
        return bitmap;
    }
    static void LoadTexture2D(const string& name)
    {
        Texture2D* tex = new Texture2D();
        tex->SetData(name, "", LoadBitmap(name));
        cache[name] = tex;
    }

    static CubeMap* LoadCubeMap(const string& name)
    {
        CubeMap* cubeMap = new CubeMap;

        string faces[6] =
        {
            name + "/right.jpg",
            name + "/left.jpg",
            name + "/top.jpg",
            name + "/bottom.jpg",
            name + "/front.jpg",
            name + "/back.jpg"
        };

        glGenTextures(1, &cubeMap->id);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMap->id);

        for (unsigned int i = 0; i < 6; i++)
        {
            Bitmap* bitmap = LoadBitmap(faces[i].c_str());
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                0, GL_RGB, bitmap->get_width(), bitmap->get_height(), 0, GL_RGB, GL_UNSIGNED_BYTE, bitmap->GetNativeData()
            );
            //delete bitmap;
        }
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

        return cubeMap;
    }

#pragma region LoadModel
    static vector<Texture2D*> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName, const string& dir)
    {
        vector<Texture2D*> textures;
        auto d = mat->GetTextureCount(aiTextureType::aiTextureType_HEIGHT);
        for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
        {
            aiString str;
            mat->GetTexture(type, i, &str);
            Texture2D* texture = new Texture2D;

            auto name = StringUtil::Concat(dir, "/", PathUtil::GetFilename(str.C_Str()));

            texture->SetData(str.C_Str(), typeName, LoadBitmap(name));
            //texture.id = TextureFromFile(str.C_Str(), directory);
            //texture.type = typeName;
            //texture.path = str;
            textures.push_back(texture);
        }
        return textures;
    }

    static Mesh* processMesh(aiMesh* mesh, const aiScene* scene, const string& dir)
    {
        vector<Vertex> vertices;
        vector<unsigned int> indices;
        vector<Texture2D*> textures;

        vertices.reserve(mesh->mNumVertices);
        for (unsigned int i = 0; i < mesh->mNumVertices; i++)
        {
            Vertex vertex;
            vertex.Position = { mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z };
            vertex.Normal = { mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z };
            if (mesh->mTextureCoords[0]) // 网格是否有纹理坐标？
            {
                vertex.TexCoords = { mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y };
            }
            else
                vertex.TexCoords = Vector2::Zero();

            vertices.push_back(vertex);
        }
        //index
        indices.reserve(mesh->mNumFaces);
        for (unsigned int i = 0; i < mesh->mNumFaces; i++)
        {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++)
                indices.push_back(face.mIndices[j]);
        }
        // 处理索引
        //...
            // 处理材质
        if (mesh->mMaterialIndex >= 0)
        {
            aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
            vector<Texture2D*> diffuseMaps = loadMaterialTextures(material,
                aiTextureType_DIFFUSE, "mat_diffuse_tex", dir);
            textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

            vector<Texture2D*> specularMaps = loadMaterialTextures(material,
                aiTextureType_SPECULAR, "mat_specular_tex", dir);
            textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());

            vector<Texture2D*> normalMaps = loadMaterialTextures(material,
                aiTextureType_NORMALS, "mat_normal_tex", dir);
            textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
        }

        Mesh* nmesh = new Mesh;
        nmesh->SetData(vertices, indices, textures);
        return nmesh;
    }
    static void processNode(aiNode* node, const aiScene* scene, Node* pnode, const string& dir)
    {
        for (unsigned int i = 0; i < node->mNumMeshes; i++)
        {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];

            Node* n = new Node(mesh->mName.C_Str(), pnode);
            n->AddComponent<MeshRenderer>()->set_mesh(processMesh(mesh, scene, dir));

            //meshes->push_back(processMesh(mesh, scene));
        }
        for (unsigned int i = 0; i < node->mNumChildren; i++)
        {
            processNode(node->mChildren[i], scene, pnode, dir);
        }
    }
    static Node* LoadModel(const string& path)
    {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        {
            throw importer.GetErrorString();
            //cout << "ERROR::ASSIMP::" << importer.GetErrorString() << endl;
            return nullptr;
        }
        string directory = path.substr(0, path.find_last_of('/'));



        Node* node = new Node(PathUtil::GetFilenameWithoutExt(path));

        vector<Mesh*> meshes;
        processNode(scene->mRootNode, scene, node, directory);

        return node;
    }

#pragma endregion



    MObject* Resource::Load(const string& name, Type* type)
    {
        string filename = read_path + "/" + name;
        if (cache[filename] != nullptr)
        {
            return cache[filename];
        }

        if (type->IsSubclassOf(cltypeof<Texture2D>()))
        {
            LoadTexture2D(filename);
        }
        if (type->IsSubclassOf(cltypeof<Node>()))
        {
            cache[filename] = LoadModel(filename);
        }
        if (type->IsSubclassOf(cltypeof<CubeMap>()))
        {
            return LoadCubeMap(filename);
        }

        return cache[filename];
    }

    void LoadAsync(const string& name, Type* type, Action<MObject*>* callback)
    {
        string filename = read_path + "/" + name;
        if (cache[filename] != nullptr)
        {
            callback->Invoke(cache[filename]);
        }
    }
}
