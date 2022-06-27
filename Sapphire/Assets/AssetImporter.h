#pragma once

#include "AssetObject.h"
#include <CoreLib/File.h>

#define ENGINE_ASSETIMPORTER() \
static inline struct __engine_assetimporter_init { \
    __engine_assetimporter_init() { \
        RegisterAssetImporter(new __corelib_curclass); \
    } \
} __engine_assetimporter_init_;

namespace Sapphire
{
    struct AssetImporterContext
    {
        string AssetPath;
        AssetImporterContext(const string& assetpath) : AssetPath(assetpath)
        {
        }
        const string& get_assetpath() const
        {
            return this->AssetPath;
        }
        string get_directory() const
        {
            return PathUtil::GetDirectory(this->AssetPath);
        }
        string get_filename_noext() const
        {
            return PathUtil::GetFilenameWithoutExt(this->AssetPath);
        }
    };


    class AssetImporter : public MObject
    {
        CORELIB_DEF_TYPE(Sapphire::AssetImporter, MObject);

    public:
        virtual AssetObject* OnImport(const AssetImporterContext& ctx, Type* type) = 0;
        virtual Type* GetAssetType() const = 0;

    protected:

    private:
        inline static std::map<Type*, AssetImporter*> importers;
    public:
        static void RegisterAssetImporter(AssetImporter* importer)
        {
            importers[importer->GetAssetType()] = importer;
        }

        static AssetImporter* GetAssetImporter(Type* type)
        {
            auto it = importers.find(type);
            return it != importers.end() ? it->second : nullptr;
        }
    };


}