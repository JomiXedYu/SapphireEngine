#include <SapphireEngine/UnitType/Vector2.h>
#include <cmath>
#include <format>

namespace SapphireEngine 
{
	std::string Vector2::ToString()
	{
		return std::format("{{x: {}, y: {}}}", this->x, this->y);
	}
	const float* Vector2::get_value_ptr() const
	{
		return &this->x;
	}
	Vector2::Vector2() : x(0), y(0) {}
	Vector2::Vector2(float x, float y) : x(x), y(y)
	{
	}
	float Vector2::Distance(const Vector2& target1, const Vector2& target2)
	{
		float x = abs(target1.x - target2.x);
		float y = abs(target1.y - target2.y);
		float _distance = sqrt(x * x + y * y);
		return _distance;
	}
	float Vector2::Distance(const Vector2& target)
	{
		return Distance(*this, target);
	}

}

