#pragma once

#include <CoreLib/Reflection.h>
#include "AssetObject.h"
#include "ScriptableAsset.h"
#include "Texture2D.h"

namespace SapphireEngine
{
    class CubeMap : public AssetObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::CubeMap, AssetObject);
    public:
        //CORELIB_REFL_DECL_FIELD(top);
        //Texture2D* top;
        //CORELIB_REFL_DECL_FIELD(left);
        //Texture2D* left;
        //CORELIB_REFL_DECL_FIELD(front);
        //Texture2D* front;
        //CORELIB_REFL_DECL_FIELD(right);
        //Texture2D* right;
        //CORELIB_REFL_DECL_FIELD(back);
        //Texture2D* back;
        //CORELIB_REFL_DECL_FIELD(bottom);
        //Texture2D* bottom;

        uint32_t id;
    };

    class CubeMapImporter : public AssetImporter
    {
        CORELIB_DEF_TYPE(SapphireEngine::CubeMapImporter, AssetImporter);
        ENGINE_ASSETIMPORTER();
    public:
        virtual AssetObject* OnImport(const AssetImporterContext& ctx, Type* type) override;
        virtual Type* GetAssetType() const override
        {
            return cltypeof<CubeMap>();
        }
    };
    
}