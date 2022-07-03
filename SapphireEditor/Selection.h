#pragma once

#include <SapphireEditor/Editor.h>

namespace SapphireEditor
{
    class Selection
    {
    public:
        void set_selected(sptr<MObject> obj);
        sptr<MObject> get_selected();
    };
}