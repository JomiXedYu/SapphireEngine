#ifndef _SAPPHIREENGINE_PRIVATE_BASEINTERFACE_H
#define _SAPPHIREENGINE_PRIVATE_BASEINTERFACE_H

#include <string>
#include <cstdint>

namespace SapphireEngine::Private
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

    }
    namespace ResourceInterface
    {
        unsigned char* LoadBitmap(const std::string& name, int* out_width, int* out_height);
        void FreeBitmap(unsigned char* data);

        uint32_t LoadTexture2D(const std::string& name);
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


#endif // !SAPPHIREENGINE_PRIVATE_BASEINTERFACE_H
