#ifndef _SAPPHIREENGINE_UNITTYPE_MATRIX_H
#define SAPPHIREENGINE_UNITTYPE_MATRIX_H

#include <string>
#include "Vector4.h"

namespace SapphireEngine
{
    struct Vector3;

    struct Matrix
    {
    public:
        Vector4 value[4];
    public:
        Matrix();
        Matrix(
            const float& x1, const float& y1, const float& z1, const float& w1,
            const float& x2, const float& y2, const float& z2, const float& w2,
            const float& x3, const float& y3, const float& z3, const float& w3,
            const float& x4, const float& y4, const float& z4, const float& w4);
        Matrix(const float& x);
        Matrix(const Vector4& x, const Vector4& y, const Vector4& z, const Vector4& w);
    public:
        const float* get_value_ptr() const;
    public:
        Matrix operator*(Matrix c);
        Vector4& operator[](const int& index);
        const Vector4& operator[](const int& index) const;
    public:
        std::string ToString() const;

        //static
    public:
        static Matrix Perspective(const float& fovy, const float& aspect, const float& zNear, const float& zFar);
        static Matrix Ortho(float left, float right, float bottom, float top, float zNear, float zFar);
        static Matrix LookAt(const Vector3& eye, const Vector3& center, const Vector3& up);
    public:
        static Matrix Translate(const Matrix& m, const Vector3& v3);
        static Matrix Rotate(const Vector3& v3);
        static Matrix Scale(const Vector3& v3);
        static Matrix One();

    };

}


#endif // !SAPPHIREENGINE_UNITTYPE_MATRIX_H
