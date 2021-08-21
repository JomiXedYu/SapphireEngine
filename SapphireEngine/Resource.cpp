#include <SapphireEngine/Resource.h>
#include <SapphireEngine/Private/BaseInterface.h>

#include <map>

#include <SapphireEngine/Assets/Bitmap.h>
#include <SapphireEngine/Assets/Texture2D.h>
#include <SapphireEngine/Node.h>
#include <SapphireEngine/Assets/Mesh.h>

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
        int width, height;
        unsigned char* data = ResourceInterface::LoadBitmap(name, &width, &height);
        Bitmap* bitmap = new Bitmap();
        bitmap->SetData(data, width, height);
        return bitmap;
    }
    static void LoadTexture2D(const string& name)
    {
        Texture2D* tex = new Texture2D();
        tex->SetData(name, "", LoadBitmap(name));
        cache[name] = tex;
    }

    static vector<Texture2D> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName)
    {
        vector<Texture2D> textures;
        for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
        {
            aiString str;
            mat->GetTexture(type, i, &str);
            Texture2D texture;
            texture.SetData(str.C_Str(), typeName, LoadBitmap(str.C_Str()));
            //texture.id = TextureFromFile(str.C_Str(), directory);
            //texture.type = typeName;
            //texture.path = str;
            textures.push_back(texture);
        }
        return textures;
    }
    /*
    static Mesh* processMesh(aiMesh* mesh, const aiScene* scene)
    {
        vector<Vertex> vertices;
        vector<unsigned int> indices;
        vector<Texture2D*> textures;

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
            vector<Texture2D> diffuseMaps = loadMaterialTextures(material,
                aiTextureType_DIFFUSE, "texture_diffuse");
            textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
            vector<Texture2D> specularMaps = loadMaterialTextures(material,
                aiTextureType_SPECULAR, "texture_specular");
            textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
        }

        Mesh* nmesh = new Mesh;
        nmesh->SetData(vertices, indices, textures);
        return nmesh;
    }
    static void processNode(aiNode* node, const aiScene* scene, vector<Mesh*>* meshes)
    {
        for (unsigned int i = 0; i < node->mNumMeshes; i++)
        {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            meshes->push_back(processMesh(mesh, scene));
        }
        for (unsigned int i = 0; i < node->mNumChildren; i++)
        {
            processNode(node->mChildren[i], scene, meshes);
        }
    }
    static Node* LoadModel(const string& name)
    {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(name, aiProcess_Triangulate | aiProcess_FlipUVs);

        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        {
            throw importer.GetErrorString();
            //cout << "ERROR::ASSIMP::" << importer.GetErrorString() << endl;
            return nullptr;
        }
        auto directory = name.substr(0, name.find_last_of('/'));

        vector<Mesh*> meshes;
        processNode(scene->mRootNode, scene, &meshes);
        return nullptr;
    }
    */


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
            //LoadModel(name);
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
