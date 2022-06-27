#include <Sapphire/Assets/ScriptableAsset.h>
#include <Sapphire/Resource.h>
#include <CoreLib/File.h>
#include <CoreLib.Serializer/JsonSerializer.h>

namespace Sapphire
{

    AssetObject* ScriptableAssetImporter::OnImport(const AssetImporterContext& ctx, Type* type)
    {
        const string& content = FileUtil::ReadAllText(ctx.get_assetpath());
        return static_cast<AssetObject*>( JxCoreLib::Serializer::JsonSerializer::Deserialize(content, type) );
    }
}