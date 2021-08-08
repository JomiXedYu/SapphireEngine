#ifndef _SAPPHIREENGINE_TIME_H
#define _SAPPHIREENGINE_TIME_H

#include <cstdint>

namespace SapphireEngine
{
    class Time
    {
    private:
        Time() = delete;
    public:
        static uint32_t FrameCount();
        static float TimeCount();
        static float DeltaTime();
    };

}

#endif // !SAPPHIREENGINE_TIME_H


