#include <Sapphire/Scene.h>
#include <Sapphire/Node.h>

namespace Sapphire
{
    Node* Scene::AddNode(Node* node)
    {
        this->scene_nodes_.push_back(node);
        return node;
    }
    void Scene::RemoveNode(Node* node)
    {
        auto it = std::find(this->scene_nodes_.begin(), this->scene_nodes_.end(), node);
        this->scene_nodes_.erase(it);
    }
    void Scene::OnUpdate()
    {
        for (auto& item : this->scene_nodes_)
        {
            item->BroadcastSendMessage(MessageType::Update);
        }
    }
}

