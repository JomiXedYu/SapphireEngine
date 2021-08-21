#include <SapphireEngine/Components/MeshRenderer.h>
#include <ThirdParty/glad/glad.h>
#include <SapphireEngine/Assets/Mesh.h>
#include <SapphireEngine/Assets/Texture2D.h>
#include <SapphireEngine/ShaderProgram.h>

namespace SapphireEngine
{
    void MeshRenderer::OnDraw(ShaderProgram* program)
    {
        unsigned int diffuseNr = 1;
        unsigned int specularNr = 1;
        
        for (unsigned int i = 0; i < this->mesh_->textures.size(); i++)
        {
            glActiveTexture(GL_TEXTURE0 + i); // 在绑定之前激活相应的纹理单元
            // 获取纹理序号（diffuse_textureN 中的 N）
            string number;
            string name = this->mesh_->textures[i]->get_type();
            if (name == "texture_diffuse")
                number = std::to_string(diffuseNr++);
            else if (name == "texture_specular")
                number = std::to_string(specularNr++);

            program->SetUniformFloat(("material." + name + number).c_str(), i);
            glBindTexture(GL_TEXTURE_2D, this->mesh_->textures[i]->get_id());
        }
        glActiveTexture(GL_TEXTURE0);

        // 绘制网格
        glBindVertexArray(this->mesh_->VAO);
        glDrawElements(GL_TRIANGLES, this->mesh_->indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
}