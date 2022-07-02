#pragma once
#include <Sapphire/AppInstance.h>

namespace Sapphire
{
    class EngineAppInstanceConfig : public MObject
    {

    };

    class EngineAppInstance : public AppInstance
    {
        CORELIB_DEF_TYPE(EngineAppInstance, Sapphire::AppInstance)
    public:

    public:


    protected:

    public:
        sptr<EngineAppInstanceConfig> Config;
    };
}