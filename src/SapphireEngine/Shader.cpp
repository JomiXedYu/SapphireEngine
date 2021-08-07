#include <SapphireEngine/Shader.h>

#include <ThirdParty/glad/glad.h>
#include <iostream>
#include <SapphireEngine/EngineException.h>

namespace SapphireEngine 
{

    bool _CheckShaderCompile(const uint32_t& shaderId)
    {
        int isSuccess;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isSuccess);
        return isSuccess;
    }
    string _GetShaderCompileErrorInfo(const uint32_t& shaderId)
    {
        char info[512];
        glGetShaderInfoLog(shaderId, 512, nullptr, info);
        return string(info);
    }
    uint32_t _CreateShader(const string& shaderName, const uint32_t& shaderType, const string& shaderSource)
    {
        uint32_t shader;
        shader = glCreateShader(shaderType);

        const char* _srcStr = shaderSource.c_str();

        glShaderSource(shader, 1, &_srcStr, nullptr);
        glCompileShader(shader);

        if (!_CheckShaderCompile(shader)) {
            throw ShaderCompileException(shaderName + _T("  ") + _GetShaderCompileErrorInfo(shader));
        }

        return shader;
    }


    //public
    Shader Shader::CreateVetexShader(const string& shaderName, const string& shaderSource)
    {
        uint32_t id = _CreateShader(shaderName, GL_VERTEX_SHADER, shaderSource);
        return Shader(shaderName, id);
    }

    Shader Shader::CreateFragmentShader(const string& shaderName, const string& fragSource)
    {
        uint32_t id = _CreateShader(shaderName, GL_FRAGMENT_SHADER, fragSource);
        return Shader(shaderName, id);
    }

    uint32_t Shader::get_id() const
    {
        return this->id_;
    }

    Shader::Shader(const string& name, uint32_t id)
        : name_(name), id_(id)
    {
    }

    void Shader::DeleteShader()
    {
        glDeleteShader(this->id_);
    }

}
