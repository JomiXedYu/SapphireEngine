#ifndef SAPPHIREENGINE_MATH_H
#define SAPPHIREENGINE_MATH_H
#include <cmath>

namespace SapphireEngine::Math
{
    const inline constexpr float pi = 3.1415926f;
    const inline constexpr float deg2Rad = 0.017453292519943f;
    
    inline float Rad(const float& degree)
    {
        return deg2Rad * degree;
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