#ifndef _SAPPHIREENGINE_NODE_H
#define _SAPPHIREENGINE_NODE_H

#include <vector>
#include <list>
#include <type_traits>

#include <SapphireEngine/MObject.h>
#include <SapphireEngine/UnitType/Vector3.h>

namespace SapphireEngine
{
    using namespace JxCoreLib;

    class Transform;
    class Component;

    using MessageType_t = uint32_t;
    namespace MessageType
    {
        constexpr inline MessageType_t Initialize = 1;
        constexpr inline MessageType_t Destory = 2;
        constexpr inline MessageType_t Update = 3;

        constexpr inline MessageType_t Custom = 1000;
    }

    template<typename T>
    concept baseof_component_concept = std::is_base_of<Component, T>::value;

    class Transform : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Transform, MObject);
    public:
        Vector3 get_position() { return position_; }
        void set_position(const Vector3& value) { position_ = value; }
        Vector3 get_euler_angle() { return rotation_; }
        void set_euler_angle(const Vector3& value) { rotation_ = value; }
        Vector3 get_scale() { return scale_; }
        void set_scale(const Vector3& value) { scale_ = value; }
    public:

    private:
        Vector3 position_;
        Vector3 rotation_;
        Vector3 scale_;
    };

    class Node : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Node, MObject)
    public:
        string get_name() const;
        void set_name(const string& value);

        bool get_is_active() const;
        void set_is_active(const bool& value);

        Node* get_parent() const;
        void set_parent(Node* _parent);

        Transform* get_transform() const;
        int32_t get_child_count() const;

    public:
        Node(const Node& r) = delete;
        Node(Node&& r) = delete;
        Node& operator=(const Node& r) = delete;
    public:
        Node(
            string name = "Node",
            Node* parent = nullptr,
            Transform* transform = new Transform,
            bool is_active = true);

    public:
        virtual void SendMessage(MessageType_t msg);
        virtual void OnInitialize();
        virtual void OnDestory();
        virtual void OnUpdate();
    public:
        Component* AddComponent(Type* type);
        template<typename T>
        requires baseof_component_concept<T>&& newable_concept<T>
            inline T* AddComponent()
        {
            return static_cast<T*>(this->AddComponent(cltypeof<T>()));
        }

        void RemoveComponent(Type* type);

        template<baseof_component_concept T>
        inline void RemoveComponent()
        {
            this->RemoveComponent(cltypeof<T>());
        }

        Component* GetComponent(Type* type) const;

        template<baseof_component_concept T>
        inline T* GetComponent()
        {
            return static_cast<T*>(this->GetComponent(cltypeof<T>()));
        }

        std::vector<Component*> GetComponents();

        std::vector<Node*> GetChildren();

        Node* GetChild(const string& name);
        Node* GetChildAt(int index);

        void Update();

    private:
        string name_;
        bool is_active_;
        Node* parent_ = nullptr;
        Transform* transform_ = nullptr;
        std::vector<Node*> childs_;
        std::vector<Component*> components_;
    };
}


#endif