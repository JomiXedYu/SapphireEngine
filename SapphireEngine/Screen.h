#ifndef SAPPHIREENGINE_SCREEN_H
#define SAPPHIREENGINE_SCREEN_H

#include <SapphireEngine/UnitType/Vector2.h>

namespace SapphireEngine 
{
    class Screen 
    {
    private: 
        Screen() {}
    private:
        static Vector2 size;
    public:
        static Vector2 get_size();
        static void set_size(const SapphireEngine::Vector2& value);
    };

}

#endif // !SAPPHIREENGINE_SCREEN_H