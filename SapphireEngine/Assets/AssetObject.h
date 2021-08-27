#pragma once

#include <SapphireEngine/MObject.h>

namespace SapphireEngine
{
    class AssetObject : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::AssetObject, MObject);
    public:
        string get_address() { return address_; }

    private:
        string address_;
    };

    template<typename T>
    concept baseof_assetobject = std::is_base_of<AssetObject, T>::value;

}