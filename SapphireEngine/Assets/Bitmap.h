#ifndef _SAPPHIREENGINE_ASSETS_BITMAP_H
#define _SAPPHIREENGINE_ASSETS_BITMAP_H

#include "AssetObject.h"

namespace SapphireEngine
{
    class Bitmap
    {
    public:
        int32_t get_width() const { return width_; }
        int32_t get_height() const { return height_; }
        int32_t get_channel_count() const { return channel_; }
    public:
        const uint8_t* GetNativeData() const;
    public:
        void SetData(uint8_t* data, int32_t width, int32_t height, int32_t channel_count);
    public:
        Bitmap();
        ~Bitmap();
    private:
        uint8_t* data_;
        int32_t width_;
        int32_t height_;
        int32_t channel_;
        bool is_sealed_;
    };

}


#endif // !SAPPHIREENGINE_ASSETS_BITMAP_H

