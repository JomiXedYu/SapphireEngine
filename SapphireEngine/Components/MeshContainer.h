#pragma once
#include "Component.h"
#include <SapphireEngine/Assets/Mesh.h>

namespace SapphireEngine
{
    class MeshContainer : public Component
    {
        CORELIB_DEF_TYPE(SapphireEngine::MeshContainer, Component);
    public:
        void set_mesh(Mesh* value) { this->mesh_ = value; }
        Mesh* get_mesh() { return this->mesh_; }
    private:
        Mesh* mesh_;
    };
}