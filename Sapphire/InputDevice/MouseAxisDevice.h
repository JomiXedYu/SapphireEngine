#pragma once

#include "AxisDeviceBase.h"
#include <Sapphire/Private/InputInterface.h>

namespace Sapphire::InputDevice
{
    enum class MouseAxisCode
    {
        MouseX,
        MouseY
    };

    class MouseAxisDevice : public AxisDeviceBase
    {
    private:
        MouseAxisCode code;
        int x = 0;
        int y = 0;
        int x_v = 0;
        int y_v = 0;
    public:
        MouseAxisDevice(const string& name, const float& attenuation, const MouseAxisCode& code)
            : AxisDeviceBase(name, attenuation), code(code)
        {
        }
    public:
        void PollEvents() override {
            int x, y;
            ::Sapphire::Private::InputInterface::GetCursorPosition(&x, &y);
            this->x_v = x - this->x;
            this->y_v = y - this->y;
            this->x = x;
            this->y = y;
        }
        float Value() override {
            if (this->code == MouseAxisCode::MouseX) {
                return (float)this->x_v;
            }
            else if (this->code == MouseAxisCode::MouseY) {
                return (float)this->y_v;
            }
            return 0;
        }
    };
}