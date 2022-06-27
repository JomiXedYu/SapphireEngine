#include <Sapphire/Screen.h>
#include <Sapphire/Logger.h>

namespace Sapphire
{
	Vector2 Screen::size = Vector2();

	Vector2 Screen::get_size()
	{
		return size;
	}

	void Screen::set_size(const Vector2& value)
	{
		Logger::Info() << "screen size: " << value.ToString() << std::endl;
		size = value;
	}

}

