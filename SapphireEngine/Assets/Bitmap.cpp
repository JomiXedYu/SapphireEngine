#include <SapphireEngine/Assets/Bitmap.h>
#include <SapphireEngine/Private/BaseInterface.h>

namespace SapphireEngine 
{
    int32_t Bitmap::get_width() const
    {
        return this->width_;
    }
    int32_t Bitmap::get_height() const
    {
        return this->height_;
    }
    const uint8_t* Bitmap::GetNativeData() const
    {
        return this->data_;
    }

    void Bitmap::SetData(uint8_t* data, int32_t width, int32_t height)
    {
        if (this->is_sealed_)
        {
            return;
        }
        this->data_ = data;
        this->width_ = width;
        this->height_ = height;
        this->is_sealed_ = true;
    }

    Bitmap::Bitmap() : MObject(), data_(nullptr), width_(0), height_(0), is_sealed_(false) {}

    Bitmap::~Bitmap()
    {
        Private::ResourceInterface::FreeBitmap(this->data_);
    }

}
