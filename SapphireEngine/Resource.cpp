#include <SapphireEngine/Resource.h>
#include <SapphireEngine/Private/BaseInterface.h>
#include <CoreLib/File.h>
#include <map>
#include <string_view>
#include <iostream>
#include <fstream>

#include <SapphireEngine/Node.h>

#include <SapphireEngine/Assets/_include.h>
#include <SapphireEngine/Components/MeshRenderer.h>

#include <SapphireEngine/Assets/AssetImporter.h>
#include <SapphireEngine/Assets/ScriptableAsset.h>
#include <ThirdParty/glad/glad.h>

#include <CoreLib.Serializer/JsonSerializer.h>

namespace SapphireEngine
{
    using namespace Private;
    using namespace std;

    static string read_path;
    void Resource::SetLocalPath(const string& path)
    {
        read_path = path;
    }

    const string& Resource::GetLocalPath()
    {
        return read_path;
    }

    static map<string, AssetObject*> cache;


    AssetObject* Resource::Load(string_view path, Type* type)
    {
        string filename{ path };

        if (cache[filename] != nullptr)
        {
            return cache[filename];
        }

        AssetImporter* importer = AssetImporter::GetAssetImporter(type);
        
        if (importer == nullptr)
        {
            if (type->IsSubclassOf(cltypeof<ScriptableAsset>()))
            {
                importer = AssetImporter::GetAssetImporter(cltypeof<ScriptableAsset>());
            }
        }

        auto obj = importer->OnImport(filename, type);


        cache[filename] = obj;
        return obj;


        //AssetObject* assetobj = nullptr;

        //if (type->IsSubclassOf(cltypeof<Texture2D>()))
        //{
        //    auto tex = LoadTexture2D(filename);
        //    cache[filename] = tex;
        //}
        //if (type->IsSubclassOf(cltypeof<Model>()))
        //{
        //    Model* model = new Model;
        //    String fn{ filename };
        //    cltypeof<Model>()->get_fieldinfo("ref_name_")->SetValue(model, &fn);
        //    cache[filename] = model;
        //}
        //if (type->IsSubclassOf(cltypeof<CubeMap>()))
        //{
        //    return LoadCubeMap(filename);
        //}
        //return cache[filename];
    }

    

}
