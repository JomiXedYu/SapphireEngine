#pragma once

#include <Sapphire/MObject.h>

namespace Sapphire
{
    class AssetObject : public MObject
    {
        CORELIB_DEF_TYPE(Sapphire::AssetObject, MObject);
    public:
        const string& get_address() { return address_; }
    public:

    private:
        CORELIB_REFL_DECL_FIELD(address_);
        string address_;
    protected:
        bool is_sealed_ = false;
    };

    template<typename T>
    concept baseof_assetobject = std::is_base_of<AssetObject, T>::value;

}