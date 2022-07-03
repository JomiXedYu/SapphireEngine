#include "MainMenuBarWindow.h"

namespace SapphireEditor
{
    void MainMenuBarWindow::OnDrawImGui()
    {
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Edit"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Build"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Window"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Help"))
            {
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
    }
}