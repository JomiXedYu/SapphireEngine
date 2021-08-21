#include <SapphireEngine/Assets/Texture2D.h>

#include <ThirdParty/glad/glad.h>
#include <CoreLib/File.h>

namespace SapphireEngine
{
    Texture2D::Texture2D()
    {

    }
    Texture2D::~Texture2D()
    {
    }
    void Texture2D::SetData(const string& name, const string& type, Bitmap* bitmap)
    {
        if (this->is_sealed)
        {
            return;
        }


        glGenTextures(1, &this->id_);
        glBindTexture(GL_TEXTURE_2D, this->id_);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmap->get_width(), bitmap->get_height(), 0, GL_RGB, GL_UNSIGNED_BYTE, bitmap->GetNativeData());
        glGenerateMipmap(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, 0);

        this->name_ = PathUtil::GetFilenameWithoutExt(name);
        this->type_ = type;
        this->bitmap_ = bitmap;
        this->is_sealed = true;
    }
}
