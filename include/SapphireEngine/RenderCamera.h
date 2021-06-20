#ifndef SAPPHIREENGINE_RENDERCAMERA_H
#define SAPPHIREENGINE_RENDERCAMERA_H

#include <SapphireEngine/UnitType/_include.h>

namespace SapphireEngine 
{
    enum class CameraMode {
        Perspective,
        Orthographic
    };

    struct RenderCamera {
    public:
        float fov;
        float near;
        float far;
        Vector2 size;
        CameraMode cameraMode;
        Vector3 position;
        Quaternion rotation;
        Color backgroundColor;
    public:
        RenderCamera();
    public:
        Vector3 Forward();
        Vector3 Right();
    public:
        Matrix GetViewMat();
        Matrix GetProjectionMat();
    };
}

#endif // !SAPPHIREENGINE_RENDERCAMERA_H