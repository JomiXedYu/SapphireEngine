#pragma once
#include "Component.h"

namespace Sapphire
{
    class ShaderProgram;

    class RendererInterface
    {
    public:
        virtual void Render() = 0;
    };

    class Renderer : public Component, public RendererInterface
    {
        CORELIB_DEF_TYPE(Sapphire::Renderer, Component);
    };
}