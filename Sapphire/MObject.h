#ifndef _Sapphire_MOBJECT_H
#define _Sapphire_MOBJECT_H

#include <CoreLib/Core.h>
#include <CoreLib/Reflection.h>
#include <cstdint>
#include <string>

namespace Sapphire
{
    using namespace JxCoreLib;

    template<typename T>
    using Array = std::vector<T>;

    class MObject : public Object
    {
        CORELIB_DEF_TYPE(Sapphire::MObject, Object);
    public:
        MObject() {}
    public:


	public:
		bool get_is_destoryed() const { return this->isDestoryed; }
	private:
		bool isDestoryed;
    };

    template<typename T>
    concept baseof_mobject = std::is_base_of<MObject, T>::value;
}

#endif // !Sapphire_MOBJECT_H