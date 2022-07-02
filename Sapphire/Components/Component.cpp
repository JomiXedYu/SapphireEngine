#include <Sapphire/Components/Component.h>
#include <Sapphire/Node.h>

namespace Sapphire
{
    void Component::set_enabled(bool value)
    {
        if (enabled_ == value) return;
        enabled_ = value;
        if (value)
            this->SendMessage(MessageType::Enabled);
        else
            this->SendMessage(MessageType::Disabled);
    }
	
	bool Component::EqualsType(Type* type)
	{
		return GetType() == type;
	}
	
    void Component::SendMessage(MessageType_t msg)
    {
        switch (msg)
        {
        case MessageType::Initialize:
            this->OnInitialize(); break;
        case MessageType::Start:
            this->OnStart(); break;
        case MessageType::Enabled:
            this->OnEnabled(); break;
        case MessageType::Disabled:
            this->OnDisabled(); break;
        case MessageType::Destory:
            this->OnDestory(); break;
        [[likely]] case MessageType::Update:
            this->OnUpdate(); break;
        }
    }

}