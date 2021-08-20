#ifndef _SAPPHIREENGINE_RESOURCE_H
#define _SAPPHIREENGINE_RESOURCE_H

#include <SapphireEngine/MObject.h>

namespace SapphireEngine
{
    class Bitmap;
    class Texture2D;

    namespace Resource
    {
        Bitmap* LoadBitmap(const string& name);
        Texture2D* LoadTexture2D(const string& name);
    }

}


#endif // !SAPPHIREENGINE_RESOURCE_H


