#pragma once
#include <SapphireEditor/Editor.h>
#include <ThirdParty/imgui/imgui.h>

namespace SapphireEditor
{
    class EditorWindow : public MObject
    {
        CORELIB_DEF_TYPE(EditorWindow, Sapphire::MObject);
    public:
        virtual string_view GetWindowName() const;
        virtual void OnDrawImGui();
    };
}