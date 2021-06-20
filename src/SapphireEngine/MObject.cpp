#include <SapphireEngine/MObject.h>

namespace SapphireEngine
{
    void MObject::AddManagedChild(MObject* child)
    {
        if (std::find(managed_list_.begin(), managed_list_.end(), child) != managed_list_.end())
        {
            managed_list_.push_back(child);
        }
    }
    MObject::~MObject()
    {
        for (MObject* item : managed_list_)
        {
            delete item;
        }
    }
}