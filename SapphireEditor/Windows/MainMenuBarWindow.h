#pragma once
#include "EditorWindow.h"

namespace SapphireEditor
{
    class MainMenuBarWindow : public EditorWindow
    {
        CORELIB_DEF_TYPE(MainMenuBarWindow, SapphireEditor::EditorWindow);
    protected:
        virtual void OnDrawImGui() override;
    public:
        virtual string_view GetWindowName() const override { return "MainMenuBar"; }
        virtual void DrawImGui() override { this->OnDrawImGui(); }
    };
}