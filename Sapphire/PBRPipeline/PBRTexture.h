#pragma once
#include <Sapphire/Assets/AssetObject.h>
#include <Sapphire/Assets/Texture2D.h>
#include <Sapphire/Assets/AssetImporter.h>

namespace Sapphire::PBRPipeline
{
    using namespace Sapphire;

    class PBRTextureImporter;

    class PBRTexture : public AssetObject
    {
        CORELIB_DEF_TYPE(Sapphire::PBRPipeline::PBRTexture, AssetObject);
        friend class PBRTextureImporter;
    public:
        inline Texture2D* get_albedo() { return this->albedo_; }
        inline Texture2D* get_normal() { return this->normal_; }
        inline Texture2D* get_metallic() { return this->metallic_; }
        inline Texture2D* get_roughness() { return this->roughness_; }
        inline Texture2D* get_ao() { return this->ao_; }
    private:
        CORELIB_REFL_DECL_FIELD(albedo_);
        Texture2D* albedo_;

        CORELIB_REFL_DECL_FIELD(normal_);
        Texture2D* normal_;

        CORELIB_REFL_DECL_FIELD(metallic_);
        Texture2D* metallic_;

        CORELIB_REFL_DECL_FIELD(roughness_);
        Texture2D* roughness_;

        CORELIB_REFL_DECL_FIELD(ao_);
        Texture2D* ao_;
    };

    class PBRTextureImporter : public AssetImporter
    {
        CORELIB_DEF_TYPE(Sapphire::PBRPipeline::PBRTextureImporter, AssetImporter);
        ENGINE_ASSETIMPORTER();
    public:
        virtual AssetObject* OnImport(const AssetImporterContext& ctx, Type* type) override;
        virtual Type* GetAssetType() const
        {
            return cltypeof<PBRTexture>();
        }
    private:

    };
}