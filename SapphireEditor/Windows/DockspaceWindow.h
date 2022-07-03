#pragma once

#include "EditorWindow.h"

namespace SapphireEditor
{
    class DockspaceWindow : public EditorWindow
    {
        CORELIB_DEF_TYPE(DockspaceWindow, SapphireEditor::EditorWindow);
    public:
        virtual string_view GetWindowName() const override { return "Dockspace"; }
        virtual void OnDrawImGui() override;

        virtual void DrawImGui() override { this->OnDrawImGui(); }
    };
}