#ifndef _Sapphire_UNITTYPE_VECTOR3_H
#define _Sapphire_UNITTYPE_VECTOR3_H

#include <string>
#include "Vector2.h"

namespace Sapphire
{
    struct Vector3
    {
    public:
        float x;
        float y;
        float z;
    public:
        const float* get_value_ptr() const { return &this->x; }
        static constexpr int value_count = 3;
    public:
        Vector3() : x(0), y(0), z(0) {}
        Vector3(float x, float y, float z = 0.0f) : x(x), y(y), z(z) {}
        std::string ToString() const;
    public:
        float Distance(const Vector3& v) const;
        float Magnitude() const;
        Vector3 Normalize();
    public:
        static float Distance(const Vector3& l, const Vector3& r);
        static Vector3 Cross(const Vector3& l, const Vector3& r);
        static float Dot(const Vector3& l, const Vector3& r);
        static Vector3 Normalize(const Vector3& v);
    public:
        static Vector3 Up() { return Vector3{ 0.f, 1.f, 0.f }; }
        static Vector3 Right() { return Vector3{ 1.f, 0.f, 0.f }; }
        static Vector3 Forward() {
            //RIGHT HANDLE
            return Vector3(0, 0, -1);
        }
        static Vector3 Zero() { return Vector3(0.f, 0.f, 0.f); }
        static Vector3 One() { return Vector3(1.f, 1.f, 1.f); }
    public:
        float& operator[](const int& index);
        Vector3& operator +=(const Vector3& target);
        Vector3& operator -=(const Vector3& target);
        Vector3& operator *=(const float& scalar);
        Vector3& operator /=(const float& scalar);
        Vector3 operator-();
        operator Vector2() const;
    };

    inline Vector3 operator+(const Vector3& l, const Vector3& r) { return Vector3(l.x + r.x, l.y + r.y, l.z + r.z); }
    inline Vector3 operator-(const Vector3& l, const Vector3& r) { return Vector3(l.x - r.x, l.y - r.y, l.z - r.z); }
    inline Vector3 operator/(const Vector3& v3, const float& f) { return Vector3(v3.x / f, v3.y / f, v3.z / f); }
    inline Vector3 operator/(const float& f, const Vector3& v3) { return Vector3(f / v3.x, f / v3.y, f / v3.z); }
    inline Vector3 operator*(const Vector3& v3, const float& f) { return Vector3(v3.x * f, v3.y * f, v3.z * f); }
    inline Vector3 operator*(const float& f, const Vector3& v3) { return Vector3(v3.x * f, v3.y * f, v3.z * f); }
    inline Vector3 operator*(const Vector3& l, const Vector3& r) { return Vector3(l.x * r.x, l.y * r.y, l.z * r.z); }

    inline Vector3::operator Vector2() const
    {
        return Vector2(x, y);
    }

    inline float Vector3::Distance(const Vector3& l, const Vector3& r)
    {
        float x = l.x - r.x;
        float z = l.z - r.z;
        float y = l.y - r.y;
        return sqrt(x * x + y * y * z * z);
    }

    inline float Vector3::Distance(const Vector3& v) const
    {
        return Distance(*this, v);
    }

    inline float Vector3::Dot(const Vector3& l, const Vector3& r)
    {
        return l.x * r.x + l.y * r.y + l.z * r.z;
    }

    inline Vector3 Vector3::Normalize(const Vector3& target)
    {
        return target / sqrtf(Dot(target, target));
    }
    inline Vector3 Vector3::Cross(const Vector3& target1, const Vector3& target2)
    {
        return Vector3(
            target1.y * target2.z - target1.z * target2.y,
            target1.z * target2.x - target1.x * target2.z,
            target1.x * target2.y - target1.y * target2.x
        );
    }

    inline float Vector3::Magnitude() const
    {
        return sqrtf(Dot(*this, *this));
    }

    inline Vector3 Vector3::Normalize()
    {
        return Normalize(*this);
    }

    inline float& Vector3::operator[](const int& index)
    {
        return *((&this->x) + index);
    }

    inline Vector3& Vector3::operator+=(const Vector3& target)
    {
        this->x += target.x;
        this->y += target.y;
        this->z += target.z;
        return *this;
    }

    inline Vector3& Vector3::operator-=(const Vector3& target)
    {
        this->x -= target.x;
        this->y -= target.y;
        this->z -= target.z;
        return *this;
    }

    inline Vector3& Vector3::operator*=(const float& scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        return *this;
    }

    inline Vector3& Vector3::operator/=(const float& scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        return *this;
    }

    inline Vector3 Vector3::operator-()
    {
        return Vector3(-x, -y, -z);
    }

    inline std::string Vector3::ToString() const
    {
        std::string s;
        s.reserve(64);
        s.append("{x: "); s.append(std::to_string(x)); s.append(", ");
        s.append("y: "); s.append(std::to_string(y)); s.append(", ");
        s.append("z: "); s.append(std::to_string(z)); s.append("}");
        return s;
    }
}
namespace std
{
    inline string to_string(const Sapphire::Vector3& vec)
    {
        return vec.ToString();
    }
}

#endif // !Sapphire_UNITTYPE_VECTOR3_H
