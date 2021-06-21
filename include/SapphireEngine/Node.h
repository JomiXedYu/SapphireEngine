#ifndef SAPPHIREENGINE_NODE_H
#define SAPPHIREENGINE_NODE_H

#include <SapphireEngine/MObject.h>
#include <SapphireEngine/Components/Component.h>
#include <vector>
#include <list>

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

        Component* AddComponent(Type* type);
        void RemoveComponent(Type* type);

        Component* GetComponent(Type* type) const;
        std::vector<Component*> GetComponents();

        std::vector<Node*> GetChildren();

        Node* GetChild(const string& name);
        Node* GetChildAt(int index);

    };
}


#endif