#ifndef _Sapphire_COMPONENTS_COMPONENT_H
#define _Sapphire_COMPONENTS_COMPONENT_H

#include <Sapphire/PreLoad.h>
#include <CoreLib/CoreLib.h>
#include <Sapphire/MObject.h>
#include <Sapphire/Node.h>

namespace Sapphire
{

    namespace MessageType
    {
        constexpr inline MessageType_t Start = 11;
        constexpr inline MessageType_t Enabled = 12;
        constexpr inline MessageType_t Disabled = 13;
    }


    class Component : public MObject
    {
        friend class Node;
        CORELIB_DEF_TYPE(Sapphire::Component, MObject);
    private:
        Node* node_ = nullptr;
        bool enabled_ = true;
    public:
        bool get_enabled() const { return enabled_; }
        void set_enabled(bool value);
        Node* get_node() { return node_; }
        Transform* get_transform() { return node_->get_transform(); }
    public:
        virtual void SendMessage(MessageType_t msg);
        virtual void OnInitialize() {}
        virtual void OnUpdate() {}
        virtual void OnDestory() {}

        virtual void OnStart() {}
        virtual void OnEnabled() {}
        virtual void OnDisabled() {}

    public:
        Component() {}
    };

}


#endif // !Sapphire_COMPONENTS_COMPONENT_H