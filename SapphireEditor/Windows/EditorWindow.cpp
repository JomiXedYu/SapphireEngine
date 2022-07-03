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
}