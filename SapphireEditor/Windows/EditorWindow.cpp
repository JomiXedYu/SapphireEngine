#include "EditorWindow.h"
#include "EditorWindow.h"
#include "EditorWindow.h"
#include <SapphireEditor/Windows/EditorWindow.h>

namespace SapphireEditor
{
    string_view EditorWindow::GetWindowName() const
    {
        return this->GetType()->get_name();
    }

    void EditorWindow::DrawImGui()
    {
        ImGui::Begin(GetWindowName().data(), &is_opened, window_flags);
        this->OnDrawImGui();
        ImGui::End();
    }

    void EditorWindow::OnDrawImGui()
    {

    }
    void EditorWindow::Open()
    {
        if (this->is_opened) return;
        this->is_opened = true;
        this->OnOpen();
    }
    void EditorWindow::Close()
    {
        if (!this->is_opened) return;
        this->is_opened = false;
        this->OnClose();
    }
}