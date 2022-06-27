#ifndef _Sapphire_SCREEN_H
#define _Sapphire_SCREEN_H

#include <Sapphire/UnitType/Vector2.h>

namespace Sapphire 
{
    class Screen 
    {
    private: 
        Screen() {}
    private:
        static Vector2 size;
    public:
        static Vector2 get_size();
        static void set_size(const Sapphire::Vector2& value);
    };

}

#endif // !Sapphire_SCREEN_H