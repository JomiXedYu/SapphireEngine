#include <SapphireEngine/Logger.h>
#include <iostream>

namespace SapphireEngine
{
    using namespace std;
    void Logger::Info(const string& log)
    {
        cout << "[INFO]" << log << endl;
    }
    void Logger::Warning(const string& log)
    {
        cout << "[WARNING]" << log << endl;
    }
    void Logger::Error(const string& log)
    {
        cout << "[ERROR]" << log << endl;
    }
}