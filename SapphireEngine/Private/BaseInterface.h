#ifndef _SAPPHIREENGINE_PRIVATE_BASEINTERFACE_H
#define _SAPPHIREENGINE_PRIVATE_BASEINTERFACE_H

#include <string>
#include <cstdint>
#include <SapphireEngine/UnitType/Color.h>

namespace SapphireEngine
{
    class Bitmap;

    namespace Private
    {
        namespace InputInterface
        {
            bool GetKey(const int& keyCode);
            bool GetMouseButton(const int& keyCode);
            void GetCursorPosition(int* out_x, int* out_y);
            void PollEvents();
        }
        namespace RenderInterface
        {
            void Clear(const Color& color);
            void EnableDepthTest();
            void DisableDepthTest();

            void LoadTexture2D(Bitmap* bitmap, uint32_t* out_id);
        }
        namespace ResourceInterface
        {
            unsigned char* LoadBitmap(const std::string& name, int* out_width, int* out_height, int* out_channel);
            void FreeBitmap(unsigned char* data);
        }
        namespace SystemInterface
        {
            bool InitializeWindow(const std::string& title, int width, int height);
            void TerminateWindow();
            void GetResolution(int* out_width, int* out_height);
            void SetResolution(int width, int height);

            double GetTime();
            float GetDeltaTime();

            uint32_t GetFrameCount();

            void PollEvents();

            void RequestQuitEvents();
            bool GetIsQuit();
            void SetRequestQuitCallBack(bool(*funptr)());
            void SetQuitCallBack(void(*funcptr)());

            void Log(const char* str);
        }
    }

}


#endif // !SAPPHIREENGINE_PRIVATE_BASEINTERFACE_H
