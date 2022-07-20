#include <Sapphire/Math/Quaternion.h>

#include <Sapphire/Math/Vector3.h>
#include <Sapphire/Math/Matrix.h>
#include <Sapphire/Math.h>
#include <format>

namespace Sapphire
{
    using namespace std;
    Quaternion::Quaternion() : x(0), y(0), z(0), w(0)
    {

    }

    Quaternion::Quaternion(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w)
    {
    }

    string Quaternion::ToString() const
    {
        return std::format("{{x: {}, y: {}, z: {}, w: {}}}", x, y, z, w);
    }

    inline static float clamp(const float& x, const float& min, const float& max)
    {
        return std::min(std::max(x, min), max);
    }

    inline static float roll(const Quaternion& q)
    {
        return std::atan2(2.0f * (q.x * q.y + q.w * q.z), q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z);
    }

    inline static float pitch(const Quaternion& q)
    {
        return std::atan2(2.0f * (q.y * q.z + q.w * q.x), q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z);
    }

    inline static float yaw(const Quaternion& q)
    {
        return std::asin(clamp(-2.0f * (q.x * q.z - q.w * q.y), -1.0f, 1.0f));
    }

    Vector3 Quaternion::ToEuler() const
    {
        using namespace Math;
        return Vector3{ Degrees(pitch(*this)), Degrees(yaw(*this)), Degrees(roll(*this)) };
    }

    void Quaternion::SetEuler(const Vector3& euler_angle)
    {
        Vector3 in = Math::Radians(euler_angle) * 0.5f;

        Vector3 c = Vector3{ std::cos(in.x), std::cos(in.y), std::cos(in.z) };

        Vector3 s = Vector3{ std::sin(in.x), std::sin(in.y), std::sin(in.z) };

        this->w = c.x * c.y * c.z + s.x * s.y * s.z;
        this->x = s.x * c.y * c.z - c.x * s.y * s.z;
        this->y = c.x * s.y * c.z + s.x * c.y * s.z;
        this->z = c.x * c.y * s.z - s.x * s.y * c.z;
    }

    Matrix Quaternion::ToMatrix4() const
    {
        Matrix Result = Matrix::One();
        const Quaternion& q = *this;
        float qxx(q.x * q.x);
        float qyy(q.y * q.y);
        float qzz(q.z * q.z);
        float qxz(q.x * q.z);
        float qxy(q.x * q.y);
        float qyz(q.y * q.z);
        float qwx(q.w * q.x);
        float qwy(q.w * q.y);
        float qwz(q.w * q.z);

        Result[0][0] = float(1) - float(2) * (qyy + qzz);
        Result[0][1] = float(2) * (qxy + qwz);
        Result[0][2] = float(2) * (qxz - qwy);

        Result[1][0] = float(2) * (qxy - qwz);
        Result[1][1] = float(1) - float(2) * (qxx + qzz);
        Result[1][2] = float(2) * (qyz + qwx);

        Result[2][0] = float(2) * (qxz + qwy);
        Result[2][1] = float(2) * (qyz - qwx);
        Result[2][2] = float(1) - float(2) * (qxx + qyy);
        return Result;
    }

    void Quaternion::AddEulerX(const float& value)
    {
        Vector3 euler = this->ToEuler();
        euler.x += value;
        this->SetEuler(euler);
    }

    void Quaternion::AddEulerY(const float& value)
    {
        Vector3 euler = this->ToEuler();
        euler.y += value;
        this->SetEuler(euler);
    }

    void Quaternion::AddEulerZ(const float& value)
    {
        Vector3 euler = this->ToEuler();
        euler.z += value;
        this->SetEuler(euler);
    }

}

