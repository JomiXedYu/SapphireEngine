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

    Color::Color(int R, int G, int B, int A)
    {
        this->set_R(R);
        this->set_G(G);
        this->set_B(B);
        this->set_A(A);
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

    static inline float _Range(const float& value)
    {
        return ::std::max(0.0f, ::std::min(1.0f, value));
    }

    void Color::set_r(float value)
    {
        this->r_ = _Range(value);
    }

    void Color::set_g(float value)
    {
        this->g_ = _Range(value);
    }

    void Color::set_b(float value)
    {
        this->b_ = _Range(value);
    }

    void Color::set_a(float value)
    {
        this->a_ = _Range(value);
    }


    int Color::R() const
    {
        return Math::Round(this->r_ * 255.0f);
    }

    int Color::G() const
    {
        return Math::Round(this->g_ * 255.0f);
    }

    int Color::B() const
    {
        return Math::Round(this->b_ * 255.0f);
    }

    int Color::A() const
    {
        return Math::Round(this->a_ * 255.0f);
    }

    static inline float _ConvIntToFloat(const int& value)
    {
        return (float)value / 255.0f;
    }

    static inline int _Range(const int& value)
    {
        return ::std::max(0, ::std::min(255, value));
    }

    void Color::set_R(int value)
    {
        this->r_ = _ConvIntToFloat(_Range(value));
    }

    void Color::set_G(int value)
    {
        this->g_ = _ConvIntToFloat(_Range(value));
    }

    void Color::set_B(int value)
    {
        this->b_ = _ConvIntToFloat(_Range(value));
    }

    void Color::set_A(int value)
    {
        this->a_ = _ConvIntToFloat(_Range(value));
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

}
