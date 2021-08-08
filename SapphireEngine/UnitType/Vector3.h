#ifndef _SAPPHIREENGINE_UNITTYPE_VECTOR3_H
#define _SAPPHIREENGINE_UNITTYPE_VECTOR3_H

#include <string>

namespace SapphireEngine
{
    struct Vector3
    {
    public:
        float x;
        float y;
        float z;
    public:
        const float* get_value_ptr() const;
        static constexpr const int value_count = 3;
    public:
        Vector3();
        Vector3(float x, float y, float z = 0.0f);
        std::string ToString() const;
    public:
        float Distance(const Vector3& target) const;
        float Magnitude() const;
        Vector3 Normalize();
    public:
        static float Distance(const Vector3& target1, const Vector3& target2);
        static Vector3 Cross(const Vector3& target1, const Vector3& target2);
        static float Dot(const Vector3& target1, const Vector3& target2);
        static Vector3 Normalize(const Vector3& target);
    public:
        static Vector3 Up() { return Vector3{ 0, 1, 0 }; }
        static Vector3 Right() { return Vector3{ 1, 0, 0 }; }
        static Vector3 Forward() {
            //RIGHT HANDLE
            return Vector3(0, 0, -1);
        }
        static Vector3 Zero() { return Vector3{ 0, 0, 0 }; }
    public:
        float& operator[](const int& index);
        Vector3& operator +=(const Vector3& target);
        Vector3& operator -=(const Vector3& target);
        Vector3& operator *=(const float& scalar);
        Vector3& operator /=(const float& scalar);
    };

    Vector3 operator+(const Vector3& target1, const Vector3& target2);
    Vector3 operator-(const Vector3& target1, const Vector3& target2);
    Vector3 operator/(const Vector3& v3, const float& f);
    Vector3 operator/(const float& f, const Vector3& v3);
    Vector3 operator*(const Vector3& v3, const float& f);
    Vector3 operator*(const float& f, const Vector3& v3);
    Vector3 operator*(const Vector3& l, const Vector3& r);
}


#endif // !SAPPHIREENGINE_UNITTYPE_VECTOR3_H
