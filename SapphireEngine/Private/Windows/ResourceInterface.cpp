#include <SapphireEngine/Private/BaseInterface.h>

#define STB_IMAGE_IMPLEMENTATION
#include <ThirdParty/stb_image.h>
#include <string>

namespace SapphireEngine::Private
{
    using namespace std;
    unsigned char* ResourceInterface::LoadBitmap(const string& name, int* out_width, int* out_height)
    {
        stbi_set_flip_vertically_on_load(true);
        int nrChannels;
        return stbi_load(name.c_str(), out_width, out_height, &nrChannels, 0);
    }

    void ResourceInterface::FreeBitmap(unsigned char* data)
    {
        stbi_image_free(data);
    }

    uint32_t ResourceInterface::LoadTexture2D(const string& name)
    {
        return 0;
    }
}

