#include <SapphireEngine/Components/Component.h>
#include <SapphireEngine/Node.h>

namespace SapphireEngine
{
    Component::Component(SapphireEngine::Node* node)
    {
        this->node_ = node;
    }

}