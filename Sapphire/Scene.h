#ifndef _Sapphire_SCENE_H
#define _Sapphire_SCENE_H

#include <vector>

#include <Sapphire/MObject.h>

namespace Sapphire
{
    class Node;

    class Scene : public MObject
    {
        CORELIB_DEF_TYPE(Sapphire::Scene, MObject)
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


#endif // !Sapphire_SCENE_H
