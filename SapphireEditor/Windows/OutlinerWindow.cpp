#include <SapphireEditor/Windows/OutlinerWindow.h>

namespace SapphireEditor
{
    void OutlinerWindow::OnDrawImGui()
    {
        if (ImGui::TreeNode("SceneRoot"))
        {
            if (ImGui::TreeNode("GameObject"))
            {

                ImGui::TreePop();
            }

            ImGui::TreePop();
        }
    }
}