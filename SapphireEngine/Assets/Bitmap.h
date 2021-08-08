#ifndef SAPPHIREENGINE_ASSETS_BITMAP_H
#define SAPPHIREENGINE_ASSETS_BITMAP_H

#include <SapphireEngine/MObject.h>

namespace SapphireEngine
{
    class Bitmap : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Bitmap, MObject)
    private:
        unsigned char* data_;
        int width_;
        int height_;
    public:
        int get_width() const;
        int get_height() const;
    public:
        const uint8_t* GetNativeData() const;

    private:
        Bitmap();
    public:
        Bitmap(unsigned char* data, int width, int height);
        ~Bitmap();
    };

}


#endif // !SAPPHIREENGINE_ASSETS_BITMAP_H

