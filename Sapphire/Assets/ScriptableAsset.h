#pragma once
#include "AssetObject.h"
#include "AssetImporter.h"

namespace Sapphire
{
    class ScriptableAsset : public AssetObject
    {
        CORELIB_DEF_TYPE(Sapphire::ScriptableAsset, AssetObject);
    public:
    };

    class ScriptableAssetImporter : public AssetImporter
    {
        CORELIB_DEF_TYPE(Sapphire::ScriptableAssetImporter, AssetImporter);
        ENGINE_ASSETIMPORTER();
    public:
        virtual AssetObject* OnImport(const AssetImporterContext& ctx, Type* type) override;
        virtual Type* GetAssetType() const
        {
            return cltypeof<ScriptableAsset>();
        }
    };
}