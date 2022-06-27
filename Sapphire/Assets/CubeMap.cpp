#include <Sapphire/Assets/CubeMap.h>
#include <ThirdParty/glad/glad.h>
#include <Sapphire/Private/ResourceInterface.h>
#include <CoreLib/File.h>
#include <CoreLib.Serializer/JsonSerializer.h>

namespace Sapphire
{

    class CubeMapAssetObject : public Object
    {
        CORELIB_DEF_TYPE(Sapphire::CubeMapAssetObject, Object);
    public:
        CORELIB_REFL_DECL_FIELD(Top);
        string Top;
        CORELIB_REFL_DECL_FIELD(Left);
        string Left;
        CORELIB_REFL_DECL_FIELD(Bottom);
        string Bottom;
        CORELIB_REFL_DECL_FIELD(Front);
        string Front;
        CORELIB_REFL_DECL_FIELD(Back);
        string Back;
        CORELIB_REFL_DECL_FIELD(Right);
        string Right;
    };

    AssetObject* CubeMapImporter::OnImport(const AssetImporterContext& ctx, Type* type)
    {
        auto ser = Serializer::JsonSerializer::Deserialize<CubeMapAssetObject>(FileUtil::ReadAllText(ctx.get_assetpath()));
        CubeMap* cubemap = new CubeMap;
        string* str[6] = {
            &ser->Right,
            &ser->Left,
            &ser->Top,
            &ser->Bottom,
            &ser->Front,
            &ser->Back,
        };
        const string& dir = ctx.get_directory();
        glGenTextures(1, &cubemap->id);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubemap->id);

        for (unsigned int i = 0; i < 6; i++)
        {
            int width, height, channel;
            const string& path = StringUtil::Concat(dir, "/", *str[i]);
            uint8_t* data = Private::ResourceInterface::LoadBitmap(path, &width, &height, &channel);
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
            );
            Private::ResourceInterface::FreeBitmap(data);
        }
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

        return cubemap;
    }
}