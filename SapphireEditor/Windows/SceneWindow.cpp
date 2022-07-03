#include <SapphireEditor/Windows/SceneWindow.h>
#include <glad/glad.h>
#include <glfw/include/GLFW/glfw3.h>

extern void pbr_render();
namespace SapphireEditor
{
    static uint32_t fbo;
    static uint32_t tex;
    static uint32_t rbo;

    SceneWindow::SceneWindow()
    {
        glGenFramebuffers(1, &fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);

        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        //glGenRenderbuffers(1, &rbo);
        //glBindRenderbuffer(GL_RENDERBUFFER, rbo);
        //glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 800, 600);
        //glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

        this->window_flags = ImGuiWindowFlags_MenuBar;
        
    }
    void SceneWindow::OnDrawImGui()
    {

        if (ImGui::BeginMenuBar())
        {
            const char* items[] = { "Shade" };
            static int item_current_idx = 0;
            const char* combo_preview_value = items[item_current_idx];
            ImGui::SetNextItemWidth(150);
            if (ImGui::BeginCombo("Draw Mode", combo_preview_value))
            {

                ImGui::EndCombo();
            }
            ImGui::EndMenuBar();
        }


        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tex, 0);

        pbr_render();
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        //ImGui::GetWindowDrawList()->AddImage(tex, { 300,300 }, { 500,500 });
    }
}