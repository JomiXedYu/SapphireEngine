#pragma once
#include "Component.h"

namespace SapphireEngine
{
    class ShaderProgram;

    class RendererInterface
    {
    public:
        virtual void Render() = 0;
    };

    class Renderer : public Component, public RendererInterface
    {
        CORELIB_DEF_TYPE(SapphireEngine::Renderer, Component);
    };
}