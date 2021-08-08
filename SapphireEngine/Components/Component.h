#ifndef _SAPPHIREENGINE_COMPONENTS_COMPONENT_H
#define _SAPPHIREENGINE_COMPONENTS_COMPONENT_H

#include <CoreLib/CoreLib.h>
#include <SapphireEngine/MObject.h>

namespace SapphireEngine
{
    class Node;

    class Component : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Component, MObject);
    private:
        Node* node_;
        bool enabled_;
    public:
        bool get_enabled() const { return enabled_; }
        void set_enabled(bool value) { enabled_ = value; }
        Node* get_node() { return node_; }
    protected:
        virtual void OnInitialize() {}
        virtual void OnStart() {}
        virtual void OnEnabled() {}
        virtual void OnDisabled() {}
        virtual void OnUpdate(const float& dt) {}
        virtual void OnDestory() {}
    public:
        Component() {}
        Component(Node* node);
    };

    template<typename T>
    concept baseof_component_concept = std::is_base_of<Component, T>::value;
}


#endif // !SAPPHIREENGINE_COMPONENTS_COMPONENT_H