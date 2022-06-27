#ifndef _Sapphire_RESOURCE_H
#define _Sapphire_RESOURCE_H

#include <Sapphire/Assets/AssetObject.h>
#include <functional>
#include <string_view>
#include <iostream>

namespace Sapphire
{
    class Bitmap;
    class Texture2D;
    class Node;

    namespace Resource
    {
        void SetLocalPath(const string& path);
        const string& GetLocalPath();

        //AssetObject* Load(std::istream& stream);
        AssetObject* Load(std::string_view path, Type* type);

        template<baseof_assetobject T>
        T* Load(std::string_view path)
        {
            return static_cast<T*>(Load(path, cltypeof<T>()));
        }

        inline AssetObject* LoadLocal(std::string_view name, Type* type)
        {
            return Load(StringUtil::Concat(GetLocalPath(), "/", name), type);
        }

        template<baseof_assetobject T>
        T* LoadLocal(std::string_view name)
        {
            return static_cast<T*>(LoadLocal(name, cltypeof<T>()));
        }


    }

}


#endif // !Sapphire_RESOURCE_H


