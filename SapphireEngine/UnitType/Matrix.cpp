#include <SapphireEngine/UnitType/Matrix.h>
#include <string>
#include <sstream>
#include <SapphireEngine/UnitType/Vector3.h>
#include <SapphireEngine/UnitType/Vector4.h>
#include <SapphireEngine/Math.h>

namespace SapphireEngine
{
    Matrix::Matrix()
    {
    }

    Matrix::Matrix(
        const float& x1, const float& y1, const float& z1, const float& w1,
        const float& x2, const float& y2, const float& z2, const float& w2,
        const float& x3, const float& y3, const float& z3, const float& w3,
        const float& x4, const float& y4, const float& z4, const float& w4)
    {
        this->value[0] = Vector4(x1, x2, x3, x4);
        this->value[1] = Vector4(y1, y2, y3, y4);
        this->value[2] = Vector4(z1, z2, z3, z4);
        this->value[3] = Vector4(w1, w2, w3, w4);
    }
    Matrix::Matrix(const float& x)
    {
        this->value[0] = Vector4(x, 0, 0, 0);
        this->value[1] = Vector4(0, x, 0, 0);
        this->value[2] = Vector4(0, 0, x, 0);
        this->value[3] = Vector4(0, 0, 0, x);
    }
    Matrix::Matrix(const Vector4& x, const Vector4& y, const Vector4& z, const Vector4& w)
    {
        this->value[0] = x;
        this->value[1] = y;
        this->value[2] = z;
        this->value[3] = w;
    }


    Matrix Matrix::Scale(const Vector3& v3)
    {
        return Matrix(
            v3.x, 0, 0, 0,
            0, v3.y, 0, 0,
            0, 0, v3.z, 0,
            0, 0, 0, 1
        );
    }

    Matrix Matrix::One()
    {
        return Matrix(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        );
    }

    Matrix::operator Matrix3()
    {
        return Matrix3{ (Vector3)value[0], (Vector3)value[1], (Vector3)value[2] };
    }


    Matrix Matrix::operator*(Matrix target)
    {
        Matrix mat;
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                float result = 0;
                for (int i = 0; i < 4; i++)
                {
                    result += this->value[i][r] * target.value[c][i];
                }
                mat.value[c][r] = result;
            }
        }
        return mat;
    }

    Vector4& Matrix::operator[](const int& index)
    {
        return this->value[index];
    }

    const Vector4& Matrix::operator[](const int& index) const
    {
        return this->value[index];
    }


    std::string Matrix::ToString() const
    {
        std::stringstream ss;
        ss << "\n";
        for (int r = 0; r < 4; r++)
        {
            ss << "|";
            for (int c = 0; c < 4; c++)
            {
                ss.width(10);

                Vector4 vec = this->value[c];
                ss << vec[r];
            }
            ss << "|" << std::endl;
        }

        return ss.str();
    }

    Matrix Matrix::Perspective(const float& fovy, const float& aspect, const float& zNear, const float& zFar)
    {
        float const tanHalfFovy = tan(fovy / 2);
        Matrix result;
        result[0][0] = 1 / (aspect * tanHalfFovy);
        result[1][1] = 1 / (tanHalfFovy);
        result[2][3] = -1;

        result[2][2] = -(zFar + zNear) / (zFar - zNear);
        result[3][2] = -(2 * zFar * zNear) / (zFar - zNear);
        return result;
    }

    Matrix Matrix::Ortho(float left, float right, float bottom, float top, float zNear, float zFar)
    {
        Matrix Result = Matrix::One();
        Result[0][0] = 2 / (right - left);
        Result[1][1] = 2 / (top - bottom);
        Result[3][0] = -(right + left) / (right - left);
        Result[3][1] = -(top + bottom) / (top - bottom);

        Result[2][2] = -2 / (zFar - zNear);
        Result[3][2] = -(zFar + zNear) / (zFar - zNear);

        return Result;
    }

    Matrix Matrix::LookAt(const Vector3& eye, const Vector3& center, const Vector3& up)
    {
        Vector3 f(Vector3::Normalize(center - eye));
        Vector3 s(Vector3::Normalize(Vector3::Cross(f, up)));
        Vector3 u(Vector3::Cross(s, f));

        Matrix Result(1);
        Result[0][0] = s.x;
        Result[1][0] = s.y;
        Result[2][0] = s.z;
        Result[0][1] = u.x;
        Result[1][1] = u.y;
        Result[2][1] = u.z;
        Result[0][2] = -f.x;
        Result[1][2] = -f.y;
        Result[2][2] = -f.z;
        Result[3][0] = -Vector3::Dot(s, eye);
        Result[3][1] = -Vector3::Dot(u, eye);
        Result[3][2] = Vector3::Dot(f, eye);
        return Result;

    }
    Matrix Matrix::Translate(const Matrix& m, const Vector3& v3)
    {
        Matrix Result(m);
        Result[3] = m[0] * v3.x + m[1] * v3.y + m[2] * v3.z + m[3];
        return Result;
    }

    Vector4 Matrix::GetRow(int32_t line) const
    {
        Vector4 vec;
        for (size_t i = 0; i < 4; i++)
        {
            vec[i] = this->value[i][0];
        }
        return vec;
    }

    Vector4 Matrix::GetColumn(int32_t line) const
    {
        return this->value[line];
    }

    Matrix3::Matrix3(
        const float& x1, const float& y1, const float& z1,
        const float& x2, const float& y2, const float& z2,
        const float& x3, const float& y3, const float& z3)
    {
        this->value[0] = Vector3(x1, x2, x3);
        this->value[1] = Vector3(y1, y2, y3);
        this->value[2] = Vector3(z1, z2, z3);
    }

    Matrix3::Matrix3(const float& v)
    {
        this->value[0] = Vector3(v, 0, 0);
        this->value[1] = Vector3(0, v, 0);
        this->value[2] = Vector3(0, 0, v);
    }

    Matrix3::Matrix3(const Vector3& x, const Vector3& y, const Vector3& z)
    {
        this->value[0] = x;
        this->value[1] = y;
        this->value[2] = z;
    }

    Matrix3::operator Matrix()
    {
        return Matrix{ Vector4(value[0],0), Vector4(value[1],0), Vector4(value[2],0), Vector4(0,0,0,1) };
    }

}
