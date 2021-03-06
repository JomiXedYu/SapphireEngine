#ifndef CORELIB_JSONSERIALIZER_H
#define CORELIB_JSONSERIALIZER_H

#include <CoreLib/CoreLib.h>
#include <CoreLib/Reflection.h>
#include <memory>

namespace JxCoreLib::Serializer
{
    class JsonSerializer
    {
    public:
        static string Serialize(Object* obj, bool isIndent = false);
    public:
        static Object* Deserialize(const string& jstr, Type* type);
        template<typename T>
        static T* Deserialize(const string& str)
        {
            return static_cast<T*>(Deserialize(str, cltypeof<T>()));
        }

        template<typename T>
        static std::unique_ptr<T> DeserializeUnique(const string& str)
        {
            return std::unique_ptr<T>{ static_cast<T*>(Deserialize(str, cltypeof<T>())) };
        }
    };
}

#endif // !CORELIB_JSONSERIALIZER_H