#include <SapphireEngine/Assets/Bitmap.h>
#include <SapphireEngine/Private/BaseInterface.h>

namespace SapphireEngine 
{
    int Bitmap::get_width() const
    {
        return this->width_;
    }
    int Bitmap::get_height() const
    {
        return this->height_;
    }
    const uint8_t* Bitmap::GetNativeData() const
    {
        return this->data_;
    }

    Bitmap::Bitmap() : MObject(), data_(nullptr), width_(0), height_(0) {}

    Bitmap::Bitmap(unsigned char *data, int width, int height) : MObject(),
        data_(data), width_(width), height_(height)
    {
    }

    Bitmap::~Bitmap()
    {
        Private::ResourceInterface::FreeBitmap(this->data_);
    }

}
