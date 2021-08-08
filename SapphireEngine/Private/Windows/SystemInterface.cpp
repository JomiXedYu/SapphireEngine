#include <SapphireEngine/Private/BaseInterface.h>

#include <ThirdParty/glfw/include/GLFW/glfw3.h>

#include <vector>
#include <iostream>

//#pragma comment(lib, "ThirdParty/glfw/libvc2019/glfw3.lib")
//#pragma comment(lib, "glfw3.lib")

using namespace std;

namespace SapphireEngine::Private
{
    GLFWwindow* _glfw_window_instance;
    bool SystemInterface::InitializeWindow(int width, int height)
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        _glfw_window_instance = glfwCreateWindow(width, height, "TestOpenGL", nullptr, nullptr);
        if (_glfw_window_instance == nullptr) {
            return false;
        }
        glfwMakeContextCurrent(_glfw_window_instance);

        return true;
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
    float SystemInterface::GetTime()
    {
        return (float)glfwGetTime();
    }

    static uint32_t _frameCount = 0;
    uint32_t SystemInterface::GetFrameCount()
    {
        return _frameCount;
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
        if (isQuit) return;

        glfwSwapBuffers(_glfw_window_instance);
        _frameCount++;

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
        if (requestQuitCallBackPtr()) {
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

    void SystemInterface::Log(const char* str)
    {
        cout << "[SYSTEM]: " << str << endl;
    }

}

