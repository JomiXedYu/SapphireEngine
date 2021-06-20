#include <SapphireEngine/UnitType/Vector3.h>
#include <cmath>
#include <format>

namespace SapphireEngine 
{
    const float* Vector3::get_value_ptr() const
    {
        return &this->x;
    }
    Vector3::Vector3() : x(0), y(0), z(0)
    {
    }

    Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
    {
    }

    std::string Vector3::ToString() const
    {
        return std::format("{{x: {}, y: {}, z: {}}}", this->x, this->y, this->z);
    }

    float Vector3::Distance(const Vector3& target1, const Vector3& target2)
    {
        float x = target1.x - target2.x;
        float z = target1.z - target2.z;
        float y = target1.y - target2.y;
        float dis = sqrt(x * x + y * y * z * z);
        return dis;
    }

    Vector3 Vector3::Cross(const Vector3& target1, const Vector3& target2)
    {
        return Vector3(
            target1.y * target2.z - target1.z * target2.y,
            target1.z * target2.x - target1.x * target2.z,
            target1.x * target2.y - target1.y * target2.x
        );
    }

    float Vector3::Dot(const Vector3& target1, const Vector3& target2)
    {
        return target1.x * target2.x + target1.y * target2.y + target1.z * target2.z;
    }

    //每个分量除以向量长度得到单位向量
    Vector3 Vector3::Normalize(const Vector3& target)
    {
        return target / sqrtf(Dot(target, target));
    }

    float Vector3::Distance(const Vector3& target) const
    {
        return Distance(*this, target);
    }

    float Vector3::Magnitude() const
    {
        return sqrtf(Dot(*this, *this));
    }

    Vector3 Vector3::Normalize()
    {
        return Normalize(*this);
    }

    Vector3 Vector3::Up()
    {
        return Vector3(0, 1, 0);
    }

    Vector3 Vector3::Right()
    {
        //RIGHT HANDLE
        return Vector3(-1, 0, 0);
    }

    Vector3 Vector3::Forward()
    {
        return Vector3(0, 0, 1);
    }

    Vector3& Vector3::operator+=(const Vector3& target)
    {
        this->x += target.x;
        this->y += target.y;
        this->z += target.z;
        return *this;
    }

    Vector3& Vector3::operator-=(const Vector3& target)
    {
        this->x -= target.x;
        this->y -= target.y;
        this->z -= target.z;
        return *this;
    }

    Vector3& Vector3::operator*=(const float& scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        return *this;
    }

    Vector3& Vector3::operator/=(const float& scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        return *this;
    }

    Vector3 operator+(const Vector3& target1, const Vector3& target2)
    {
        return Vector3(target1.x + target2.x, target1.y + target2.y, target1.z + target2.z);
    }

    Vector3 operator-(const Vector3& target1, const Vector3& target2)
    {
        return Vector3(target1.x - target2.x, target1.y - target2.y, target1.z - target2.z);
    }

    Vector3 operator/(const Vector3& v3, const float& f)
    {
        return Vector3(v3.x / f, v3.y / f, v3.z / f);
    }

    Vector3 operator/(const float& f, const Vector3& v3)
    {
        return Vector3(f / v3.x, f / v3.y, f / v3.z);
    }

    Vector3 operator*(const Vector3& v3, const float& f)
    {
        return Vector3(v3.x * f, v3.y * f, v3.z * f);
    }

    Vector3 operator*(const float& f, const Vector3& v3)
    {
        return Vector3(v3.x * f, v3.y * f, v3.z * f);
    }

}
