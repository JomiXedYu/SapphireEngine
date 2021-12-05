#ifndef _SAPPHIREENGINE_ASSETS_MESH_H
#define _SAPPHIREENGINE_ASSETS_MESH_H

#include <vector>
#include <array>

#include "AssetObject.h"
#include <SapphireEngine/UnitType/Vector3.h>
#include <SapphireEngine/UnitType/Vertex.h>
#include <SapphireEngine/Assets/Material.h>

namespace SapphireEngine
{
    class Texture2D;
    class MeshRenderer;

    class Mesh : public AssetObject
    {
        friend class MeshRenderer;
        CORELIB_DEF_TYPE(SapphireEngine::Mesh, AssetObject)
    public:
        void SetData(
            const std::vector<Vertex>& vertices,
            const std::vector<unsigned int> indices,
            const std::vector<Texture2D*> textures);

    public:
        uint32_t VBO, VAO, EBO;
    public:
        std::vector<Vertex> vertices;
        std::vector<uint32_t> indices;
        std::vector<Texture2D*> textures;

    public:
        static std::array<float, 8 * 6> CreateStdLayoutPlane();
        static std::array<float, 3 * 6 * 6> CreateCube();
        static std::array<float, 8 * 6 * 6> CreateStdLayoutCube();
        static Mesh* CreateSphere(uint32_t x_seg, uint32_t y_seg);
    };


}

#endif // !SAPPHIREENGINE_ASSETS_MESH_H
