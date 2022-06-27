#ifndef _Sapphire_ENGINEMANAGER_H
#define _Sapphire_ENGINEMANAGER_H

#include <Sapphire/Private/InputInterface.h>
#include <Sapphire/Screen.h>
#include <Sapphire/InputDevice/Input.h>
#include <Sapphire/UnitType/Vector2.h>
#include <Sapphire/Application.h>
#include <Sapphire/InputDevice/KeyAxisDevice.h>
#include <Sapphire/InputDevice/MouseAxisDevice.h>

namespace Sapphire
{
    class EngineLauncher
    {
    public:
        virtual void Initialize() = 0;
        virtual void Terminate() = 0;
    };

    class EngineDefaultLauncher : public EngineLauncher
    {
    public:
        void Initialize() override
        {
            Application::Initialize("test", Vector2(1280.0f, 720.0f));

            using namespace Sapphire::InputDevice;
            Input::AddDeivce(new KeyAxisDevice("horizontal", 0.08f, KeyCode::D, KeyCode::A));
            Input::AddDeivce(new KeyAxisDevice("vertical", 0.08f, KeyCode::W, KeyCode::S));
            Input::AddDeivce(new MouseAxisDevice("mouseX", 0.0f, MouseAxisCode::MouseX));
            Input::AddDeivce(new MouseAxisDevice("mouseY", 0.0f, MouseAxisCode::MouseY));


            
        }
        void Terminate() override
        {
            Application::Terminate();
            InputDevice::Input::Terminate();
        }
    };

}

#endif // !Sapphire_ENGINEMANAGER_H