#include <SapphireEditor/Windows/EditorWindow.h>

namespace SapphireEditor
{
    string_view EditorWindow::GetWindowName() const
    {
        return this->GetType()->get_name();
    }

    void EditorWindow::OnDrawImGui()
    {

    }
}