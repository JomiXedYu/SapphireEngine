/*
* @Moudule     : Object
* @Date        : 2021/04/17
* @Author      : JomiXedYu
* @Description : This file is part of JxCode.CoreLib : https://github.com/JomiXedYu/JxCode.CoreLib
* @StdRequired : c++20
*/

#ifndef _CORELIB_OBJECT_H
#define _CORELIB_OBJECT_H

#include <vector>
#include <memory>
#include <type_traits>
#include "UString.h"

namespace JxCoreLib
{
    template<typename T>
    using sptr = std::shared_ptr<T>;

    template<typename T>
    sptr<T> mksptr(T* t) { return sptr<T>(t); }


    class Type;

    struct GlobalIniter
    {
        GlobalIniter(void(*f)())
        {
            f();
        }
        GlobalIniter(const GlobalIniter&) = delete;
        GlobalIniter(GlobalIniter&&) = delete;
    };

    class Object
    {
    private:
        static Type* __meta_type();
        static inline struct _ObjectInit {
            _ObjectInit() {
                Object::__meta_type();
            }
        } _object_init_;
    private:
        std::vector<Object*>* managed_child_ = nullptr;
        Object* parent_ = nullptr;
    private:
        void AddManagedChild(Object* child);
        void RemoveManagedChild(Object* child);
    public:
        void SetManagedParent(Object* parent);
    public:
        virtual Type* GetType() const;
        friend class Type;
    public:
        Object() {}
        virtual ~Object();
    public:
        virtual string ToString() const;
    };

    class ManagedptrTree final
    {
    public:
        inline static Object* const Root = new Object;
        static void GCollect();
    };

    template<typename T>
    concept baseof_object_concept =
        std::is_base_of<Object, typename std::remove_pointer<T>::type>::value;

    template<typename T>
    concept baseof_object_pointer_concept =
        baseof_object_concept<T>
        && std::is_pointer<T>::value;

    template<typename T>
    concept newable_concept = requires { new T; };

    template<typename T>
    concept non_newable_concept = !requires { new T; };

}
namespace std
{
    string to_string(JxCoreLib::Object* obj);
}
#endif // !_CORELIB_OBJECT_H
