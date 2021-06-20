#include <SapphireEngine/Screen.h>

namespace SapphireEngine
{
	Vector2 Screen::size = Vector2();

	Vector2 Screen::get_size()
	{
		return size;
	}

	void Screen::set_size(const Vector2& value)
	{
		size = value;
	}

}

