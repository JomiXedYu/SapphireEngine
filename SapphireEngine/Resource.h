#ifndef _SAPPHIREENGINE_RESOURCE_H
#define _SAPPHIREENGINE_RESOURCE_H

#include <SapphireEngine/MObject.h>
#include <CoreLib/Events.hpp>

namespace SapphireEngine
{
    class Bitmap;
    class Texture2D;
    class Node;

    namespace Resource
    {
        MObject* Load(const string& name, Type* type);

        template<baseof_mobject T>
        T* Load(const string& name) { return static_cast<T*>(Load(name, cltypeof<T>())); }

        void LoadAsync(const string& name, Type* type, Action<MObject*>* callback);

        template<baseof_mobject T>
        void LoadAsync(const string& name, Action<T*>* callback)
        {
            LoadAsync(name, cltypeof<T>(), callback);
        }
    }

}


#endif // !SAPPHIREENGINE_RESOURCE_H


