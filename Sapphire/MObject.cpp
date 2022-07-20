#include <Sapphire/MObject.h>
#include <map>

namespace Sapphire
{


	MObject::MObject() : is_destoryed_(false)
	{
		this->instance_id_ = MObjectInstanceTable::ConstructInstance(this);
	}

	MObject::~MObject()
	{
		MObjectInstanceTable::RemoveInstance(this->instance_id_);
	}

	bool MObject::get_is_destoryed() const
	{
		return this->is_destoryed_;
	}
}