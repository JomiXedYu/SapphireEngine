#ifndef SAPPHIREENGINE_INPUTDEVICE_AXISDEVICEBASE_H
#define SAPPHIREENGINE_INPUTDEVICE_AXISDEVICEBASE_H

#include <CoreLib/String.h>

namespace SapphireEngine::InputDevice
{
    using namespace JxCoreLib;
    class AxisDeviceBase
    {
    protected:
        string name_;
        float attenuation_;
    public:
        
        float get_attenuation() const { return this->attenuation_; }
        const string& get_name() const { return this->name_; }
    public:
        AxisDeviceBase(const string& name, float attenuation) 
            : name_(name), attenuation_(attenuation)
        {
        }
    public:
        virtual void PollEvents() = 0;
        virtual float Value() = 0;
    };
}
#endif // !SAPPHIREENGINE_INPUTDEVICE_AXISDEVICEBASE_H