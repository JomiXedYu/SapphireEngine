#ifndef _SAPPHIREENGINE_APPLICATION_H
#define _SAPPHIREENGINE_APPLICATION_H

#include <CoreLib/Events.hpp>
#include <CoreLib/String.h>

namespace SapphireEngine
{
    struct Vector2;
    using namespace JxCoreLib;

    class Application
    {
    private:
        Application() = delete;
    public:
        static void Initialize(const Vector2& size);
        static void Terminate();
        static bool IsQuit();
        static void Quit();

        static string AppPath();
        static string DataFolder();

        static Action<> QuittingEvents;
        static Function<bool> RequestQuitEvents;
    };

}

#endif // !SAPPHIREENGINE_APPLICATION_H