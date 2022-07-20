#pragma once
#include <Sapphire/MObject.h>
#include <Sapphire/Math/Color.h>
#include <Sapphire/Components/Component.h>

namespace Sapphire::Lighting
{
	class Light : Sapphire::Component
	{
		CORELIB_DEF_TYPE(Sapphire::Lighting::Light, Component)
		
	public:
		void SetTemperture(float value);
		void SetColor(Color color);
	};
}
