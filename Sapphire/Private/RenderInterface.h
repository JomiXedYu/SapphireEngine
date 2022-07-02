#pragma once
#include <Sapphire/UnitType/Color.h>
#include <cstdint>

namespace Sapphire
{
    class Texture2D;
    namespace Private::RenderInterface
    {
        void Clear(const Color& color);
        void EnableDepthTest();
        void DisableDepthTest();

        void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height);

        void LoadTexture2D(Texture2D* tex, uint32_t* out_id);
        void UnloadTexture2D(uint32_t id);
        void UnloadTexture2Ds(uint32_t id[], int32_t length);


        double GetTime();
        float GetDeltaTime();
        uint32_t GetFrameCount();
        void Render();
    }

}