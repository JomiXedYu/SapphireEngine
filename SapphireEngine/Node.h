#ifndef _SAPPHIREENGINE_NODE_H
#define _SAPPHIREENGINE_NODE_H

#include <SapphireEngine/MObject.h>
#include <SapphireEngine/Components/Component.h>
#include <vector>
#include <list>
#include <type_traits>

namespace SapphireEngine
{
    using namespace JxCoreLib;

    class Transform;

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
        Node(string name = "Node", Node* parent = nullptr, bool is_active = true);

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