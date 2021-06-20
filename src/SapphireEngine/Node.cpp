#include <SapphireEngine/Node.h>
using namespace std;

namespace SapphireEngine
{
    string Node::get_name() const
    {
        return this->name_;
    }
    void Node::set_name(const string& value)
    {
        this->name_ = value;
    }
    bool Node::get_is_active() const
    {
        return this->is_active_;
    }
    void Node::set_is_active(const bool& value)
    {
        this->is_active_ = value;
    }
    Node* Node::get_parent() const
    {
        return this->parent_;
    }
    void Node::set_parent(Node* _parent)
    {
        this->parent_ = _parent;
    }
    Transform* Node::get_transform() const
    {
        return this->transform_;
    }

    int32_t Node::get_child_count() const
    {
        return this->childs_.size();
    }

    Node::Node() : parent_(nullptr), transform_(nullptr), is_active_(false)
    {
    }

    Node::Node(string name, Node* parent, bool is_active)
        : name_(name), parent_(parent), is_active_(is_active),
        transform_(nullptr)
    {
    }

    Component* Node::AddComponent(Type* type)
    {
        Component* com = (Component*)type->get_type()->CreateInstance();
        this->components_.push_back(com);
        return com;
    }
    void Node::RemoveComponent(Type* type)
    {
        for (auto it = this->components_.begin(); it != this->components_.end(); it++)
        {
            if ((*it)->get_type() == type) {
                this->components_.erase(it);
                break;
            }
        }
    }

    Component* Node::GetComponent(Type* type) const
    {
        for (auto& item : this->components_) {
            if (item->get_type() == type) {
                return item;
            }
        }
        return nullptr;
    }
    vector<Component*> Node::GetComponents()
    {
        return this->components_;
    }
    vector<Node*> Node::GetChildren()
    {
        return this->childs_;
    }
    Node* Node::GetChild(const string& name)
    {
        for (auto& item : this->childs_) {
            if (item->name_ == name) {
                return item;
            }
        }
        return nullptr;
    }
    Node* Node::GetChildAt(int index)
    {
        return this->childs_[index];
    }
}

