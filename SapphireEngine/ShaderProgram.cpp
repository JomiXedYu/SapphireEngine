#include <SapphireEngine/ShaderProgram.h>
#include <ThirdParty/glad/glad.h>
#include <SapphireEngine/UnitType/_include.h>

namespace SapphireEngine 
{
    using namespace std;

    uint32_t ShaderProgram::get_id() const
    {
        return this->id_;
    }

    ShaderProgram::ShaderProgram()
    {
        this->id_ = glCreateProgram();
    }

    ShaderProgram::~ShaderProgram()
    {
        glDeleteProgram(this->id_);
    }

    static bool _CheckShaderProgram(int id)
    {
        int isSuccess;
        glGetProgramiv(id, GL_LINK_STATUS, &isSuccess);
        return isSuccess;
    }

    void ShaderProgram::UseProgram()
    {
        glUseProgram(this->id_);
    }

    void ShaderProgram::AttachShader(const Shader& shaderId)
    {
        glAttachShader(this->id_, shaderId.get_id());
    }

    void ShaderProgram::Link()
    {
        glLinkProgram(this->id_);
        if (!_CheckShaderProgram(this->id_)) {
            int success;
            char infoLog[512];
            glGetProgramiv(this->id_, GL_LINK_STATUS, &success);
            if (!success) {
                glGetProgramInfoLog(this->id_, 512, NULL, infoLog);

                //throw ;
            }
        }
    }

    int32_t ShaderProgram::GetUniformLocaltion(const string& name)
    {
        //std::string str = StringUtility::WstringToString(name);
        return glGetUniformLocation(this->id_, name.data());
    }

    void ShaderProgram::SetUniformInt(const string& name, const int32_t& i)
    {
        glUniform1i(this->GetUniformLocaltion(name), i);
    }

    void ShaderProgram::SetUniformMatrix4fv(const string& name, const float* value)
    {
        glUniformMatrix4fv(this->GetUniformLocaltion(name), 1, GL_FALSE, value);
    }

    void ShaderProgram::SetUniformMatrix4fv(const string& name, const Matrix& mat)
    {
        SetUniformMatrix4fv(name, mat.get_value_ptr());
    }

    void ShaderProgram::SetUniformVector3(const string& name, const Vector3& value)
    {
        glUniform3fv(this->GetUniformLocaltion(name), 1, value.get_value_ptr());
    }

    void ShaderProgram::SetUniformColor(const string& name, const Color& value)
    {
        glUniform4fv(this->GetUniformLocaltion(name), 1, value.get_value_ptr());
    }


}
