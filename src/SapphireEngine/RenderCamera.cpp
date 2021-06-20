#include <SapphireEngine/RenderCamera.h>
#include <SapphireEngine/Screen.h>
#include <SapphireEngine/Math.h>
#include <SapphireEngine/UnitType/_include.h>

namespace SapphireEngine 
{
    RenderCamera::RenderCamera()
    {
        this->fov = 0;
        this->near = 0.1f;
        this->far = 100.0f;
        this->cameraMode = CameraMode::Perspective;
    }


    Vector3 RenderCamera::Forward()
    {
        auto rotation = this->rotation.get_euler();

        float yx = cos(Math::Rad(rotation.y + 90)) * 1.0f;
        float yz = sin(Math::Rad(rotation.y + 90)) * 1.0f;
        if (rotation.x > 89.0f) rotation.x = 89.0f;
        if (rotation.x < -89.0f) rotation.x = -89.0f;
        float xy = sin(Math::Rad(rotation.x)) * 1.0f;
        return Vector3(yx, xy, yz);
    }

    Vector3 RenderCamera::Right()
    {
        return Vector3::Cross(this->Forward(), Vector3::Up());
    }

    Matrix RenderCamera::GetViewMat()
    {
        return Matrix::LookAt(
            this->position,
            this->position + this->Forward(),
            Vector3::Up()
        );
    }

    Matrix RenderCamera::GetProjectionMat()
    {
        const Vector2& size = this->size;
        Matrix ret;
        if (this->cameraMode == CameraMode::Perspective) {
            ret = Matrix::Perspective(
                Math::Rad(this->fov),
                size.x / size.y,
                this->near,
                this->far
            );
        }
        else {
            ret = Matrix::Ortho(
                0.0f,
                size.x,
                0.0f,
                size.y,
                this->near,
                this->far
            );
        }
        return ret;
    }

}

