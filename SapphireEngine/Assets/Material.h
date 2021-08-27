#ifndef _SAPPHIREENGINE_ASSETS_MATERIAL_H
#define _SAPPHIREENGINE_ASSETS_MATERIAL_H

#include <CoreLib/CoreLib.h>
#include "AssetObject.h"
#include <SapphireEngine/UnitType/Vector3.h>

namespace SapphireEngine
{
    class Material : public AssetObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Material, AssetObject);
    public:
        Vector3 ambient;
        Vector3 diffuse;
        Vector3 specular;
        float shininess;
    };
}

#endif