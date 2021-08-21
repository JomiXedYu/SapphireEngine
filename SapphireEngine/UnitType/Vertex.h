#pragma once

#include <SapphireEngine/UnitType/Vector2.h>
#include <SapphireEngine/UnitType/Vector3.h>

namespace SapphireEngine
{
    struct Vertex
    {
        Vector3 Position;
        Vector3 Normal;
        Vector2 TexCoords;
    };
}
