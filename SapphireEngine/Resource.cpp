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

namespace SapphireEngine
{
    using namespace Private;
    using namespace std;

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

            Node* n = new Node(mesh->mName.C_Str(), pnode, true);
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



    MObject* Resource::Load(const string& name, Type* type)
    {
        if (cache[name] != nullptr)
        {
            return cache[name];
        }

        if (type->IsSubclassOf(cltypeof<Texture2D>()))
        {
            LoadTexture2D(name);
        }
        if (type->IsSubclassOf(cltypeof<Node>()))
        {
            cache[name] = LoadModel(name);
        }

        return cache[name];
    }

    void LoadAsync(const string& name, Type* type, Action<MObject*>* callback)
    {
        if (cache[name] != nullptr)
        {
            callback->Invoke(cache[name]);
        }
    }
}
