#include <SapphireEngine/Assets/Bitmap.h>
#include <SapphireEngine/Private/BaseInterface.h>

namespace SapphireEngine 
{
    const uint8_t* Bitmap::GetNativeData() const
    {
        return this->data_;
    }

    void Bitmap::SetData(uint8_t* data, int32_t width, int32_t height, int32_t channel_count)
    {
        if (this->is_sealed_)
        {
            return;
        }
        this->data_ = data;
        this->width_ = width;
        this->height_ = height;
        this->channel_ = channel_count;
        this->is_sealed_ = true;
    }

    Bitmap::Bitmap() : data_(nullptr), width_(0), height_(0), channel_(0), is_sealed_(false) {}

    Bitmap::~Bitmap()
    {
        Private::ResourceInterface::FreeBitmap(this->data_);
    }

}
