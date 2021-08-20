#include <SapphireEngine/InputDevice/Input.h>
#include <SapphireEngine/Private/BaseInterface.h>
#include <SapphireEngine/Screen.h>
#include <SapphireEngine/UnitType/Vector2.h>

namespace SapphireEngine::InputDevice
{
    using namespace Private;
    using namespace std;

    std::vector<AxisDeviceBase*> axisDevices;

    bool Input::GetKey(KeyCode code)
    {
        return InputInterface::GetKey((int)code);
    }

    bool Input::GetKeyDown(KeyCode code)
    {
        return false;
    }

    bool Input::GetKeyUp(KeyCode code)
    {
        return false;
    }

    bool Input::GetMouseButton(const int& i)
    {
        return InputInterface::GetMouseButton(i);
    }

    float Input::GetAxis(const string& name)
    {
        for (auto item : axisDevices) {
            if (item->get_name() == name) {
                float v = item->Value();
                if (v != 0.0f) {
                    return v;
                }
            }
        }

        return 0.0f;
    }

    static bool isLockMouse = false;
    void Input::SetLockMouse(bool value)
    {
        isLockMouse = value;
    }

    bool Input::GetLockMouse()
    {
        return isLockMouse;
    }

    Vector2 Input::MousePosition()
    {
        int x, y;
        InputInterface::GetCursorPosition(&x, &y);

        //auto size = Screen::getSize();
        //if (x < 0) x = 0;
        //if (x > size.getWidth()) x = size.getWidth();
        //if (y < 0) y = 0;
        //if (y > size.getHeight()) y = size.getHeight();

        return Vector2((float)x, (float)y);
    }

    void Input::PollEvents()
    {
        InputInterface::PollEvents();
        for (auto item : axisDevices) {
            item->PollEvents();
        }
        if (isLockMouse) {

        }
    }

    void Input::AddDeivce(AxisDeviceBase* device)
    {
        axisDevices.push_back(device);
    }

    void Input::Terminate()
    {
        for (const auto& item : axisDevices)
        {
            delete item;
        }
        axisDevices.clear();
    }

}

