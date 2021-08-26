#ifndef _SAPPHIREENGINE_UNITTYPE_VECTOR4_H
#define _SAPPHIREENGINE_UNITTYPE_VECTOR4_H

#include <string>
#include "Vector3.h"

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
        const float* get_value_ptr() const { return &this->x; }
        static constexpr const int value_count = 4;
    public:
        Vector4() : x(0), y(0), z(0), w(0) {}
        Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
        Vector4(const Vector3& v3, float w) : x(v3.x), y(v3.y), z(v3.z), w(w) {}
    public:
        std::string ToString();
    public:
        float& operator[](const int& index) { return *((&this->x) + index); }
        const float& operator[](const int& index) const { return *((&this->x) + index); }

        operator Vector3();
    };

    inline Vector4 operator+(const Vector4& l, const Vector4& r) { return Vector4(l.x + r.x, l.y + r.y, l.z + r.z, l.w + r.w); }
    inline Vector4 operator-(const Vector4& l, const Vector4& r) { return Vector4(l.x - r.x, l.y - r.y, l.z - r.z, l.w - r.w); }

    inline Vector4 operator*(const Vector4& vec, const float& s) { return Vector4(vec.x * s, vec.y * s, vec.z * s, vec.w * s); }
    inline Vector4 operator*(const float& s, const Vector4& vec) { return Vector4(vec.x * s, vec.y * s, vec.z * s, vec.w * s); }
    inline Vector4 operator/(const Vector4& vec, const float& s) { return Vector4(vec.x / s, vec.y / s, vec.z / s, vec.w / s); }

    inline Vector4::operator Vector3() { return Vector3(x, y, z); }

}


#endif // !SAPPHIREENGINE_UNITTYPE_VECTOR4_H