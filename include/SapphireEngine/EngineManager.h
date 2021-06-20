#ifndef SAPPHIREENGINE_ENGINEMANAGER_H
#define SAPPHIREENGINE_ENGINEMANAGER_H

#include <SapphireEngine/Private/BaseInterface.h>

#include <SapphireEngine/Screen.h>

#include <SapphireEngine/InputDevice/Input.h>

#include <SapphireEngine/UnitType/Vector2.h>
#include <SapphireEngine/Application.h>
#include <SapphireEngine/InputDevice/KeyAxisDevice.h>
#include <SapphireEngine/InputDevice/MouseAxisDevice.h>

namespace SapphireEngine
{
    using namespace Private;
    using namespace InputDevice;

    namespace EngineManager
    {
        static void Init()
        {
            Application::Initialize(Vector2(800.0f, 800.0f));

            Input::AddDeivce(new KeyAxisDevice("horizontal", 0.08f, KeyCode::A, KeyCode::D));
            Input::AddDeivce(new KeyAxisDevice("vertical", 0.08f, KeyCode::W, KeyCode::S));
            Input::AddDeivce(new MouseAxisDevice("mouseX", 0.0f, MouseAxisCode::MouseX));
            Input::AddDeivce(new MouseAxisDevice("mouseY", 0.0f, MouseAxisCode::MouseY));
        }
        static void Term()
        {
            Application::Terminate();
            Input::Terminate();
        }
    };
}

#endif // !SAPPHIREENGINE_ENGINEMANAGER_H