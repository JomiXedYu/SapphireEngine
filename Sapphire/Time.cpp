#include <Sapphire/Time.h>
#include <Sapphire/Private/RenderInterface.h>

namespace Sapphire 
{
    using namespace Private;
    using namespace RenderInterface;

    uint32_t Time::FrameCount()
    {
        return GetFrameCount();
    }

    float Time::TimeCount()
    {
        return GetTime();
    }

    float Time::DeltaTime()
    {
        return GetDeltaTime();
    }

}
