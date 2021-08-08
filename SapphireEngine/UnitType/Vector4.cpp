#include <SapphireEngine/UnitType/Vector4.h>
#include <exception>
#include <format>
#include <CoreLib/DebugTool.h>

namespace SapphireEngine 
{
    const float* Vector4::get_value_ptr() const
    {
        return &this->x;
    }
    Vector4::Vector4() : x(0), y(0), z(0), w(0)
    {

    }
    Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
    {
    }

    std::string Vector4::ToString()
    {
        return std::format("{x: {}, y: {}, z: {}, w: {}}", this->x, this->y, this->z, this->w);
    }

    float& Vector4::operator[](const int& index)
    {
        switch (index)
        {
            case 0: return this->x;
            case 1: return this->y;
            case 2: return this->z;
            case 3: return this->w;
            default: throw std::out_of_range(DEBUG_INFO("out of range"));
        }
    }

    Vector4 operator+(const Vector4& vec1, const Vector4& vec2)
    {
        return Vector4(
            vec1.x + vec2.x,
            vec1.y + vec2.y,
            vec1.z + vec2.z,
            vec1.w + vec2.w
        );
    }

    Vector4 operator-(const Vector4& vec1, const Vector4& vec2)
    {
        return Vector4(
            vec1.x - vec2.x,
            vec1.y - vec2.y,
            vec1.z - vec2.z,
            vec1.w - vec2.w
        );
    }

    Vector4 operator*(const Vector4& vec, const float& s)
    {
        return Vector4(vec.x * s, vec.y * s, vec.z * s, vec.w * s);
    }

    Vector4 operator*(const float& s, const Vector4& vec)
    {
        return Vector4(vec.x * s, vec.y * s, vec.z * s, vec.w * s);
    }

    Vector4 operator/(const Vector4& vec, const float& s)
    {
        return Vector4(vec.x / s, vec.y / s, vec.z / s, vec.w / s);
    }


}

