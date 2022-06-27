#ifndef _Sapphire_APPLICATION_H
#define _Sapphire_APPLICATION_H

#include <CoreLib/Events.hpp>
#include <string>

namespace Sapphire
{
    struct Vector2;

    class Application
    {
    private:
        Application() = delete;
    public:
        static void Initialize(const std::string& title, const Vector2& size);
        static void Terminate();
        static bool IsQuit();
        static void Quit();

        static std::string AppPath();
        static std::string DataFolder();
        
        static JxCoreLib::Action<> QuittingEvents;
        static JxCoreLib::Function<bool> RequestQuitEvents;
    };

}

#endif // !Sapphire_APPLICATION_H