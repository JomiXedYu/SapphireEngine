#include <Sapphire/Resource.h>
#include <Sapphire/Private/ResourceInterface.h>
#include <CoreLib/File.h>
#include <map>
#include <string_view>
#include <iostream>
#include <fstream>

#include <Sapphire/Node.h>

#include <Sapphire/Assets/_include.h>
#include <Sapphire/Components/MeshRenderer.h>

#include <Sapphire/Assets/AssetImporter.h>
#include <Sapphire/Assets/ScriptableAsset.h>
#include <ThirdParty/glad/glad.h>

#include <CoreLib.Serializer/JsonSerializer.h>
#include <Sapphire/Logger.h>

namespace Sapphire
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
