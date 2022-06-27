#ifndef _Sapphire_SHADERPROGRAM_H
#define _Sapphire_SHADERPROGRAM_H

#include <Sapphire/MObject.h>
#include <Sapphire/Shader.h>
#include <vector>
#include <string_view>

namespace Sapphire
{
    struct Vector3;
    struct Matrix;
    struct Color;
    class Texture2D;

    class ShaderProgram : public MObject
    {
        CORELIB_DEF_TYPE(Sapphire::ShaderProgram, MObject);
    
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

        int32_t GetUniformLocaltion(std::string_view name);
        void SetUniformInt(std::string_view name, const int32_t& i);
        void SetUniformFloat(std::string_view name, const float& f);
        void SetUniformMatrix4fv(std::string_view name, const float* value);
        void SetUniformMatrix4fv(std::string_view name, const Matrix& mat);
        void SetUniformVector3(std::string_view name, const Vector3& value);
        void SetUniformColor(std::string_view name, const Color& value);
        void SetUniformColor(std::string_view name, const Vector3& value);

        void SetUniformTexture2D(std::string_view name, const string& tex_name);

    protected:
        string name_;
        uint32_t id_;
        std::vector<Texture2D*> textures_;
    private:
        inline static uint32_t current_use_id = 0;
    };



}

#endif // !Sapphire_SHADERPROGRAM_H