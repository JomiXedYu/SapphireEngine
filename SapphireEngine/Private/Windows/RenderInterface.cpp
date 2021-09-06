#include <SapphireEngine/Private/BaseInterface.h>
#include <ThirdParty/glad/glad.h>
#include <SapphireEngine/Assets/Bitmap.h>

namespace SapphireEngine::Private
{
    namespace RenderInterface
    {
        void Clear(const Color& color)
        {
            glClearColor(color.r(), color.g(), color.b(), color.a());
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void EnableDepthTest()
        {
            glEnable(GL_DEPTH_TEST);
        }
        void DisableDepthTest()
        {
            glDisable(GL_DEPTH_TEST);
        }

        void LoadTexture2D(Bitmap* bitmap, uint32_t* out_id)
        {
            glGenTextures(1, out_id);
            glBindTexture(GL_TEXTURE_2D, *out_id);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            auto img_type = GL_RGB;
            switch (bitmap->get_channel_count())
            {
            case 3:
                img_type = GL_RGB;
                break;
            case 4:
                img_type = GL_RGBA;
                break;
            case 1:
                img_type = GL_RED;
                break;
            default:
                break;
            }

            glTexImage2D(GL_TEXTURE_2D, 0, img_type, bitmap->get_width(), bitmap->get_height(), 0, img_type, GL_UNSIGNED_BYTE, bitmap->GetNativeData());
            glGenerateMipmap(GL_TEXTURE_2D);

            glBindTexture(GL_TEXTURE_2D, 0);

        }

    }
}