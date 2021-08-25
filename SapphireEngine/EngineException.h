#ifndef _SAPPHIREENGINE_ENGINEEXCEPTION_H
#define _SAPPHIREENGINE_ENGINEEXCEPTION_H

#include <CoreLib/CoreLib.h>
#include <CoreLib/CommonException.h>

namespace SapphireEngine 
{
    using namespace JxCoreLib;
    class EngineException : public ExceptionBase
    {
        CORELIB_DEF_TYPE(SapphireEngine::EngineException, ExceptionBase);
    public:
        DEF_EXCEPTION_CTOR(EngineException);
    };


}

#endif