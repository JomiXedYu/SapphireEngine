#ifndef _SAPPHIREENGINE_RESOURCE_H
#define _SAPPHIREENGINE_RESOURCE_H

#include <SapphireEngine/Assets/AssetObject.h>
#include <functional>

namespace SapphireEngine
{
    class Bitmap;
    class Texture2D;
    class Node;

    namespace Resource
    {
        void SetReadPath(const string& path);
        string GetReadPath();

        AssetObject* Load(const string& name, Type* type, bool is_full_path = false);

        template<baseof_assetobject T>
        T* Load(const string& name, bool is_full_path = false) { return static_cast<T*>(Load(name, cltypeof<T>(), is_full_path)); }

    }

}


#endif // !SAPPHIREENGINE_RESOURCE_H


