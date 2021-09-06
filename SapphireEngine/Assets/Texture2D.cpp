#include <SapphireEngine/Assets/Texture2D.h>
#include <SapphireEngine/Private/BaseInterface.h>
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
        Private::RenderInterface::LoadTexture2D(bitmap, &this->id_);
        this->name_ = PathUtil::GetFilenameWithoutExt(name);
        this->type_ = type;
        this->bitmap_ = bitmap;
        this->is_sealed = true;
    }
}
