#include <SapphireEngine/Assets/Texture2D.h>
#include <SapphireEngine/Private/RenderInterface.h>
#include <SapphireEngine/Private/ResourceInterface.h>
#include <CoreLib/File.h>
#include <SapphireEngine/Resource.h>

namespace SapphireEngine
{
    Texture2D::Texture2D()
    {
    }
    Texture2D::~Texture2D()
    {
        if (this->is_sealed_)
        {
            Private::RenderInterface::UnloadTexture2D(this->id_);
        }
    }

    void Texture2D::SetData(const string& name, uint8_t* data, int32_t width, int32_t height, int32_t channel)
    {
        if (this->is_sealed_)
        {
            return;
        }
        this->name_ = name;
        this->data_ = data;
        this->width_ = width;
        this->height_ = height;
        this->channel_ = channel;
        Private::RenderInterface::LoadTexture2D(this, &this->id_);
        this->is_sealed_ = true;
    }

    const uint8_t* Texture2D::GetNativeData() const
    {
        return this->data_;
    }


    AssetObject* Texture2DImporter::OnImport(const AssetImporterContext& ctx, Type* type)
    {
        Texture2D* tex = new Texture2D;
        int32_t width, height, channel;
        uint8_t* data = Private::ResourceInterface::LoadBitmap(ctx.get_assetpath(), &width, &height, &channel);

        tex->SetData(ctx.get_filename_noext(), data, width, height, channel);

        return tex;
    }
}
