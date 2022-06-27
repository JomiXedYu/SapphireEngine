#ifndef _Sapphire_ENGINEEXCEPTION_H
#define _Sapphire_ENGINEEXCEPTION_H

#include <CoreLib/CoreLib.h>
#include <CoreLib/CommonException.h>

namespace Sapphire 
{
    using namespace JxCoreLib;
    class EngineException : public ExceptionBase
    {
        CORELIB_DEF_TYPE(Sapphire::EngineException, ExceptionBase);
    public:
        DEF_EXCEPTION_CTOR(EngineException);
    };


}

#endif