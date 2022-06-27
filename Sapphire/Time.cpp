#include <Sapphire/Time.h>
#include <Sapphire/Private/SystemInterface.h>

namespace Sapphire 
{
    using namespace Private;

    uint32_t Time::FrameCount()
    {
        return SystemInterface::GetFrameCount();
    }

    float Time::TimeCount()
    {
        return SystemInterface::GetTime();
    }

    float Time::DeltaTime()
    {
        return SystemInterface::GetDeltaTime();
    }

}
