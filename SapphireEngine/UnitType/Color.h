#ifndef _SAPPHIREENGINE_UNITTYPE_COLOR_H
#define SAPPHIREENGINE_UNITTYPE_COLOR_H
#include <string>

namespace SapphireEngine 
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
        Color(float r, float g, float b, float a);
        Color(float r, float g, float b);
    public:
        std::string get_rgba_string() const;
        std::string get_RGBA_string() const;
    public:
        Color operator+(const Color& target);
        Color operator-(const Color& target);
        Color operator*(const Color& target);
        Color operator/(const Color& target);
    public:
        static Color White();
        static Color Black();
        static Color Red();
        static Color Green();
        static Color Blue();
        static Color Purple();
        static Color Cyan();
        static Color Yellow();
    };

}

#endif // !SAPPHIREENGINE_UNITTYPE_COLOR_H



