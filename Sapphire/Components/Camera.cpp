#include <Sapphire/Components/Camera.h>
#include <Sapphire/Math.h>

namespace Sapphire
{
    Matrix Camera::LookAtRH
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

    Vector3 Camera::Forward()
    {
        auto rotation = this->get_transform()->get_euler_angle();
        rotation.y -= 90.0f;
        float x = cos(Math::Radians(rotation.y)) * cos(Math::Radians(rotation.x));
        float y = sin(Math::Radians(rotation.x));
        float z = sin(Math::Radians(rotation.y)) * cos(Math::Radians(rotation.x));
        return Vector3::Normalize({ x,y,z });
    }

    Vector3 Camera::Right()
    {
        return Vector3::Cross(this->Forward(), Vector3::Up());
    }

    Matrix Camera::GetModelMat()
    {
        return Matrix::Translate(Matrix::One(), this->get_transform()->get_position());
    }

    Matrix Camera::GetViewMat()
    {
        auto pos = this->get_transform()->get_position();
        return Matrix::LookAt(
            pos,
            pos + this->Forward(),
            Vector3::Up()
        );
    }

    Matrix Camera::GetProjectionMat()
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