#ifndef _SAPPHIREENGINE_SCENE_H
#define _SAPPHIREENGINE_SCENE_H

#include <vector>

#include <SapphireEngine/MObject.h>

namespace SapphireEngine
{
    class Node;

    class Scene : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Scene, MObject)
    public:
        const std::vector<Node*>& get_nodes() const { return scene_nodes_; }
        static Scene* Current() { return current; }
    public:
        Node* AddNode(Node* node);
        void RemoveNode(Node* node);
        void OnUpdate();

        Scene* SetCurrentState() { current = this; return this; }
    private:
        std::vector<Node*> scene_nodes_;
        static Scene* current;
    };
    inline Scene* Scene::current = nullptr;
}


#endif // !SAPPHIREENGINE_SCENE_H
