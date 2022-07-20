#include <Sapphire/ShaderProgram.h>
#include <ThirdParty/glad/glad.h>
#include <Sapphire/Math/_include.h>
#include <Sapphire/Assets/Texture2D.h>

namespace Sapphire 
{
    using namespace std;

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
        if (this->get_isused())
        {
            return;
        }
        glUseProgram(this->id_);
        current_use_id = this->id_;
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

    int32_t ShaderProgram::GetUniformLocaltion(std::string_view name)
    {
        return glGetUniformLocation(this->id_, name.data());
    }

    void ShaderProgram::SetUniformInt(std::string_view name, const int32_t& i)
    {
        glUniform1i(this->GetUniformLocaltion(name), i);
    }

    void ShaderProgram::SetUniformFloat(std::string_view name, const float& f)
    {
        glUniform1f(this->GetUniformLocaltion(name), f);
    }

    void ShaderProgram::SetUniformMatrix4fv(std::string_view name, const float* value)
    {
        glUniformMatrix4fv(this->GetUniformLocaltion(name), 1, GL_FALSE, value);
    }

    void ShaderProgram::SetUniformMatrix4fv(std::string_view name, const Matrix& mat)
    {
        SetUniformMatrix4fv(name, mat.get_value_ptr());
    }

    void ShaderProgram::SetUniformVector3(std::string_view name, const Vector3& value)
    {
        glUniform3fv(this->GetUniformLocaltion(name), 1, value.get_value_ptr());
    }

    void ShaderProgram::SetUniformColor(std::string_view name, const Color& value)
    {
        glUniform4fv(this->GetUniformLocaltion(name), 1, value.get_value_ptr());
    }

    void ShaderProgram::SetUniformColor(std::string_view name, const Vector3& value)
    {
        SetUniformColor(name, Color(value.x, value.y, value.z));
    }

    void ShaderProgram::SetUniformTexture2D(std::string_view name, const string& tex_name)
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
