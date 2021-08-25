#include <SapphireEngine/ShaderProgram.h>
#include <ThirdParty/glad/glad.h>
#include <SapphireEngine/UnitType/_include.h>
#include <SapphireEngine/Assets/Texture2D.h>

namespace SapphireEngine 
{
    using namespace std;

    uint32_t ShaderProgram::get_id() const
    {
        return this->id_;
    }

    ShaderProgram::ShaderProgram(const string& name)
    {
        this->name_ = name;
        this->id_ = glCreateProgram();
    }

    ShaderProgram::~ShaderProgram()
    {
        glDeleteProgram(this->id_);
    }

    string ShaderProgram::ToString() const
    {
        return this->name_;
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
                throw ShaderCompileException(this->ToString() + infoLog);
                
            }
        }
    }

    void ShaderProgram::AddTexture(Texture2D* tex)
    {
        this->textures_.push_back(tex);
    }

    int32_t ShaderProgram::GetUniformLocaltion(const string& name)
    {
        return glGetUniformLocation(this->id_, name.data());
    }

    void ShaderProgram::SetUniformInt(const string& name, const int32_t& i)
    {
        glUniform1i(this->GetUniformLocaltion(name), i);
    }

    void ShaderProgram::SetUniformFloat(const string& name, const float& f)
    {
        glUniform1f(this->GetUniformLocaltion(name), f);
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

    void ShaderProgram::SetUniformColor(const string& name, const Vector3& value)
    {
        SetUniformColor(name, Color(value.x, value.y, value.z));
    }

    void ShaderProgram::SetUniformTexture2D(const string& name, const string& tex_name)
    {
        Texture2D* tex = nullptr;
        int i = 0;
        for (auto& item : this->textures_)
        {
            if (item->get_name() == tex_name)
            {
                tex = item;
                break;
            }
            ++i;
        }
        if (tex == nullptr)
        {
            throw 0;
        }
        this->SetUniformInt(name, i);
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, tex->get_id());
    }


}
