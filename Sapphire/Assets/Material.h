#ifndef _Sapphire_ASSETS_MATERIAL_H
#define _Sapphire_ASSETS_MATERIAL_H

#include "AssetObject.h"
#include <CoreLib/CoreLib.h>
#include <Sapphire/UnitType/Vector3.h>
#include <vector>
#include "Texture2D.h"
#include <Sapphire/ShaderProgram.h>

namespace Sapphire
{
    
    class Material : public AssetObject
    {
        CORELIB_DEF_TYPE(Sapphire::Material, AssetObject);
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