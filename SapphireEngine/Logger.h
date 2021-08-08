#ifndef _SAPPHIREENGINE_LOGGER_H
#define _SAPPHIREENGINE_LOGGER_H

#include <CoreLib/String.h>
#include <iostream>

namespace SapphireEngine
{
    using namespace JxCoreLib;

    class Logger
    {
    public:
        static void PrintInfo(const string& log);
        static void PrintWarning(const string& log);
        static void PrintError(const string& log);

        static std::ostream& Info();
        static std::ostream& Warning();
        static std::ostream& Error();
    };

}


#endif // !SAPPHIREENGINE_LOGGER_H