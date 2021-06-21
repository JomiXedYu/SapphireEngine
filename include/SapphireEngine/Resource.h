#ifndef SAPPHIREENGINE_RESOURCE_H
#define SAPPHIREENGINE_RESOURCE_H

#include <CoreLib/String.h>

namespace SapphireEngine
{
    class Bitmap;
    using namespace JxCoreLib;

    namespace Resource
    {
        Bitmap* LoadBitmap(const string& name);
    };

}


#endif // !SAPPHIREENGINE_RESOURCE_H

