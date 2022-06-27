#ifndef _Sapphire_PRIVATE_BASEINTERFACE_H
#define _Sapphire_PRIVATE_BASEINTERFACE_H

#include <string>
#include <string_view>
#include <cstdint>


namespace Sapphire
{
    class Bitmap;
    class Texture2D;

    namespace Private::ResourceInterface
    {
        unsigned char* LoadBitmap(std::string_view name, int* out_width, int* out_height, int* out_channel);
        void FreeBitmap(unsigned char* data);

    }

}


#endif // !Sapphire_PRIVATE_BASEINTERFACE_H
