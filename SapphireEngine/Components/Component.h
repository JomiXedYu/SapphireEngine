#ifndef _SAPPHIREENGINE_COMPONENTS_COMPONENT_H
#define _SAPPHIREENGINE_COMPONENTS_COMPONENT_H

#include <CoreLib/CoreLib.h>
#include <SapphireEngine/MObject.h>

namespace SapphireEngine
{
    class Node;
    using MessageType_t = uint32_t;

    namespace MessageType
    {
        constexpr MessageType_t Initialize = 1;
        constexpr MessageType_t Start = 2;
        constexpr MessageType_t Enabled = 3;
        constexpr MessageType_t Disabled = 4;
        constexpr MessageType_t Update = 5;
        constexpr MessageType_t Destory = 6;
    }

    class Component : public MObject
    {
        friend class Node;
        CORELIB_DEF_TYPE(SapphireEngine::Component, MObject);
    private:
        Node* node_ = nullptr;
        bool enabled_ = true;
    public:
        bool get_enabled() const { return enabled_; }
        void set_enabled(bool value)
        {
            if (enabled_ == value) return;
            enabled_ = value;
            if (value)
                this->SendMessage(MessageType::Enabled);
            else
                this->SendMessage(MessageType::Disabled);
        }
        Node* get_node() { return node_; }
    public:
        virtual void SendMessage(MessageType_t msg)
        {
            switch (msg)
            {
            case MessageType::Initialize:
                this->OnInitialize(); break;
            case MessageType::Start:
                this->OnStart(); break;
            case MessageType::Enabled:
                this->OnEnabled(); break;
            case MessageType::Disabled:
                this->OnDisabled(); break;
            case MessageType::Destory:
                this->OnDestory(); break;
            [[likely]] case MessageType::Update:
                this->OnUpdate(); break;
            }
        }
        virtual void OnInitialize() {}
        virtual void OnStart() {}
        virtual void OnEnabled() {}
        virtual void OnDisabled() {}
        virtual void OnUpdate() {}
        virtual void OnDestory() {}
    public:
        Component() {}
        Component(Node* node);
    };

    template<typename T>
    concept baseof_component_concept = std::is_base_of<Component, T>::value;
}


#endif // !SAPPHIREENGINE_COMPONENTS_COMPONENT_H