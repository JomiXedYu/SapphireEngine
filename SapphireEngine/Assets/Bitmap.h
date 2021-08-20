#ifndef _SAPPHIREENGINE_ASSETS_BITMAP_H
#define _SAPPHIREENGINE_ASSETS_BITMAP_H

#include <SapphireEngine/MObject.h>

namespace SapphireEngine
{
    class Bitmap : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Bitmap, MObject)
    private:
        uint8_t* data_;
        int32_t width_;
        int32_t height_;
        bool is_sealed_;
    public:
        int32_t get_width() const;
        int32_t get_height() const;
    public:
        const uint8_t* GetNativeData() const;

    public:
        void SetData(uint8_t* data, int32_t width, int32_t height);
    public:
        Bitmap();
        ~Bitmap();

    };

}


#endif // !SAPPHIREENGINE_ASSETS_BITMAP_H

