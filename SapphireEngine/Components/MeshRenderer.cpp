#include <SapphireEngine/Components/MeshRenderer.h>
#include <ThirdParty/glad/glad.h>
#include <SapphireEngine/Assets/Mesh.h>
#include <SapphireEngine/Assets/Texture2D.h>
#include <SapphireEngine/ShaderProgram.h>

namespace SapphireEngine
{

    void MeshRenderer::OnInitialize()
    {

    }

    void MeshRenderer::Render()
    {
        auto meshc = this->get_node()->GetComponent<MeshContainer>();
        if (meshc == nullptr)
        {
            return;
        }

        this->material_->program->UseProgram();

        auto vao = meshc->get_mesh()->VAO;
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, meshc->get_mesh()->indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

}