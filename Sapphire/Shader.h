#ifndef _Sapphire_SHADER_H
#define _Sapphire_SHADER_H

#include <Sapphire/MObject.h>
#include <Sapphire/EngineException.h>

namespace Sapphire
{
    class Shader : public MObject
    {
        CORELIB_DEF_TYPE(Sapphire::Shader, MObject);
    public:
        static Shader CreateVetexShader(const string& shaderName, const string& shaderSource);
        static Shader CreateFragmentShader(const string& shaderName, const string& fragSource);
    private:
        uint32_t id_;
        string name_;
        bool disposed = false;
    public:
        uint32_t get_id() const;
    protected:
        Shader(const string& name, uint32_t id);
    public:
        ~Shader();
    public:
        void DeleteShader();
    };

    class ShaderCompileException : public EngineException
    {
        CORELIB_DEF_TYPE(Sapphire::ShaderCompileException, EngineException);
    public:
        DEF_EXCEPTION_CTOR(ShaderCompileException);
    };


}

#endif // !Sapphire_SHADER_H


