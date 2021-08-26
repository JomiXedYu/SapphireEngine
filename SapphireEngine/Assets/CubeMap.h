#pragma once

#include<CoreLib/Reflection.h>
#include <SapphireEngine/MObject.h>


namespace SapphireEngine
{
    class CubeMap : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::CubeMap, MObject);
    public:


        void OnDraw();

        CORELIB_REFL_DECL_FIELD(top);
        string top;
        CORELIB_REFL_DECL_FIELD(left);
        string left;
        CORELIB_REFL_DECL_FIELD(front);
        string front;
        CORELIB_REFL_DECL_FIELD(right);
        string right;
        CORELIB_REFL_DECL_FIELD(back);
        string back;
        CORELIB_REFL_DECL_FIELD(bottom);
        string bottom;

        uint32_t id;
    };

}