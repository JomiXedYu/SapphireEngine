#ifndef SAPPHIREENGINE_UNITTYPE_VECTOR2_H
#define SAPPHIREENGINE_UNITTYPE_VECTOR2_H

#include <string>

namespace SapphireEngine
{
    struct Vector2
    {
    public:
        float x;
        float y;
    public:
        const float* get_value_ptr() const;
        static constexpr const int value_count = 2;
    public:
        Vector2();
        Vector2(float x, float y);
        std::string ToString();
    public:
        float& operator[](const int& index);
    public:
        static float Distance(const Vector2& target1, const Vector2& target2);
        float Distance(const Vector2& target);
    };
}

#endif // !SAPPHIREENGINE_UNITTYPE_VECTOR2_H




