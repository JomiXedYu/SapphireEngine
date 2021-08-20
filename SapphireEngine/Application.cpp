﻿#include <SapphireEngine/Application.h>
#include <SapphireEngine/Screen.h>
#include <SapphireEngine/Private/BaseInterface.h>
#include <vector>
#include <filesystem>
#include <CoreLib/UString.h>


namespace SapphireEngine 
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
        SystemInterface::Log("Application is quitting");
        //通知程序即将关闭
        Application::QuittingEvents.Invoke();
    }
    void Application::Initialize(const std::string& title, const Vector2& size)
    {
        Screen::set_size(size);
        SystemInterface::InitializeWindow(title, (int)Screen::get_size().x, (int)Screen::get_size().y);

        SystemInterface::SetRequestQuitCallBack(RequestQuit);
        SystemInterface::SetQuitCallBack(quitting);
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


