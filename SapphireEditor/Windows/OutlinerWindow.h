#pragma once
#include "EditorWindow.h"

namespace SapphireEditor
{
    class OutlinerWindow : public EditorWindow
    {
        CORELIB_DEF_TYPE(OutlinerWindow, SapphireEditor::EditorWindow);
        virtual string_view GetWindowName() const override { return "Outliner"; }
        virtual void OnDrawImGui() override;
    };
}