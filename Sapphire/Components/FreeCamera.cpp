#include <Sapphire/Components/FreeCamera.h>
#include <Sapphire/InputDevice/Input.h>
#include <Sapphire/Components/Camera.h>
#include <Sapphire/Time.h>

namespace Sapphire
{
    using namespace InputDevice;

    void FreeCamera::OnUpdate()
    {
        float timedelta = Time::DeltaTime();
        float hori = Input::GetAxis("horizontal");
        float vert = Input::GetAxis("vertical");

        auto cam = Camera::Main();

        cam->get_transform()->Translate(cam->Forward() * vert * this->speed_);
        cam->get_transform()->Translate(cam->Right() * hori * this->speed_);

        if (Input::GetKey(KeyCode::E))
        {
            cam->get_transform()->Translate(Vector3::Up() * timedelta * 500 * this->speed_);
        }
        else if (Input::GetKey(KeyCode::Q))
        {
            cam->get_transform()->Translate(-Vector3::Up() * timedelta * 500 * this->speed_);
        }

        if (Input::GetKey(KeyCode::LeftAlt))
        {
            if (Input::GetMouseButton(1))
            {
                cam->get_transform()->Translate(cam->Forward() * Input::GetAxis("mouseX") * timedelta * 10);
            }
            if (Input::GetMouseButton(2))
            {
                cam->get_transform()->Translate(cam->Right() * -Input::GetAxis("mouseX") * timedelta * 10);
                cam->get_transform()->Translate(Vector3::Up() * Input::GetAxis("mouseY") * timedelta * 10);
            }
        }
        else
        {
            if (Input::GetMouseButton(1))
            {
                cam->get_transform()->Rotate({ 0, Input::GetAxis("mouseX") * timedelta * 10, 0 });
                cam->get_transform()->Rotate({ -Input::GetAxis("mouseY") * timedelta * 10 ,0 ,0 });
            }
        }
    }
}