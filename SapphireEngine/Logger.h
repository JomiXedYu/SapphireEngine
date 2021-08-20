#ifndef _SAPPHIREENGINE_LOGGER_H
#define _SAPPHIREENGINE_LOGGER_H

#include <iostream>
#include <string>

namespace SapphireEngine
{
    class Logger
    {
    public:
        static void PrintInfo(const std::string& log);
        static void PrintWarning(const std::string& log);
        static void PrintError(const std::string& log);

        static std::ostream& Info();
        static std::ostream& Warning();
        static std::ostream& Error();
    };

}


#endif // !SAPPHIREENGINE_LOGGER_H