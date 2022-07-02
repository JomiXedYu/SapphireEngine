#pragma once

#include <CoreLib/Events.hpp>
#include <Sapphire/MObject.h>
#include <Sapphire/AppInstance.h>

namespace Sapphire
{
    struct Vector2;

    class Application
    {
    private:
        Application() = delete;
    public:
        static void Initialize(string_view title, const Vector2& size);
        static void Terminate();
        static bool IsQuit();
        static void Quit();

        static string AppPath();
        static string DataFolder();
        
        static JxCoreLib::Action<> QuittingEvents;
        static JxCoreLib::Function<bool> RequestQuitEvents;

        static inline sptr<AppInstance> CurrentAppInstance;
        static inline std::vector<sptr<AppInstance>> AppInstances;

        static inline sptr<AppInstance> AddAppInstanceAndSetCurrent(sptr<AppInstance> ptr)
        {
            AppInstances.push_back(ptr);
            CurrentAppInstance = ptr;
            return ptr;
        }

        static int Exec();
    };

}