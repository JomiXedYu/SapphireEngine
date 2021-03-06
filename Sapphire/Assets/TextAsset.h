#pragma once

#include "AssetObject.h"
#include <CoreLib/File.h>

namespace Sapphire
{
    class TextAsset : public AssetObject
    {
        CORELIB_DEF_TYPE(Sapphire::TextAsset, AssetObject);
    public:

    private:
        CORELIB_REFL_DECL_FIELD(text_);
        string ref_name_;
        string text_;
    };
}