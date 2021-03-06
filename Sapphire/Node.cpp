#include <Sapphire/Node.h>
#include <Sapphire/Components/Component.h>

using namespace std;

namespace Sapphire
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

    Node::Node(string name, Node* parent, Transform* transform, bool is_active)
        : name_(name), transform_(transform), is_active_(is_active)
    {
        this->set_parent(parent);
    }

    void Node::BroadcastSendMessage(MessageType_t msg)
    {
        this->SendMessage(msg);
        for (auto& item : this->childs_)
        {
            item->BroadcastSendMessage(msg);
        }
    }

    void Node::SendMessage(MessageType_t msg)
    {
        switch (msg)
        {
        case MessageType::Initialize:
            this->OnInitialize(); break;
        case MessageType::Destory:
            this->OnDestory(); break;
        [[likely]] case MessageType::Update:
            this->OnUpdate(); break;
        }

        for (auto& item : this->components_)
        {
            item->SendMessage(msg);
        }
    }

    void Node::OnInitialize()
    {

    }

    void Node::OnDestory()
    {

    }

    void Node::OnUpdate()
    {

    }

    Component* Node::AddComponent(Type* type)
    {
        Component* com = (Component*)type->CreateInstance();
        //init
        com->node_ = this;
        this->components_.push_back(com);
        com->SetManagedParent(this); //managed_ptr
        com->SendMessage(MessageType::Initialize);
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

}

