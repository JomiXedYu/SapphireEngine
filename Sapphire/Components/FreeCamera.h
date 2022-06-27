#pragma once

#include <Sapphire/MObject.h>
#include "Component.h"

namespace Sapphire
{
    class FreeCamera : public Component
    {
        CORELIB_DEF_TYPE(Sapphire::FreeCamera, Component);
    public:
        virtual void OnUpdate() override;

    public:
        float speed_ = 0.1f;
    };
}