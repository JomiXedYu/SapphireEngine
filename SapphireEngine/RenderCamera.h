#ifndef _SAPPHIREENGINE_RENDERCAMERA_H
#define _SAPPHIREENGINE_RENDERCAMERA_H

#include <SapphireEngine/UnitType/_include.h>

namespace SapphireEngine 
{
    enum class CameraMode 
    {
        Perspective,
        Orthographic
    };

    struct RenderCamera 
    {
    public:
        float fov;
        float near;
        float far;
        Vector2 size;
        CameraMode cameraMode;
        Vector3 position;
        Vector3 rotationEuler;
        Color backgroundColor;
    public:
        RenderCamera();
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
    };
}

#endif // !SAPPHIREENGINE_RENDERCAMERA_H