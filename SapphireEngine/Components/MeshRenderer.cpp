#include <SapphireEngine/Components/MeshRenderer.h>
#include <ThirdParty/glad/glad.h>
#include <SapphireEngine/Assets/Mesh.h>
#include <SapphireEngine/Assets/Texture2D.h>
#include <SapphireEngine/ShaderProgram.h>

namespace SapphireEngine
{
    void MeshRenderer::OnDraw(ShaderProgram* program)
    {
        //unsigned int diffuseNr = 1;
        //unsigned int specularNr = 1;
        //unsigned int normalNr = 1;
        //program->UseProgram();
        //for (unsigned int i = 0; i < this->mesh_->textures.size(); i++)
        //{
        //    glActiveTexture(GL_TEXTURE0 + i); // 在绑定之前激活相应的纹理单元
        //    // 获取纹理序号（diffuse_textureN 中的 N）
        //    string number;
        //    string name = this->mesh_->textures[i]->get_type();
        //    if (name == "mat_diffuse_tex")
        //        number = std::to_string(diffuseNr++);
        //    else if (name == "mat_specular_tex")
        //        number = std::to_string(specularNr++);
        //    else if (name == "mat_normal_tex")
        //        number = std::to_string(normalNr++);

        //    auto loc = glGetUniformLocation(program->get_id(), (name + number).c_str());
        //    glBindTexture(GL_TEXTURE_2D, this->mesh_->textures[i]->get_id());
        //    program->SetUniformInt((name + number).c_str(), i);
        //    auto error = glGetError();
        //}
        //glActiveTexture(GL_TEXTURE0);

        //// 绘制网格
        //glBindVertexArray(this->mesh_->VAO);
        //glDrawElements(GL_TRIANGLES, this->mesh_->indices.size(), GL_UNSIGNED_INT, 0);
        //glBindVertexArray(0);


        //PBR

        Texture2D tex[5];
        
        program->SetUniformInt("albedoMap", 1);
        program->SetUniformInt("normalMap", 2);
        program->SetUniformInt("matallicMap", 3);
        program->SetUniformInt("roughnessMap", 4);
        program->SetUniformInt("aoMap", 5);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, 1);

        this->mesh_;
    }
    void MeshRenderer::OnUpdate()
    {

    }
}