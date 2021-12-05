#pragma once

#include <SapphireEngine/MObject.h>
#include "Component.h"

namespace SapphireEngine
{
    class FreeCamera : public Component
    {
        CORELIB_DEF_TYPE(SapphireEngine::FreeCamera, Component);
    public:
        virtual void OnUpdate() override;

    public:
        float speed_ = 0.1f;
    };
}