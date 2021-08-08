#ifndef SAPPHIREENGINE_ASSETS_MESH_H
#define SAPPHIREENGINE_ASSETS_MESH_H

#include <SapphireEngine/UnitType/Vector3.h>
#include <SapphireEngine/MObject.h>

namespace SapphireEngine
{
    class Mesh : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Mesh, MObject)
    private:
        Vector3* vertex;
    public:

    };
}

#endif // !SAPPHIREENGINE_ASSETS_MESH_H
