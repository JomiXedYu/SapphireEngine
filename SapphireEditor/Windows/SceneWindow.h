#pragma once
#include "EditorWindow.h"

namespace SapphireEditor
{
    class SceneWindow : public EditorWindow
    {
        CORELIB_DEF_TYPE(SceneWindow, SapphireEditor::EditorWindow);
    public:
        SceneWindow();
        virtual string_view GetWindowName() const override { return "Scene"; }
        virtual void OnDrawImGui() override;
    };
}