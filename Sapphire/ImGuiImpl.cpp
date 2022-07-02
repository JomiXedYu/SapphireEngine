#include "ImGuiImpl.h"
#include <Sapphire/ImGuiImpl.h>

#include <ThirdParty/imgui/imgui.h>
#include <ThirdParty/imgui/imgui_impl_glfw.h>
#include <ThirdParty/imgui/imgui_impl_opengl3.h>

#include <Sapphire/Private/SystemInterface.h>

namespace Sapphire
{
    using namespace Private;
    void ImGui_Engine_NewFrame()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }
    void ImGui_Engine_EndFrame()
    {
        //ImGui::UpdatePlatformWindows();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    void ImGui_Engine_Initialize()
    {
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiWindowFlags_MenuBar;
        //io.ConfigFlags |= ImGuiWindowFlags_NoTitleBar;
        io.ConfigFlags &= ~ImGuiConfigFlags_ViewportsEnable;
        
        io.Fonts->AddFontFromFileTTF("DroidSans.ttf", 16.0f);
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsClassic();
        ImGuiStyle& style = ImGui::GetStyle();

        ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)SystemInterface::GetWindow(), true);
        ImGui_ImplOpenGL3_Init("#version 330");
    }
    void ImGui_Engine_Terminate()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
}