#ifndef SAPPHIREENGINE_MOBJECT_H
#define SAPPHIREENGINE_MOBJECT_H
#include <CoreLib/CoreLib.h>
#include <vector>

namespace SapphireEngine
{
    using namespace JxCoreLib;
    class MObject : public Object
    {
        CORELIB_DEF_TYPE(SapphireEngine::MObject, Object);
    protected:
        uint32_t instance_id_ = 0;
        std::vector<MObject*> managed_list_;
    public:
        void AddManagedChild(MObject* child);
        void SetManagedParent(MObject* parent);
    public:
        MObject() {}
        virtual ~MObject() override;
    public:
        bool operator==(const MObject& r)
        {
            return this->instance_id_ == r.instance_id_;
        }
        virtual string ToString() const override
        {
            return base::ToString();
        }

    };
}

#endif // !SAPPHIREENGINE_MOBJECT_H