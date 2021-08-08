#include <SapphireEngine/Private/BaseInterface.h>
#include <ThirdParty/glfw/include/GLFW/glfw3.h>
//#include <Windows.h>

//#pragma comment(lib, "ThirdParty/glfw/libvc2019/glfw3.lib")
//#pragma comment(lib, "glfw3.lib")

namespace SapphireEngine::Private
{
    //src: SystemInterface.cpp
    extern GLFWwindow* _glfw_window_instance;

    bool InputInterface::GetKey(const int& keyCode)
    {
        return glfwGetKey(_glfw_window_instance, (int)keyCode) == GLFW_PRESS;
    }

    bool InputInterface::GetMouseButton(const int& keyCode)
    {
        return glfwGetMouseButton(_glfw_window_instance, keyCode);
    }

    void InputInterface::GetCursorPosition(int* out_x, int* out_y)
    {
        double x, y;
        glfwGetCursorPos(_glfw_window_instance, &x, &y);
        *out_x = (int)x;
        *out_y = (int)y;
        //POINT p;
        //GetCursorPos(&p);
        //*out_x = p.x;
        //*out_y = p.y;
    }

    void InputInterface::PollEvents()
    {
        glfwPollEvents();
    }


}

