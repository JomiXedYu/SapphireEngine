#pragma once
#include "MObject.h"

namespace Sapphire
{
    class AppInstance : public Object
    {
        CORELIB_DEF_TYPE(Sapphire::AppInstance, Object)
    public:
        virtual void OnInitialize() {}
        virtual void OnTerminate() {}
        virtual void OnRender() {}
    };
}