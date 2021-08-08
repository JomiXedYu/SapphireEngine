#ifndef SAPPHIREENGINE_UNITTYPE_VECTOR4_H
#define SAPPHIREENGINE_UNITTYPE_VECTOR4_H

#include <string>

namespace SapphireEngine 
{
    struct Vector4
    {
    public:
        float x;
        float y;
        float z;
        float w;
    public:
        const float* get_value_ptr() const;
        static constexpr const int value_count = 4;
    public:
        Vector4();
        Vector4(float x, float y, float z, float w);
    public:
        std::string ToString();
    public:
        float& operator[](const int& index);
    };

    Vector4 operator+(const Vector4& vec1, const Vector4& vec2);
    Vector4 operator-(const Vector4& vec1, const Vector4& vec2);

    Vector4 operator*(const Vector4& vec, const float& s);
    Vector4 operator*(const float& s, const Vector4& vec);
    Vector4 operator/(const Vector4& vec, const float& s);
}


#endif // !SAPPHIREENGINE_UNITTYPE_VECTOR4_H