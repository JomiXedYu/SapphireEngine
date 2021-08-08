#ifndef _SAPPHIREENGINE_INPUTDEVICE_KEYAXISDEVICE_H
#define _SAPPHIREENGINE_INPUTDEVICE_KEYAXISDEVICE_H

#include <SapphireEngine/Private/BaseInterface.h>
#include "KeyCode.h"
#include "AxisDeviceBase.h"

namespace SapphireEngine::InputDevice
{
    class KeyAxisDevice : public AxisDeviceBase
    {
    private:
        KeyCode positiveCode;
        KeyCode negativeCode;
        float value;
    public:
        KeyAxisDevice(const string& name, float attenuation, KeyCode positiveCode, KeyCode negativeCode)
            : AxisDeviceBase(name, attenuation),
            positiveCode(positiveCode), negativeCode(negativeCode), value(0)
        {
        }
    public:
        void PollEvents() override 
        {
            float v = 0;

            bool positivePress = Private::InputInterface::GetKey((int)this->positiveCode);
            bool negativePress = Private::InputInterface::GetKey((int)this->negativeCode);

            if (positivePress || negativePress) {
                if (positivePress) {
                    v += this->attenuation_;
                }
                if (negativePress) {
                    v -= this->attenuation_;
                }
            }
            else {
                if (value > 0) {
                    v -= this->attenuation_;
                }
                else if (value < 0) {
                    v += this->attenuation_;
                }
            }

            v = this->value + v;
            if (v == 0) {

            }
            else if (v > 1) {
                v = 1;
            }
            else if (v < -1) {
                v = -1;
            }
            else if (v > 0 && v <= this->attenuation_ - 0.01f) {
                v = 0;
            }
            else if (v < 0 && v >= -this->attenuation_ + 0.01f) {
                v = 0;
            }
            this->value = v;
        }

        float Value() override {
            return this->value;
        }
    };
}


#endif //!SAPPHIREENGINE_INPUTDEVICE_KEYAXISDEVICE_H