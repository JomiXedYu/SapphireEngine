#pragma once
#include "MObject.h"

namespace Sapphire
{
    class AppInstance : public Object
    {
    public:
        virtual void OnInitialize() {}
        virtual void OnTerminate() {}
        virtual void OnRender() {}
    };
}