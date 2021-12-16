#ifndef _SAPPHIREENGINE_ENGINEMANAGER_H
#define _SAPPHIREENGINE_ENGINEMANAGER_H

#include <SapphireEngine/Private/InputInterface.h>
#include <SapphireEngine/Screen.h>
#include <SapphireEngine/InputDevice/Input.h>
#include <SapphireEngine/UnitType/Vector2.h>
#include <SapphireEngine/Application.h>
#include <SapphireEngine/InputDevice/KeyAxisDevice.h>
#include <SapphireEngine/InputDevice/MouseAxisDevice.h>

namespace SapphireEngine
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

            using namespace SapphireEngine::InputDevice;
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

#endif // !SAPPHIREENGINE_ENGINEMANAGER_H