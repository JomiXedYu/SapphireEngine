#pragma once
#include "Component.h"
#include <SapphireEngine/Assets/Mesh.h>

namespace SapphireEngine
{
    class MeshContainer : public Component
    {
        CORELIB_DEF_TYPE(SapphireEngine::MeshContainer, Component);
    public:
        Mesh* mesh;
    };
}