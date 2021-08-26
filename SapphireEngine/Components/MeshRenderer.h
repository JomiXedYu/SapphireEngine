#pragma once

#include <SapphireEngine/MObject.h>
#include <SapphireEngine/Components/Component.h>
#include <vector>

namespace SapphireEngine
{
    class Mesh;
    class Material;
    class ShaderProgram;

    class MeshRenderer : public Component
    {
        CORELIB_DEF_TYPE(SapphireEngine::MeshRenderer, Component)
    public:
        Mesh* get_mesh() { return mesh_; }
        void set_mesh(Mesh* mesh) { mesh_ = mesh; }
    public:
        void OnDraw(ShaderProgram*);
        void OnUpdate() override;
        MeshRenderer() {}
    private:
        Mesh* mesh_ = nullptr;
        std::vector<Material*> materials_;
    };
}