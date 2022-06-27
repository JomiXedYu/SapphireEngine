#pragma once

#include <Sapphire/UnitType/Vector2.h>
#include <Sapphire/UnitType/Vector3.h>

namespace Sapphire
{
    struct Vertex
    {
        Vector3 Position;
        Vector3 Normal;
        Vector2 TexCoords;
    };
}
