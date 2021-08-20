#ifndef _SAPPHIREENGINE_ASSETS_TEXTURE2D_H
#define _SAPPHIREENGINE_ASSETS_TEXTURE2D_H

#include <SapphireEngine/MObject.h>
#include <SapphireEngine/Assets/Bitmap.h>

namespace SapphireEngine
{
    class Texture2D : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Texture2D, MObject);
    
    public:
        Texture2D();
        ~Texture2D() override;
    public:
        uint32_t get_id() const { return id_; }
        const string& get_name() const { return name_; }

    public:
        void SetData(const string& name, Bitmap* bitmap);

    private:
        uint32_t id_ = 0;
        string name_;
        Bitmap* bitmap_ = nullptr;
        bool is_sealed = false;
    };
}

#endif // !_SAPPHIREENGINE_ASSETS_TEXTURE_H
