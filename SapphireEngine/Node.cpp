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
        if (this->parent_ == nullptr)
        {
            if (_parent != nullptr)
            {
                _parent->childs_.push_back(this);
            } 
        }
        else
        {
            auto it = std::find(this->parent_->childs_.begin(), this->parent_->childs_.end(), this);
            this->parent_->childs_.erase(it);

            if (_parent != nullptr)
            {
                _parent->childs_.push_back(this);
            }
        }
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

    Node::Node(string name, Node* parent, bool is_active)
        : name_(name), is_active_(is_active)
    {
        this->set_parent(parent);
    }

    Component* Node::AddComponent(Type* type)
    {
        Component* com = (Component*)type->CreateInstance();
        com->node_ = this;
        this->components_.push_back(com);
        com->SetManagedParent(this);
        com->OnInitialize();
        return com;
    }
    void Node::RemoveComponent(Type* type)
    {
        for (auto it = this->components_.begin(); it != this->components_.end(); it++)
        {
            if ((*it)->GetType() == type) {
                (*it)->set_enabled(false);
                this->components_.erase(it);
                break;
            }
        }
    }

    Component* Node::GetComponent(Type* type) const
    {
        for (auto& item : this->components_) {
            if (item->GetType() == type) {
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
    void Node::Update()
    {
        for (auto& com : this->components_)
        {
            com->SendMessage(MessageType::Update);
        }
        for (auto& item : this->childs_)
        {
            item->Update();
        }
    }
}

