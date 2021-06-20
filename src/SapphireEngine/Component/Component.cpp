#include <SapphireEngine/Components/Component.h>
#include <SapphireEngine/Node.h>

namespace SapphireEngine
{
    Component::Component(SapphireEngine::Node* node)
        : MObject(), enabled_(false), node_(node)
    {

    }

}