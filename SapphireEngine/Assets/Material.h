#ifndef _SAPPHIREENGINE_ASSETS_MATERIAL_H
#define _SAPPHIREENGINE_ASSETS_MATERIAL_H

#include "AssetObject.h"
#include <CoreLib/CoreLib.h>
#include <SapphireEngine/UnitType/Vector3.h>
#include <vector>
#include "Texture2D.h"
#include <SapphireEngine/ShaderProgram.h>

namespace SapphireEngine
{
    
    class Material : public AssetObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Material, AssetObject);
    //public:
    //    Vector3 ambient;
    //    Vector3 diffuse;
    //    Vector3 specular;
    //    float shininess;
    public:
        std::map<string, Texture2D*> textures;
        ShaderProgram* program;
        void Bind();
    };
}

#endif