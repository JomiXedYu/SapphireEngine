#include <SapphireEngine/Private/BaseInterface.h>

#define STB_IMAGE_IMPLEMENTATION
#include <ThirdParty/stb_image.h>
#include <string>

namespace SapphireEngine::Private
{
    using namespace std;
    unsigned char* ResourceInterface::LoadBitmap(const string& name, int* out_width, int* out_height, int* out_channel)
    {
        //stbi_set_flip_vertically_on_load(true);
        return stbi_load(name.c_str(), out_width, out_height, out_channel, 0);
    }

    void ResourceInterface::FreeBitmap(unsigned char* data)
    {
        stbi_image_free(data);
    }

}

