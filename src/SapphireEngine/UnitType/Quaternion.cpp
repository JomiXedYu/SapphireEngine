#include <SapphireEngine/UnitType/Quaternion.h>

#include <cmath>
#include <SapphireEngine/UnitType/Vector3.h>

namespace SapphireEngine 
{
    Quaternion::Quaternion() : x(0), y(0), z(0), w(0)
    {
        
    }

    Quaternion::Quaternion(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w)
    {
    }

    inline static float clamp(const float& x, const float& min, const float& max) 
    {
        return std::min(std::max(x, 0.0f), 1.0f);
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

    Vector3 Quaternion::get_euler() const
    {
        return Vector3(pitch(*this), yaw(*this), roll(*this));
    }

    void Quaternion::set_euler(const Vector3& euler_angle)
    {
        Vector3 c = euler_angle * 0.5f;
        c = Vector3(std::cos(c.x), std::cos(c.y), std::cos(c.z));

        Vector3 s = euler_angle * 0.5f;
        s = Vector3(std::sin(s.x), std::sin(s.y), std::sin(s.z));

        this->w = c.x * c.y * c.z + s.x * s.y * s.z;
        this->x = s.x * c.y * c.z - c.x * s.y * s.z;
        this->y = c.x * s.y * c.z + s.x * c.y * s.z;
        this->z = c.x * c.y * s.z - s.x * s.y * c.z;
    }

    void Quaternion::add_euler_x(const float& value)
    {
        Vector3 euler = this->get_euler();
        euler.x += value;
        this->set_euler(euler);
    }

    void Quaternion::add_euler_y(const float& value)
    {
        Vector3 euler = this->get_euler();
        euler.y += value;
        this->set_euler(euler);
    }

    void Quaternion::add_euler_z(const float& value)
    {
        Vector3 euler = this->get_euler();
        euler.z += value;
        this->set_euler(euler);
    }

}

