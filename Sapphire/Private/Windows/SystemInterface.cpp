﻿#include <Sapphire/Private/SystemInterface.h>
#include <Sapphire/Logger.h>

#include <ThirdParty/glad/glad.h>
#include <ThirdParty/glfw/include/GLFW/glfw3.h>
#include <CoreLib/DebugTool.hpp>
#include <vector>
#include <iostream>

using namespace std;

namespace Sapphire::Private
{


    GLFWwindow* _glfw_window_instance;

    bool SystemInterface::InitializeWindow(std::string_view title, int width, int height)
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        _glfw_window_instance = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
        if (_glfw_window_instance == nullptr) {
            return false;
        }
        glfwMakeContextCurrent(_glfw_window_instance);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            Logger::Info() << "glad: Failed to initialize glad" << endl;
            
            return false;
        }

        return true;
    }
    void* SystemInterface::GetWindow()
    {
        return _glfw_window_instance;
    }
    void SystemInterface::TerminateWindow()
    {
        glfwTerminate();
    }

    void SystemInterface::GetResolution(int* out_width, int* out_height)
    {

    }

    void SystemInterface::SetResolution(int width, int height)
    {

    }


    static bool isQuit = false;
    static bool(*requestQuitCallBackPtr)() = nullptr;
    static void(*quitCallBackPtr)() = nullptr;

    inline static void Quit() {
        isQuit = true;
        quitCallBackPtr();
    }

    inline static void CancelQuit() {
        isQuit = false;
        glfwSetWindowShouldClose(_glfw_window_instance, 0);
    }

    void SystemInterface::PollEvents()
    {

        if (!isQuit) {
            if (glfwWindowShouldClose(_glfw_window_instance)) {
                //退出检测
                if (requestQuitCallBackPtr()) {
                    //退出
                    Quit();
                }
                else {
                    CancelQuit();
                }
            }
        }
    }


    void SystemInterface::RequestQuitEvents()
    {
        //检测是否有中断退出事件
        if (requestQuitCallBackPtr())
        {
            Quit();
        }

    }

    bool SystemInterface::GetIsQuit()
    {
        return isQuit;
    }
    void SystemInterface::SetRequestQuitCallBack(bool(*funptr)())
    {
        requestQuitCallBackPtr = funptr;
    }

    void SystemInterface::SetQuitCallBack(void(*funcptr)())
    {
        quitCallBackPtr = funcptr;
    }


}

