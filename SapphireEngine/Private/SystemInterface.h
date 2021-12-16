#pragma once
#include <cstdint>
#include <string>
#include <string_view>

namespace SapphireEngine::Private
{
    namespace SystemInterface
    {
        bool InitializeWindow(std::string_view title, int width, int height);
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


    }
}