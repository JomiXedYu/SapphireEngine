#ifndef _SAPPHIREENGINE_SHADER_H
#define _SAPPHIREENGINE_SHADER_H

#include <SapphireEngine/MObject.h>

namespace SapphireEngine
{
    class Shader : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::Shader, MObject);
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

}

#endif // !SAPPHIREENGINE_SHADER_H


