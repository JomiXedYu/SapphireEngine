#include <SapphireEngine/Resource.h>
#include <SapphireEngine/Private/BaseInterface.h>
#include <CoreLib/File.h>
#include <map>

#include <SapphireEngine/Node.h>

#include <SapphireEngine/Assets/_include.h>
#include <SapphireEngine/Components/MeshRenderer.h>


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

    static map<string, AssetObject*> cache;

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


#pragma endregion



    AssetObject* Resource::Load(const string& name, Type* type, bool is_full_path)
    {
        string filename;
        if (is_full_path)
        {
            filename = name;
        }
        else
        {
            filename = read_path + "/" + name;
        }

        if (cache[filename] != nullptr)
        {
            return cache[filename];
        }

        if (type->IsSubclassOf(cltypeof<Texture2D>()))
        {
            LoadTexture2D(filename);
        }
        if (type->IsSubclassOf(cltypeof<Model>()))
        {
            Model* model = new Model;
            String fn{ filename };
            cltypeof<Model>()->get_fieldinfo("ref_name_")->SetValue(model, &fn);
            cache[filename] = model;
        }
        if (type->IsSubclassOf(cltypeof<CubeMap>()))
        {
            return LoadCubeMap(filename);
        }
        if (type->IsSubclassOf(cltypeof<Bitmap>()))
        {
            return LoadBitmap(filename);
        }
        return cache[filename];
    }

}
