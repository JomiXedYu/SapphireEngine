#ifndef SAPPHIREENGINE_UNITTYPE_QUATERNION_H
#define SAPPHIREENGINE_UNITTYPE_QUATERNION_H

namespace SapphireEngine 
{
	struct Vector3;
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
	public:
		Vector3 get_euler() const;
		void set_euler(const Vector3& euler_angle);

		void add_euler_x(const float& value);
		void add_euler_y(const float& value);
		void add_euler_z(const float& value);
	};
}


#endif // !SAPPHIREENGINE_UNITTYPE_QUATERNION_H


