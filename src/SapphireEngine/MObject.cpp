#include <SapphireEngine/MObject.h>

namespace SapphireEngine
{
    void MObject::AddManagedChild(MObject* child)
    {
        if (child == nullptr)
        {
            return;
        }
        if (std::find(managed_list_.begin(), managed_list_.end(), child) != managed_list_.end())
        {
            managed_list_.push_back(child);
        }
    }
    void MObject::RemoveManagedChild(MObject* child)
    {
        if (child == nullptr)
        {
            return;
        }
        for (auto it = managed_list_.begin(); it != managed_list_.end(); it++)
        {
            if ((*it) == child)
            {
                managed_list_.erase(it);
                return;
            }
        }
    }
    void MObject::SetManagedParent(MObject* parent)
    {
        if (parent == nullptr)
        {
            return;
        }
        parent->AddManagedChild(this);
    }
    MObject::~MObject()
    {
        for (MObject* item : managed_list_)
        {
            delete item;
        }
    }
}