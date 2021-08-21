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
    public:
        Mesh* get_mesh() { return mesh_; }
        void set_mesh(Mesh* mesh) { mesh_ = mesh; }
    public:
        void OnDraw(ShaderProgram*);
    private:
        Mesh* mesh_;
        std::vector<Material*> materials_;
    };
}