#ifndef _SAPPHIREENGINE_MOBJECT_H
#define _SAPPHIREENGINE_MOBJECT_H

#include <CoreLib/CoreLib.h>
#include <CoreLib/Reflection.h>
#include <cstdint>
#include <string>

namespace SapphireEngine
{
    using namespace JxCoreLib;

    class MObject : public Object
    {
        CORELIB_DEF_TYPE(SapphireEngine::MObject, Object);
    public:
        MObject() {}
    public:

    };

    template<typename T>
    concept baseof_mobject = std::is_base_of<MObject, T>::value;
}

#endif // !SAPPHIREENGINE_MOBJECT_H