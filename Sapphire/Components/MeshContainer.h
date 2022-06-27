#pragma once
#include "Component.h"
#include <Sapphire/Assets/Mesh.h>

namespace Sapphire
{
    class MeshContainer : public Component
    {
        CORELIB_DEF_TYPE(Sapphire::MeshContainer, Component);
    public:
        void set_mesh(Mesh* value) { this->mesh_ = value; }
        Mesh* get_mesh() { return this->mesh_; }
    private:
        Mesh* mesh_;
    };
}