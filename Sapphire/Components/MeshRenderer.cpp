#include <Sapphire/Components/MeshRenderer.h>
#include <ThirdParty/glad/glad.h>
#include <Sapphire/Assets/Mesh.h>
#include <Sapphire/Assets/Texture2D.h>
#include <Sapphire/ShaderProgram.h>

namespace Sapphire
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