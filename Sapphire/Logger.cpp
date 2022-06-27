#include <Sapphire/Logger.h>
#include <iostream>

namespace Sapphire
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