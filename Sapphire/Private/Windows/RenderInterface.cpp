#include "..\RenderInterface.h"
#include "..\RenderInterface.h"
#include "..\RenderInterface.h"
#include <Sapphire/Private/RenderInterface.h>
#include <ThirdParty/glad/glad.h>
#include <Sapphire/Assets/Texture2D.h>
#include <ThirdParty/glfw/include/GLFW/glfw3.h>

namespace Sapphire::Private
{
    extern GLFWwindow* _glfw_window_instance;

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
        

        void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height)
        {
            glViewport(x, y, width, height);
        }

        void LoadTexture2D(Texture2D* tex, uint32_t* out_id)
        {
            glGenTextures(1, out_id);
            glBindTexture(GL_TEXTURE_2D, *out_id);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            auto img_type = GL_RGB;
            switch (tex->get_channel_count())
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

            glTexImage2D(GL_TEXTURE_2D, 0, img_type, tex->get_width(), tex->get_height(), 0, img_type, GL_UNSIGNED_BYTE, tex->GetNativeData());
            glGenerateMipmap(GL_TEXTURE_2D);

            glBindTexture(GL_TEXTURE_2D, 0);

        }
        void UnloadTexture2D(uint32_t id)
        {
            glDeleteTextures(1, &id);
        }

        void UnloadTexture2Ds(uint32_t id[], int32_t length)
        {
            glDeleteTextures(length, id);
        }

        static uint32_t _frameCount = 0;
        static double lastTime = 0;
        static float deltaTime = 0;

        double GetTime()
        {
            return glfwGetTime();
        }

        float GetDeltaTime()
        {
            return deltaTime;
        }

        uint32_t GetFrameCount()
        {
            return _frameCount;
        }

        void Render()
        {
            glfwSwapBuffers(_glfw_window_instance);
            _frameCount++;

            double curTime = GetTime();
            deltaTime = curTime - lastTime;
            lastTime = curTime;
        }
    }
}