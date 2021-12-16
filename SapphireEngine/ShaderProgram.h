#ifndef _SAPPHIREENGINE_SHADERPROGRAM_H
#define _SAPPHIREENGINE_SHADERPROGRAM_H

#include <SapphireEngine/MObject.h>
#include <SapphireEngine/Shader.h>
#include <vector>

namespace SapphireEngine
{
    struct Vector3;
    struct Matrix;
    struct Color;
    class Texture2D;

    class ShaderProgram : public MObject
    {
        CORELIB_DEF_TYPE(SapphireEngine::ShaderProgram, MObject);
    
    public:
        uint32_t get_id() const { return this->id_; }
        bool get_isused() const { return this->id_ == current_use_id; }
    public:
        explicit ShaderProgram(const string& name);
        virtual ~ShaderProgram() override;
        virtual string ToString() const override;
    public:
        void UseProgram();
        void AttachShader(const Shader& shaderId);
        void Link();

        void AddTexture(Texture2D* tex);

        int32_t GetUniformLocaltion(const string& name);
        void SetUniformInt(const string& name, const int32_t& i);
        void SetUniformFloat(const string& name, const float& f);
        void SetUniformMatrix4fv(const string& name, const float* value);
        void SetUniformMatrix4fv(const string& name, const Matrix& mat);
        void SetUniformVector3(const string& name, const Vector3& value);
        void SetUniformColor(const string& name, const Color& value);
        void SetUniformColor(const string& name, const Vector3& value);

        void SetUniformTexture2D(const string& name, const string& tex_name);

    protected:
        string name_;
        uint32_t id_;
        std::vector<Texture2D*> textures_;
    private:
        inline static uint32_t current_use_id = 0;
    };



}

#endif // !SAPPHIREENGINE_SHADERPROGRAM_H