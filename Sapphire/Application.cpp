#include "Application.h"
#include "Application.h"
#include <Sapphire/Application.h>
#include <Sapphire/Screen.h>
#include <Sapphire/Private/SystemInterface.h>
#include <Sapphire/Private/RenderInterface.h>
#include <vector>
#include <filesystem>
#include <CoreLib/UString.h>
#include <Sapphire/Logger.h>
#include <Sapphire/ImGuiImpl.h>
#include <Sapphire/InputDevice/Input.h>
#include <Sapphire/Resource.h>

namespace Sapphire 
{
    using namespace std;
    using namespace Private;
    using namespace JxCoreLib;

    static bool isQuit;

    Action<> Application::QuittingEvents;
    Function<bool> Application::RequestQuitEvents;

    static bool RequestQuit()
    {
        //请求关闭程序
        return Application::RequestQuitEvents.IsValidReturnInvoke();
    }
    static void quitting()
    {
        Logger::Info() << "application is quitting" << endl;

        //通知程序即将关闭
        Application::QuittingEvents.Invoke();
    }
    void Application::Initialize(string_view title, const Vector2& size)
    {
        Logger::Info() << "application initialize" << endl;

        Screen::set_size(size);
        SystemInterface::InitializeWindow(title, (int)Screen::get_size().x, (int)Screen::get_size().y);

        SystemInterface::SetRequestQuitCallBack(RequestQuit);
        SystemInterface::SetQuitCallBack(quitting);

        RenderInterface::SetViewport(0, 0, (int)size.x, (int)size.y);


    }

    int Application::Exec()
    {
        CurrentAppInstance->OnInitialize();
        while (!Application::IsQuit())
        {
            CurrentAppInstance->OnRender();
        }
        CurrentAppInstance->OnTerminate();
        return 0;
    }

    void Application::Terminate()
    {
        SystemInterface::TerminateWindow();
    }

    bool Application::IsQuit()
    {
        return SystemInterface::GetIsQuit();
    }

    void Application::Quit()
    {
        SystemInterface::RequestQuitEvents();
    }
    
    string Application::AppPath()
    {
        return StringUtil::StringCast(std::filesystem::current_path().generic_u8string());
    }

    string Application::DataFolder()
    {
        static string data = AppPath() + "/_data";
        return data;
    }

}


