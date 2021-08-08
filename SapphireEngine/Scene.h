#ifndef _SAPPHIREENGINE_SCENE_H
#define _SAPPHIREENGINE_SCENE_H

#include <vector>

#include <SapphireEngine/MObject.h>
#include <SapphireEngine/Node.h>

namespace SapphireEngine
{
    class Scene : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Scene, MObject)
    private:
        std::vector<Node*> scene_nodes_;
    public:

    public:
    };
}


#endif // !SAPPHIREENGINE_SCENE_H
