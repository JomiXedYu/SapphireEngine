#include <SapphireEngine/Logger.h>
#include <iostream>

namespace SapphireEngine
{
    using namespace std;


    ostream& Logger::Info()
    {
        cout << "[INFO]";
        return cout;
    }
    ostream& Logger::Warning()
    {
        cout << "[WARNING]";
        return cout;
    }
    ostream& Logger::Error()
    {
        cout << "[ERROR]";
        return cout;
    }
}