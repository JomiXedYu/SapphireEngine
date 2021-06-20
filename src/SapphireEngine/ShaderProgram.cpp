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

    bool ShaderProgram::CheckShaderProgram()
    {
        int isSuccess;
        glGetProgramiv(this->id_, GL_LINK_STATUS, &isSuccess);
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
        if (!this->CheckShaderProgram()) {
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
        SetUniformMatrix4fv(name, const_cast<Matrix&>(mat).get_value_ptr());
    }

    void ShaderProgram::SetUniformVector3(const string& name, const Vector3& value)
    {
        glUniform3fv(this->GetUniformLocaltion(name), 1, const_cast<Vector3&>(value).get_value_ptr());
    }

    void ShaderProgram::SetUniformColor(const string& name, const Color& value)
    {
        glUniform4fv(this->GetUniformLocaltion(name), 1, const_cast<Color&>(value).get_value_ptr());
    }


}
