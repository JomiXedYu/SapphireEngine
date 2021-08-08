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
    private:
        string name_;
        bool is_active_;
        Node* parent_;
        Transform* transform_;
        std::vector<Node*> childs_;
        std::vector<Component*> components_;
    public:
        string get_name() const;
        void set_name(const string& value);

        bool get_is_active() const;
        void set_is_active(const bool& value);

        Node* get_parent() const;
        void set_parent(Node* _parent);

        Transform* get_transform() const;
        int32_t get_child_count() const;

    private:
        Node();

    public:
        Node(string name, Node* parent, bool is_active);

    public:

        [[nodiscard]] Component* AddComponent(Type* type);
        template<typename T> requires baseof_component_concept<T> && newable_concept<T>
        [[nodiscard]] inline Component* AddComponent()
        {
            return this->AddComponent(typeof<T>());
        }

        void RemoveComponent(Type* type);
        template<baseof_component_concept T>
        inline void RemoveComponent()
        {
            this->RemoveComponent(typeof<T>());
        }

        Component* GetComponent(Type* type) const;
        template<baseof_component_concept T>
        inline Component* GetComponent()
        {
            return this->GetComponent(typeof<T>());
        }

        std::vector<Component*> GetComponents();

        std::vector<Node*> GetChildren();

        Node* GetChild(const string& name);
        Node* GetChildAt(int index);

    };
}


#endif