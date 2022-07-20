#ifndef _Sapphire_ASSETS_MESH_H
#define _Sapphire_ASSETS_MESH_H

#include <vector>
#include <array>

#include "AssetObject.h"
#include <Sapphire/Math/Vector3.h>
#include <Sapphire/Math/Vertex.h>
#include <Sapphire/Assets/Material.h>

namespace Sapphire
{
    class Texture2D;
    class MeshRenderer;

    class Mesh : public AssetObject
    {
        friend class MeshRenderer;
        CORELIB_DEF_TYPE(Sapphire::Mesh, AssetObject)
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

    };


}

#endif // !Sapphire_ASSETS_MESH_H
