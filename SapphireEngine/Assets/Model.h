#pragma once

#include "AssetObject.h"

namespace SapphireEngine
{
    class Node;

    class Model : public AssetObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Model, AssetObject);
    public:
        Node* Instantiate() const;

    private:
        CORELIB_REFL_DECL_FIELD(ref_name_);
        string ref_name_;
    };
}