#include <SapphireEngine/Private/BaseInterface.h>
#include <ThirdParty/glad/glad.h>

namespace SapphireEngine::Private
{
    namespace RenderInterface
    {
        void Clear(const Color& color)
        {
            glClearColor(color.r(), color.g(), color.b(), color.a());
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void EnableDepthTest()
        {
            glEnable(GL_DEPTH_TEST);
        }
        void DisableDepthTest()
        {
            glDisable(GL_DEPTH_TEST);
        }
    }
}