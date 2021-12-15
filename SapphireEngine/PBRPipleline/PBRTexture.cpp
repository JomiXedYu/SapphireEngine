#include <SapphireEngine/PBRPipleline/PBRTexture.h>
#include <SapphireEngine/Resource.h>
#include <CoreLib/File.h>
#include <CoreLib.Serializer/JsonSerializer.h>

namespace SapphireEngine::PBRPiplepine
{
    using namespace JxCoreLib;
    using namespace JxCoreLib::Serializer;


    class PBRTextureTextureAsset : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::PBRPiplepine::PBRTextureTextureAsset, MObject);
    public:
        CORELIB_REFL_DECL_FIELD(Albedo);
        string Albedo;
        CORELIB_REFL_DECL_FIELD(Normal);
        string Normal;
        CORELIB_REFL_DECL_FIELD(Metallic);
        string Metallic;
        CORELIB_REFL_DECL_FIELD(Roughness);
        string Roughness;
        CORELIB_REFL_DECL_FIELD(AO);
        string AO;
    };

    AssetObject* PBRTextureImporter::OnImport(const AssetImporterContext& ctx, Type* type)
    {
        const string& content = FileUtil::ReadAllText(ctx.get_assetpath());
        auto asset = JsonSerializer::DeserializeUnique<PBRTextureTextureAsset>(content);
        
        Texture2D* tex = new Texture2D;
        auto tex_importer = GetAssetImporter(cltypeof<Texture2D>());
        const string& dir = ctx.get_directory();

        auto albedo_tex = tex_importer->OnImport(AssetImporterContext{ StringUtil::Concat(dir, "/", asset->Albedo) }, type);
        auto normal_tex = tex_importer->OnImport(AssetImporterContext{ StringUtil::Concat(dir, "/", asset->Normal) }, type);
        auto metal_tex = tex_importer->OnImport(AssetImporterContext{ StringUtil::Concat(dir, "/", asset->Metallic) }, type);
        auto roughness_tex = tex_importer->OnImport(AssetImporterContext{ StringUtil::Concat(dir, "/", asset->Roughness) }, type);
        auto ao_tex = tex_importer->OnImport(AssetImporterContext{ StringUtil::Concat(dir, "/", asset->AO) }, type);

        PBRTexture* pbrtex = new PBRTexture;
        pbrtex->albedo_ = static_cast<Texture2D*>(albedo_tex);
        pbrtex->normal_ = static_cast<Texture2D*>(normal_tex);
        pbrtex->metallic_ = static_cast<Texture2D*>(metal_tex);
        pbrtex->roughness_ = static_cast<Texture2D*>(roughness_tex);
        pbrtex->ao_ = static_cast<Texture2D*>(ao_tex);

        return pbrtex;
    }

}

