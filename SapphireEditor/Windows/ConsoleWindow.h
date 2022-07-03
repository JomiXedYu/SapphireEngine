#pragma once
#include "EditorWindow.h"

namespace SapphireEditor
{
    class ConsoleWindow : public EditorWindow
    {
        CORELIB_DEF_TYPE(ConsoleWindow, SapphireEditor::EditorWindow);
        virtual string_view GetWindowName() const override { return "Console"; }
        virtual void OnDrawImGui() override;
    public:
        ConsoleWindow();
    };
}