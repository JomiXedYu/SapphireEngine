#ifndef _SAPPHIREENGINE_LOGGER_H
#define _SAPPHIREENGINE_LOGGER_H

#include <iostream>
#include <string>

namespace SapphireEngine
{
    namespace Logger
    {
        using std::endl;
        std::ostream& Info();
        std::ostream& Warning();
        std::ostream& Error();
    };

}


#endif // !SAPPHIREENGINE_LOGGER_H