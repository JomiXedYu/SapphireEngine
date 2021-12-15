#pragma once

#include "AssetObject.h"
#include "AssetImporter.h"

namespace SapphireEngine
{
    class Node;

    class ModelImporter;
    class Model : public AssetObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Model, AssetObject);
        friend class ModelImporter;
    public:
        Node* Instantiate() const;

    private:
        CORELIB_REFL_DECL_FIELD(ref_name_);
        string ref_name_;
    };

    class ModelImporter : public AssetImporter
    {
        CORELIB_DEF_TYPE(SapphireEngine::ModelImporter, AssetImporter);
        ENGINE_ASSETIMPORTER();
    public:
        virtual AssetObject* OnImport(const AssetImporterContext& ctx, Type* type);

        Type* GetAssetType() const override
        {
            return cltypeof<Model>();
        }
    };
}