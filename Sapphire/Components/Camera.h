#pragma once

#include <Sapphire/MObject.h>
#include <Sapphire/UnitType/Color.h>
#include <Sapphire/UnitType/Matrix.h>
#include "Component.h"

namespace Sapphire
{
    enum class CameraMode
    {
        Perspective,
        Orthographic
    };

    class Camera : public Component
    {
        CORELIB_DEF_TYPE(Sapphire::Camera, Component);
    public:
        static Camera* Main() { return main; }
        static void SetMain(Camera* cam) { main = cam; }
        void SetMain() { main = this; }
    public:
        Camera() : fov(0), near(0.1f), far(100.f), cameraMode(CameraMode::Perspective)
        {
        }
    public:
        Vector3 Forward();
        Vector3 Right();
    public:
        Matrix GetModelMat();
        Matrix GetViewMat();
        Matrix GetProjectionMat();
        static Matrix LookAtRH(
            Vector3 const& eye,
            Vector3 const& center,
            Vector3 const& up);
    private:
        static Camera* main;
    public:
        float fov;
        float near;
        float far;
        Vector2 size;
        CameraMode cameraMode;
        Color backgroundColor;
    };

    inline Camera* Camera::main = nullptr;
}

