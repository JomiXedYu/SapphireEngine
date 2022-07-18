#pragma once
#include <SapphireEditor/Editor.h>
#include <ThirdParty/imgui/imgui.h>

namespace SapphireEditor
{
    class EditorWindow : public MObject
    {
        CORELIB_DEF_TYPE(EditorWindow, SapphireEditor::MObject);
    public:
        virtual string_view GetWindowName() const;
        virtual void DrawImGui();
    protected:
        virtual void OnDrawImGui();
        virtual void OnOpen() {}
        virtual void OnClose() {}
    public:
        bool get_is_opened() const { return is_opened; }
        void Open();
        void Close();
    protected:
        bool is_opened = false;
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_None;
    };
}