#ifndef _Sapphire_MOBJECT_H
#define _Sapphire_MOBJECT_H

#include <CoreLib/Core.h>
#include <CoreLib/Reflection.h>
#include <cstdint>
#include <string>

namespace Sapphire
{
    using namespace JxCoreLib;

    class MObject : public Object
    {
        CORELIB_DEF_TYPE(Sapphire::MObject, Object);
    public:
        MObject() {}
    public:

    };

    template<typename T>
    concept baseof_mobject = std::is_base_of<MObject, T>::value;
}

#endif // !Sapphire_MOBJECT_H