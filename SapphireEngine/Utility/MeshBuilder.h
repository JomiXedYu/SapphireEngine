#pragma once

namespace SapphireEngine::Utility
{
    class MeshBuilder
    {
    public:
        static std::array<float, 8 * 6> CreateStdLayoutPlane();
        static std::array<float, 3 * 6 * 6> CreateCube();
        static std::array<float, 8 * 6 * 6> CreateStdLayoutCube();
    };
}