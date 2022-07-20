#ifndef _Sapphire_MOBJECT_H
#define _Sapphire_MOBJECT_H

#include <CoreLib/Core.h>
#include <CoreLib/Reflection.h>
#include <cstdint>
#include <string>

namespace Sapphire
{
    using namespace JxCoreLib;

    template<typename T>
    using Array = std::vector<T>;

    class MObject : public Object
    {
        CORELIB_DEF_TYPE(Sapphire::MObject, Object);
    public:
        MObject();
        virtual ~MObject() override;
    public:


	public:
        bool get_is_destoryed() const;
        bool get_instance_id() const { return this->instance_id_; }
	private:
		bool is_destoryed_;
        int32_t instance_id_;
    };

    template<typename T>
    concept baseof_mobject = std::is_base_of<MObject, T>::value;

	class MObjectInstanceTable
	{
		friend class MObject;
	public:
		static bool CheckInstance(int32_t instance_id)
		{
			return instance_map_.find(instance_id) != instance_map_.end();
		}
	private:
		/**
		* @return instance_id
		*/
		static int32_t ConstructInstance(MObject* object)
		{
			++instance_id_;
			instance_map_.insert(std::make_pair(instance_id_, object));
			return instance_id_;
		}
		static void RemoveInstance(int32_t id)
		{
			instance_map_.erase(id);
		}
		static MObject* GetInstance(int32_t instance_id)
		{
			auto it = instance_map_.find(instance_id);
			if (it == instance_map_.end())
			{
				return nullptr;
			}
			return it->second;
		}
	private:
		static inline int32_t instance_id_ = 0;
		static inline std::map<int32_t, MObject*> instance_map_;
	};
}

#endif // !Sapphire_MOBJECT_H