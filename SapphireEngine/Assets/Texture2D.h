#ifndef _SAPPHIREENGINE_ASSETS_TEXTURE2D_H
#define _SAPPHIREENGINE_ASSETS_TEXTURE2D_H

#include "AssetObject.h"
#include <SapphireEngine/Assets/Bitmap.h>

namespace SapphireEngine
{
    class Texture2D : public AssetObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Texture2D, AssetObject);
    
    public:
        Texture2D();
        ~Texture2D() override;
    public:
        uint32_t get_id() const { return id_; }
        const string& get_name() const { return name_; }
        const string& get_type() const { return type_; }
        void set_type(const string& type) { type_ = type; }
    public:
        void SetData(const string& name, const string& type, Bitmap* bitmap);

    private:
        uint32_t id_ = 0;
        string name_;
        string type_;
        Bitmap* bitmap_ = nullptr;
        bool is_sealed = false;
    };
}

#endif // !_SAPPHIREENGINE_ASSETS_TEXTURE_H
