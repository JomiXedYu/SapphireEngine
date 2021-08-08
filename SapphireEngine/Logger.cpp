#include <SapphireEngine/Logger.h>
#include <iostream>

namespace SapphireEngine
{
    using namespace std;
    void Logger::PrintInfo(const string& log)
    {
        cout << "[INFO]" << log << endl;
    }
    void Logger::PrintWarning(const string& log)
    {
        cout << "[WARNING]" << log << endl;
    }
    void Logger::PrintError(const string& log)
    {
        cout << "[ERROR]" << log << endl;
    }

    ostream& Logger::Info()
    {
        cout << endl << "[INFO]";
        return cout;
    }
    ostream& Logger::Warning()
    {
        cout << endl << "[WARNING]";
        return cout;
    }
    ostream& Logger::Error()
    {
        cout << endl << "[ERROR]";
        return cout;
    }
}