#include <SapphireEngine/Scene.h>
#include <SapphireEngine/Node.h>

namespace SapphireEngine
{
    void Scene::AddNode(Node* node)
    {
        this->scene_nodes_.push_back(node);
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
            item->Update();
        }
    }
}

