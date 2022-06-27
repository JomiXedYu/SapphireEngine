#ifndef _Sapphire_UTILITY_MEASURE_H
#define _Sapphire_UTILITY_MEASURE_H

#endif // !Sapphire_UTILITY_MEASURE_H


namespace Sapphire::Utility
{
    struct Vector3;
    class Transform;

    class Measure
    {
    public:
        static bool Sector(Transform* origin, Transform* target, float radius, float degree, float height);
        static bool Cylinder(Transform* origin, Transform* target, float radius, float height);
        static bool Sphere(Transform* origin, Transform* target, float radius);
        static bool Rect(Transform* origin, Transform* target, float forward, float width, float height);
    };
}


