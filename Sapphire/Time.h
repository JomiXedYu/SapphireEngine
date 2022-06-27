#ifndef _Sapphire_TIME_H
#define _Sapphire_TIME_H

#include <cstdint>

namespace Sapphire
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

#endif // !Sapphire_TIME_H


