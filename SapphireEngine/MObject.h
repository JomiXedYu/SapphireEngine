#ifndef _SAPPHIREENGINE_MOBJECT_H
#define _SAPPHIREENGINE_MOBJECT_H

#include <CoreLib/CoreLib.h>
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
        virtual string ToString() const override
        {
            return base::ToString();
        }

    };
}

#endif // !SAPPHIREENGINE_MOBJECT_H