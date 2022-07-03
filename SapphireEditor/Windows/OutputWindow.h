#pragma once
#include "EditorWindow.h"

namespace SapphireEditor
{
    class OutputWindow : public EditorWindow
    {
        CORELIB_DEF_TYPE(OutputWindow, SapphireEditor::EditorWindow);
        virtual string_view GetWindowName() const override { return "Output"; }
        virtual void OnDrawImGui() override;
    };
}