#include <SapphireEngine/UnitType/Color.h>
#include <SapphireEngine/Math.h>
#include <format>

namespace SapphireEngine
{
    Color::Color() : r_(0), g_(0), b_(0), a_(0)
    {
    }

    Color::Color(float r, float g, float b, float a) : r_(r), g_(g), b_(b), a_(a)
    {
    }

    Color::Color(float r, float g, float b) : r_(r), g_(g), b_(b), a_(1.0f)
    {
    }


    std::string Color::get_rgba_string() const
    {
        return std::format("{{r: {}, g: {}, b: {}, a: {}}}", 
            this->r_, this->g_, this->b_, this->a_);
    }

    std::string Color::get_RGBA_string() const
    {
        return std::format("{{r: {}, g: {}, b: {}, a: {}}}",
            this->R(), this->G(), this->B(), this->A());
    }

#pragma region operator
    Color Color::operator+(const Color& target)
    {
        Color color;
        color.set_r(this->r_ + target.r_);
        color.set_g(this->g_ + target.g_);
        color.set_b(this->b_ + target.b_);
        color.set_a(this->a_ + target.a_);
        return color;
    }

    Color Color::operator-(const Color& target)
    {
        Color color;
        color.set_r(this->r_ - target.r_);
        color.set_g(this->g_ - target.g_);
        color.set_b(this->b_ - target.b_);
        color.set_a(this->a_ - target.a_);
        return color;
    }

    Color Color::operator*(const Color& target)
    {
        Color color;
        color.set_r(this->r_ * target.r_);
        color.set_g(this->g_ * target.g_);
        color.set_b(this->b_ * target.b_);
        color.set_a(this->a_ * target.a_);
        return color;
    }

    Color Color::operator/(const Color& target)
    {
        Color color;
        color.set_r(this->r_ / target.r_);
        color.set_g(this->g_ / target.g_);
        color.set_b(this->b_ / target.b_);
        color.set_a(this->a_ / target.a_);
        return color;
    }


#pragma endregion

#pragma region properties

    const float* Color::get_value_ptr() const
    {
        return &this->r_;
    }

    float Color::r() const
    {
        return this->r_;
    }

    float Color::g() const
    {
        return this->g_;
    }

    float Color::b() const
    {
        return this->b_;
    }

    float Color::a() const
    {
        return this->a_;
    }

    inline static float Range(const float& value)
    {
        if (value < 0.0f) {
            return 0.0f;
        }
        else if (value > 1.0f) {
            return 1.0f;
        }
        return value;
    }

    void Color::set_r(float value)
    {
        this->r_ = Range(value);
    }

    void Color::set_g(float value)
    {
        this->g_ = Range(value);
    }

    void Color::set_b(float value)
    {
        this->b_ = Range(value);
    }

    void Color::set_a(float value)
    {
        this->a_ = Range(value);
    }


    int Color::R() const
    {
        return (int)(this->r_ * 255.0f);
    }

    int Color::G() const
    {
        return (int)(this->g_ * 255.0f);
    }

    int Color::B() const
    {
        return (int)(this->b_ * 255.0f);
    }

    int Color::A() const
    {
        return (int)(this->a_ * 255.0f);
    }

    inline float ConvIntToFloat(const int& value)
    {
        return Math::Round((float)value / 255.0f);
    }

    inline static int Range(const int& value)
    {
        if (value < 0) {
            return 0;
        }
        else if (value > 255) {
            return 255;
        }
        return value;
    }

    void Color::set_R(int value)
    {
        this->r_ = ConvIntToFloat(Range(value));
    }

    void Color::set_G(int value)
    {
        this->g_ = ConvIntToFloat(Range(value));
    }

    void Color::set_B(int value)
    {
        this->b_ = ConvIntToFloat(Range(value));
    }

    void Color::set_A(int value)
    {
        this->a_ = ConvIntToFloat(Range(value));
    }

    std::string Color::get_hex24() const
    {
        return std::string();
    }

    std::string Color::get_hex32() const
    {
        return std::string();
    }
#pragma endregion

#pragma region const properties
    Color Color::White()
    {
        return Color(1.0f, 1.0f, 1.0f);
    }

    Color Color::Black()
    {
        return Color(0.0f, 0.0f, 0.0f);
    }

    Color Color::Red()
    {
        return Color(1.0f, 0.0f, 0.0f);
    }

    Color Color::Green()
    {
        return Color(0.0f, 1.0f, 0.0f);
    }
    Color Color::Blue()
    {
        return Color(0.0f, 0.0f, 1.0f);
    }
    Color Color::Purple()
    {
        return Color(1.0f, 0.0f, 1.0f);
    }
    Color Color::Cyan()
    {
        return Color(0.0f, 1.0f, 1.0f);
    }
    Color Color::Yellow()
    {
        return Color(1.0f, 1.0f, 0.0f);
    }
#pragma endregion


}
