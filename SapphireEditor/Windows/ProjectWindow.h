#pragma once
#include "EditorWindow.h"

namespace SapphireEditor
{
    class ProjectWindow : public EditorWindow
    {
        CORELIB_DEF_TYPE(ProjectWindow, SapphireEditor::EditorWindow);
        virtual string_view GetWindowName() const override { return "Project"; }
        virtual void OnDrawImGui() override;
    };
}