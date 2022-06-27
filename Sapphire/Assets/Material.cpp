#include <Sapphire/Assets/Material.h>
#include <ThirdParty/glad/glad.h>

namespace Sapphire
{
    void Material::Bind()
    {
        this->program->UseProgram();

        int32_t i = 0;
        for (auto& [name, tex] : this->textures)
        {
            glActiveTexture(GL_TEXTURE1 + i);
            glBindTexture(GL_TEXTURE_2D, tex->get_id());
            this->program->SetUniformInt(name, tex->get_id());
            i++;
        }

        glActiveTexture(GL_TEXTURE0);

    }
}