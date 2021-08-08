#ifndef _SAPPHIREENGINE_INPUTDEVICE_INPUT_H
#define _SAPPHIREENGINE_INPUTDEVICE_INPUT_H

#include <vector>
#include <map>
#include <string>

#include <CoreLib/String.h>
#include <SapphireEngine/UnitType/Vector2.h>

#include "AxisDeviceBase.h"
#include "KeyCode.h"

namespace SapphireEngine::InputDevice
{
    class AxisConfig;
    enum class KeyCode;

    namespace Input
    {
        bool GetKey(KeyCode code);
        bool GetKeyDown(KeyCode code);
        bool GetKeyUp(KeyCode code);
        bool GetMouseButton(const int& i);
        float GetAxis(const std::string& name);

        void SetLockMouse(bool value);
        bool GetLockMouse();

        Vector2 MousePosition();

        void AddDeivce(AxisDeviceBase* device);

        void Terminate();
        
        void PollEvents();
    };
}

#endif //!SAPPHIREENGINE_INPUTDEVICE_INPUT_H