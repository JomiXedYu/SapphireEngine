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

    Matrix RenderCamera::LookAtRH
    (
        Vector3 const& eye,
        Vector3 const& center,
        Vector3 const& up
    )
    {
        Vector3 const f(Vector3::Normalize(center - eye));
        Vector3 const s(Vector3::Normalize(Vector3::Cross(f, up)));
        Vector3 const u(Vector3::Cross(s, f));

        Matrix Result(1);
        Result[0][0] = s.x;
        Result[1][0] = s.y;
        Result[2][0] = s.z;
        Result[0][1] = u.x;
        Result[1][1] = u.y;
        Result[2][1] = u.z;
        Result[0][2] = -f.x;
        Result[1][2] = -f.y;
        Result[2][2] = -f.z;
        Result[3][0] = -Vector3::Dot(s, eye);
        Result[3][1] = -Vector3::Dot(u, eye);
        Result[3][2] = Vector3::Dot(f, eye);
        return Result;
    }

    Vector3 RenderCamera::Forward()
    {
        auto rotation = this->rotationEuler;

        float x = cos(Math::Radians(rotation.y)) * cos(Math::Radians(rotation.x));
        float y = sin(Math::Radians(rotation.x));
        float z = sin(Math::Radians(rotation.y)) * cos(Math::Radians(rotation.x));
        return Vector3::Normalize({ x,y,z });
        //float yx = cos(Math::Radians(rotation.y + 90)) * 1.0f;
        //float yz = sin(Math::Radians(rotation.y + 90)) * 1.0f;
        //if (rotation.x > 89.0f) rotation.x = 89.0f;
        //if (rotation.x < -89.0f) rotation.x = -89.0f;
        //float xy = sin(Math::Radians(rotation.x)) * 1.0f;
        //return Vector3(yx, xy, yz);
    }

    Vector3 RenderCamera::Right()
    {
        return Vector3::Cross(this->Forward(), Vector3::Up());
    }

    Matrix RenderCamera::GetModelMat()
    {
        return Matrix::Translate(Matrix::One(), this->position);
    }

    Matrix RenderCamera::GetViewMat()
    {

        return Matrix::LookAt(
            this->position,
            this->position + this->Forward(),
            Vector3::Up()
        );

        return Matrix::Translate(Matrix::One(), this->position)/* * this->rotation.ToMatrix4()*/;
    }

    Matrix RenderCamera::GetProjectionMat()
    {
        const Vector2& size = this->size;
        Matrix ret;
        if (this->cameraMode == CameraMode::Perspective)
        {
            ret = Matrix::Perspective(
                Math::Radians(this->fov),
                size.x / size.y,
                this->near,
                this->far
            );
        }
        else
        {
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

