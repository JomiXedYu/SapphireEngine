//#include <SapphireEngine/PBRPipleline/PBRRenderer.h>
//#include <ThirdParty/glad/glad.h>
//
//#include <SapphireEngine/ShaderProgram.h>
//#include <SapphireEngine/Components/MeshContainer.h>
//
//namespace SapphireEngine::PBRPiplepine
//{
//    void PBRRenderer::Render()
//    {
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, tex->get_albedo()->get_id());
//
//        glActiveTexture(GL_TEXTURE2);
//        glBindTexture(GL_TEXTURE_2D, tex->get_normal()->get_id());
//
//        glActiveTexture(GL_TEXTURE3);
//        glBindTexture(GL_TEXTURE_2D, tex->get_metallic()->get_id());
//
//        glActiveTexture(GL_TEXTURE4);
//        glBindTexture(GL_TEXTURE_2D, tex->get_roughness()->get_id());
//
//        glActiveTexture(GL_TEXTURE5);
//        glBindTexture(GL_TEXTURE_2D, tex->get_ao()->get_id());
//
//        glActiveTexture(GL_TEXTURE0);
//
//
//
//        auto meshc = this->get_node()->GetComponent<MeshContainer>();
//        auto vao = meshc->mesh->VAO;
//        glBindVertexArray(vao);
//        glDrawElements(GL_TRIANGLES, meshc->mesh->indices.size(), GL_UNSIGNED_INT, 0);
//        glBindVertexArray(0);
//
//    }
//
//    void PBRRenderer::SetPBRShaderValue(ShaderProgram* program)
//    {
//        program->SetUniformInt("AlbedoMap", 1);
//        program->SetUniformInt("NormalMap", 2);
//        program->SetUniformInt("MatallicMap", 3);
//        program->SetUniformInt("RoughnessMap", 4);
//        program->SetUniformInt("AoMap", 5);
//    }
//
//}
//
