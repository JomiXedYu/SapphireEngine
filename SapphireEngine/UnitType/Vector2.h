#ifndef _SAPPHIREENGINE_UNITTYPE_VECTOR2_H
#define _SAPPHIREENGINE_UNITTYPE_VECTOR2_H

#include <cmath>
#include <string>

namespace SapphireEngine
{
    struct Vector2
    {
    public:
        float x;
        float y;
    public:
        const float* get_value_ptr() const { return &this->x; }
        static constexpr const int value_count = 2;
    public:
        Vector2() : x(0), y(0) {}
        Vector2(float x, float y) : x(x), y(y) { }

    public:
        float Distance(const Vector2& target) { return Distance(*this, target); }
        /* return new normalize vector.*/
        Vector2 Normalize() { return Normalize(*this); }
        inline std::string ToString() const;
    public:
        static inline float Dot(const Vector2& a, const Vector2& b);
        static inline float Distance(const Vector2& target1, const Vector2& target2);
        static inline Vector2 Normalize(const Vector2& input);
        static inline Vector2 Reflect(const Vector2& input, const Vector2& normal);
    public:
        static inline Vector2 Zero() { return Vector2(0, 0); }
        static inline Vector2 One() { return Vector2(1, 1); }
        static inline Vector2 Up() { return Vector2(0, 1); }
        static inline Vector2 Right() { return Vector2(1, 0); }
    public:
        float& operator[](const int& index) {
            return *((&this->x) + index);
        }
        Vector2 operator-() const { return Vector2(-this->x, -this->y); }
        Vector2& operator+=(const Vector2& r) { this->x += r.x; this->y += r.y; return *this; }
        Vector2& operator+=(const float& r) { this->x += r; this->y += r; return *this; }
        Vector2& operator-=(const Vector2& r) { this->x -= r.x; this->y -= r.y; return *this; }
        Vector2& operator-=(const float& r) { this->x -= r; this->y -= r; return *this; }
        Vector2& operator*=(const float& r) { this->x *= r; this->y *= r; return *this; }
        Vector2& operator/=(const float& r) { this->x /= r; this->y /= r; return *this; }
    };

    static Vector2 operator*(const Vector2& a, const float& b) { return Vector2(a.x * b, a.y * b); }
    static Vector2 operator*(const float& a, const Vector2& b) { return Vector2(a * b.x, a * b.y); }
    static Vector2 operator/(const Vector2& a, const float& b) { return Vector2(a.x / b, a.y / b); }
    static Vector2 operator/(const float& a, const Vector2& b) { return Vector2(a / b.x, a / b.y); }
    static Vector2 operator+(const Vector2& a, const float& b) { return Vector2(a.x + b, a.y + b); }
    static Vector2 operator+(const float& a, const Vector2& b) { return Vector2(a + b.x, a + b.y); }
    static Vector2 operator+(const Vector2& a, const Vector2& b) { return Vector2(a.x + b.x, a.y + b.y); }
    static Vector2 operator-(const Vector2& a, const float& b) { return Vector2(a.x - b, a.y - b); }
    static Vector2 operator-(const float& a, const Vector2& b) { return Vector2(a - b.x, a - b.y); }
    static Vector2 operator-(const Vector2& a, const Vector2& b) { return Vector2(a.x - b.x, a.y - b.y); }

    std::string Vector2::ToString() const
    {
        std::string s;
        s.reserve(64);
        s.append("{x: ");
        s.append(std::to_string(this->x));
        s.append(", y: ");
        s.append(std::to_string(this->y));
        s.append("}");
        return s;
    }

    float Vector2::Dot(const Vector2& a, const Vector2& b)
    {
        return a.x * b.x + a.y * b.y;
    }
    float Vector2::Distance(const Vector2& target1, const Vector2& target2)
    {
        float x = abs(target1.x - target2.x);
        float y = abs(target1.y - target2.y);
        return sqrt(x * x + y * y);
    }
    Vector2 Vector2::Normalize(const Vector2& input)
    {
        return input / sqrt(Dot(input, input));
    }
    Vector2 Vector2::Reflect(const Vector2& input, const Vector2& normal)
    {
        return -input + 2.0f * Dot(Normalize(input), normal) * normal;
    }

}
namespace std
{
    inline string to_string(const SapphireEngine::Vector2& vec)
    {
        return vec.ToString();
    }
}

#endif // !SAPPHIREENGINE_UNITTYPE_VECTOR2_H




