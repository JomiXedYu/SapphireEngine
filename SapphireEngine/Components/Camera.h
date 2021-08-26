#pragma once

#include <SapphireEngine/MObject.h>
#include "Component.h"

namespace SapphireEngine
{
    class Camera : public Component
    {
        CORELIB_DEF_TYPE(SapphireEngine::Camera, Component);
    public:
        static Camera* Main() { return main; }
        static void SetMain(Camera* cam) { main = cam; }

    private:
        static Camera* main;
    };

    inline Camera* Camera::main = nullptr;
}

