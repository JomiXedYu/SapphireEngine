#include <SapphireEngine/Resource.h>
#include <SapphireEngine/Private/BaseInterface.h>

#include <SapphireEngine/Assets/Bitmap.h>
#include <SapphireEngine/Assets/Texture2D.h>

namespace SapphireEngine 
{
    using namespace Private;
    using namespace std;

    Bitmap* Resource::LoadBitmap(const string& name)
    {
        int width, height;
        unsigned char* data = ResourceInterface::LoadBitmap(name, &width, &height);
        Bitmap* bitmap = new Bitmap();
        bitmap->SetData(data, width, height);
        return bitmap;
    }
    Texture2D* Resource::LoadTexture2D(const string& name)
    {
        Texture2D* tex = new Texture2D();
        tex->SetData(name, LoadBitmap(name));
        return tex;
    }
}
