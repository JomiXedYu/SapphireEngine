#ifndef SAPPHIREENGINE_MATH_H
#define SAPPHIREENGINE_MATH_H
#include <cmath>
#include "UnitType/Vector2.h"
#include "UnitType/Vector3.h"
#include "UnitType/Vector4.h"

namespace SapphireEngine::Math
{
    const inline constexpr float pi = 3.1415926f;
    const inline constexpr float deg2rad = 0.017453292519943f;
    const inline constexpr float rad2deg = 57.295779513082320876798154814105f;

    inline float Radians(const float& degree)
    {
        return deg2rad * degree;
    }

    template<typename T>
    inline T Radians(const T& t)
    {
        T nt{ t };
        for (size_t i = 0; i < T::value_count; i++)
        {
            nt[i] = Radians(nt[i]);
        }
        return nt;
    }
    inline float Degrees(const float& rad)
    {
        return rad2deg * rad;
    }
    template<typename T>
    inline T Degrees(const T& t)
    {
        T nt{ t };
        for (size_t i = 0; i < T::value_count; i++)
        {
            nt[i] = Degrees(nt[i]);
        }
        return nt;
    }
    inline float Abs(const float& value)
    {
        return ::abs(value);
    }
    inline float Round(const float& value)
    {
        return ::round(value);
    }
}

#endif // !SAPPHIREENGINE_MATH_H