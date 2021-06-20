#ifndef SAPPHIREENGINE_UNITTYPE_VECTOR3_H
#define SAPPHIREENGINE_UNITTYPE_VECTOR3_H

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
    public:
        Vector3();
        Vector3(float x, float y, float z);
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
        static Vector3 Up();
        static Vector3 Right();
        static Vector3 Forward();
    public:
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
}


#endif // !SAPPHIREENGINE_UNITTYPE_VECTOR3_H
