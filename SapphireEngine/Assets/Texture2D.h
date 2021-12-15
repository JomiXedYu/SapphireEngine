#ifndef _SAPPHIREENGINE_ASSETS_TEXTURE2D_H
#define _SAPPHIREENGINE_ASSETS_TEXTURE2D_H

#include "AssetObject.h"
#include "AssetImporter.h"

namespace SapphireEngine
{
    class Texture2DImporter;

    class Texture2D : public AssetObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Texture2D, AssetObject);
        friend class Texture2DImporter;
    public:
        Texture2D();
        ~Texture2D() override;
    public:
        int32_t get_width() const { return width_; }
        int32_t get_height() const { return height_; }
        int32_t get_channel_count() const { return channel_; }

        uint32_t get_id() const { return id_; }
        const string& get_name() const { return name_; }
        const string& get_type() const { return type_; }
        void set_type(const string& type) { type_ = type; }
    public:
        void SetData(const string& name, uint8_t* data, int32_t width, int32_t height, int32_t channel);

        const uint8_t* GetNativeData() const;

    private:

        uint32_t id_ = 0;
        string name_;
        string type_;

        uint8_t* data_;

        int32_t width_;
        int32_t height_;
        int32_t channel_;
    };

    class Texture2DImporter : public AssetImporter
    {
        CORELIB_DEF_TYPE(SapphireEngine::Texture2DImporter, AssetImporter);
        ENGINE_ASSETIMPORTER();
    public:
        virtual AssetObject* OnImport(const AssetImporterContext& ctx, Type* type) override;
        virtual Type* GetAssetType() const override
        {
            return cltypeof<Texture2D>();
        }
    };
}

#endif // !_SAPPHIREENGINE_ASSETS_TEXTURE_H
