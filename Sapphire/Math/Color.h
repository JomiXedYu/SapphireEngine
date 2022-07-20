#ifndef _Sapphire_UNITTYPE_COLOR_H
#define _Sapphire_UNITTYPE_COLOR_H
#include <string>

namespace Sapphire
{
    struct Color
    {
    private:
        float r_, g_, b_, a_;
    public:
        const float* get_value_ptr() const;
        float r() const;
        float g() const;
        float b() const;
        float a() const;
        void set_r(float value);
        void set_g(float value);
        void set_b(float value);
        void set_a(float value);
        int R() const;
        int G() const;
        int B() const;
        int A() const;
        void set_R(int value);
        void set_G(int value);
        void set_B(int value);
        void set_A(int value);
    public:
        std::string get_hex24() const;
        std::string get_hex32() const;
    public:
        Color();
        Color(float r, float g, float b, float a = 1.0f);
        Color(int R, int G, int B, int A = 255);
    public:
        std::string get_rgba_string() const;
        std::string get_RGBA_string() const;
    public:
        Color operator+(const Color& target);
        Color operator-(const Color& target);
        Color operator*(const Color& target);
        Color operator/(const Color& target);
    public:
        static Color White() { return Color(1.0f, 1.0f, 1.0f); }
        static Color Black() { return Color(0.0f, 0.0f, 0.0f); }
        static Color Red() { return Color(1.0f, 0.0f, 0.0f); }
        static Color Green() { return Color(0.0f, 1.0f, 0.0f); }
        static Color Blue() { return Color(0.0f, 0.0f, 1.0f); }
        static Color Purple() { return Color(1.0f, 0.0f, 1.0f); }
        static Color Cyan() { return Color(0.0f, 1.0f, 1.0f); }
        static Color Yellow() { return Color(1.0f, 1.0f, 0.0f); }
        static Color Gray() { return Color(42, 42, 42); }
        static Color DeepGray() { return Color(26, 26, 26); }
    };

}

#endif // !Sapphire_UNITTYPE_COLOR_H



