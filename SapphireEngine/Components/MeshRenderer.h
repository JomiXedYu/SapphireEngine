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
        Mesh* get_mesh() const { return this->mesh_; }
        void set_mesh(Mesh* value) { this->mesh_ = value; }
        ShaderProgram* get_program() const { return this->program_; }
        void set_program(ShaderProgram* value) { this->program_ = value; }
    public:
        void OnDraw(ShaderProgram*);
        virtual void Render() override;

        void OnUpdate() override;
    private:
        Mesh* mesh_ = nullptr;
        std::vector<Material*> materials_;
    };
}