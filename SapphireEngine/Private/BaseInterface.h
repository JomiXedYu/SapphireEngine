#ifndef _SAPPHIREENGINE_PRIVATE_BASEINTERFACE_H
#define SAPPHIREENGINE_PRIVATE_BASEINTERFACE_H

#include <CoreLib/String.h>
namespace SapphireEngine::Private
{
    using namespace JxCoreLib;

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
        using namespace JxCoreLib;
        unsigned char* LoadBitmap(const string& name, int* out_width, int* out_height);
        void FreeBitmap(unsigned char* data);
    }
    namespace SystemInterface
    {
        bool InitializeWindow(int width, int height);
        void TerminateWindow();
        void GetResolution(int* out_width, int* out_height);
        void SetResolution(int width, int height);

        float GetTime();
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
