#include <SapphireEngine/Resource.h>
#include <SapphireEngine/Private/ResourceInterface.h>
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
#include <SapphireEngine/Logger.h>

namespace SapphireEngine
{
    using namespace Private;
    using namespace std;

    static string read_path;
    void Resource::SetLocalPath(const string& path)
    {
        Logger::Info() << "Resource: local path: " << path << endl;

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
    }

    

}
