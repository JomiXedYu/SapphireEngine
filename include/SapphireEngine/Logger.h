#ifndef SAPPHIREENGINE_LOGGER_H
#define SAPPHIREENGINE_LOGGER_H

#include <CoreLib/String.h>
namespace SapphireEngine
{
    using namespace JxCoreLib;

    class Logger
    {
    public:
        static void Info(const string& log);
        static void Warning(const string& log);
        static void Error(const string& log);

    };

}


#endif // !SAPPHIREENGINE_LOGGER_H