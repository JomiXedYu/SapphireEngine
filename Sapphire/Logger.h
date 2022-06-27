#ifndef _Sapphire_LOGGER_H
#define _Sapphire_LOGGER_H

#include <iostream>
#include <string>

namespace Sapphire
{
    namespace Logger
    {
        using std::endl;
        std::ostream& Info();
        std::ostream& Warning();
        std::ostream& Error();
    };

}


#endif // !Sapphire_LOGGER_H