#pragma once

#include <SapphireEngine/MObject.h>
#include "Component.h"
#include "MeshContainer.h"
#include "Renderer.h"
#include <vector>

namespace SapphireEngine
{
    class Mesh;
    class Material;
    class ShaderProgram;

    class MeshRenderer : public Renderer
    {
        CORELIB_DEF_TYPE(SapphireEngine::MeshRenderer, Renderer)
    public:
        void set_material(Material* value) { this->material_ = value; }
        Material* get_material() { return this->material_; }
    public:
        virtual void OnInitialize() override;
        virtual void Render() override;

    private:
        Material* material_;
    };
}