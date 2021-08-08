#ifndef _SAPPHIREENGINE_INPUTDEVICE_AXISDEVICEBASE_H
#define _SAPPHIREENGINE_INPUTDEVICE_AXISDEVICEBASE_H

#include <string>

namespace SapphireEngine::InputDevice
{
    class AxisDeviceBase
    {
    protected:
        std::string name_;
        float attenuation_;
    public:
        
        float get_attenuation() const { return this->attenuation_; }
        const std::string& get_name() const { return this->name_; }
    public:
        AxisDeviceBase(const std::string& name, float attenuation)
            : name_(name), attenuation_(attenuation)
        {
        }
    public:
        virtual void PollEvents() = 0;
        virtual float Value() = 0;
    };
}
#endif // !SAPPHIREENGINE_INPUTDEVICE_AXISDEVICEBASE_H