#pragma once

#include <Sapphire/Math/Vector2.h>
#include <Sapphire/Math/Vector3.h>

namespace Sapphire
{
    struct Vertex
    {
        Vector3 Position;
        Vector3 Normal;
        Vector2 TexCoords;
    };
}
