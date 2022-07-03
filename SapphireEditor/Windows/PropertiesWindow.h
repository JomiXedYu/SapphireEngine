#pragma once
#include "EditorWindow.h"

namespace SapphireEditor
{
    class PropertiesWindow : public EditorWindow
    {
        CORELIB_DEF_TYPE(PropertiesWindow, SapphireEditor::EditorWindow);
        virtual string_view GetWindowName() const override { return "Properties"; }
        virtual void OnDrawImGui() override;

    };
}