#ifndef _SAPPHIREENGINE_RESOURCE_H
#define _SAPPHIREENGINE_RESOURCE_H

#include <string>

namespace SapphireEngine
{
    class Bitmap;

    namespace Resource
    {
        Bitmap* LoadBitmap(const std::string& name);
    };

}


#endif // !SAPPHIREENGINE_RESOURCE_H


