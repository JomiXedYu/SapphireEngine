#include <SapphireEngine/Time.h>
#include <SapphireEngine/Private/BaseInterface.h>

namespace SapphireEngine 
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
