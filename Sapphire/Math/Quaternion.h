#ifndef _Sapphire_UNITTYPE_QUATERNION_H
#define _Sapphire_UNITTYPE_QUATERNION_H

#include <string>

namespace Sapphire 
{

	struct Vector3;
	struct Matrix;

	struct Quaternion
	{
	public:
		float x;
		float y;
		float z;
		float w;
	public:
		Quaternion();
		Quaternion(float x, float y, float z, float w);
		std::string ToString() const;
	public:
		Vector3 ToEuler() const;
		void SetEuler(const Vector3& euler_angle);
	public:
		Matrix ToMatrix4() const;
	public:
		void AddEulerX(const float& value);
		void AddEulerY(const float& value);
		void AddEulerZ(const float& value);
	};
}


#endif // !Sapphire_UNITTYPE_QUATERNION_H


