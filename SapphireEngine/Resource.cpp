#include <SapphireEngine/Resource.h>
#include <SapphireEngine/Private/BaseInterface.h>
#include <SapphireEngine/Assets/Bitmap.h>

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
}
