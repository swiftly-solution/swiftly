#include "sdkaccess.h"
#include "../../filesystem/files/Files.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include "../schema/schema.h"
#include <swiftly-ext/core.h>

extern std::set<uint32_t> structCache;
void PopulateClassData(const char* className, uint32_t classOffset);

SDKAccess::SDKAccess() {}
SDKAccess::~SDKAccess() {
    fieldNames.clear();
    fieldTypes.clear();
    fieldSizes.clear();
    fieldClass.clear();
    classnames.clear();
    sdktypes.clear();
}

void SDKAccess::LoadSDKData()
{
    rapidjson::Document sdkFile;
    sdkFile.Parse(Files::Read("addons/swiftly/gamedata/sdk.json").c_str());
    if (sdkFile.HasParseError())
        return;

    if (!sdkFile.IsObject())
        return;

    for (auto it = sdkFile.MemberBegin(); it != sdkFile.MemberEnd(); ++it)
    {
        std::string className = it->name.GetString();
        this->classnames.push_back(className);

        uint32_t classOffset = hash_32_fnv1a_const(className.c_str());
        PopulateClassData(className.c_str(), classOffset);

        if (it->value.IsObject()) {
            for (auto it2 = it->value.MemberBegin(); it2 != it->value.MemberEnd(); ++it2)
            {
                std::string fieldName = it2->name.GetString();

                if (it2->value.IsObject()) {
                    if (!it2->value.HasMember("field") || !it2->value.HasMember("type")) continue;
                    if (!it2->value["field"].IsString() || !it2->value["type"].IsUint()) continue;

                    uint64_t key = ((uint64_t) hash_32_fnv1a_const(className.c_str()) << 32 | hash_32_fnv1a_const(fieldName.c_str()));

                    this->fieldNames.insert({ key, it2->value["field"].GetString() });
                    this->fieldTypes.insert({ key, (SDKFieldType_t)it2->value["type"].GetUint() });
                    if (it2->value.HasMember("size") && it2->value["size"].IsUint()) this->fieldSizes.insert({ key, it2->value["size"].GetUint() });
                    if (it2->value.HasMember("classname") && it2->value["classname"].IsString()) this->fieldClass.insert({ key, it2->value["classname"].GetString() });
                }
            }
        }
    }

    PRINTF("Succesfully loaded %lld SDK fields.\n", this->fieldNames.size());

    rapidjson::Document sdkTypesFile;
    sdkTypesFile.Parse(Files::Read("addons/swiftly/gamedata/sdk_types.json").c_str());
    if (sdkTypesFile.HasParseError())
        return;

    if (!sdkTypesFile.IsObject())
        return;

    for (auto it = sdkTypesFile.MemberBegin(); it != sdkTypesFile.MemberEnd(); ++it)
    {
        std::string typeName = it->name.GetString();
        if(sdktypes.find(typeName) == sdktypes.end()) sdktypes.insert({typeName, {}});

        if (it->value.IsObject()) {
            for (auto it2 = it->value.MemberBegin(); it2 != it->value.MemberEnd(); ++it2)
            {
                std::string fieldName = it2->name.GetString();
                int64_t value = it2->value.GetInt64();
                sdktypes[typeName].insert({fieldName, value});
            }
        }
    }

    PRINTF("Succesfully loaded %lld SDK types.\n", this->sdktypes.size());
}

std::map<std::string, std::map<std::string, int64_t>> SDKAccess::GetSDKTypes()
{
    return this->sdktypes;
}

std::vector<std::string> SDKAccess::GetClassnames()
{
    return this->classnames;
}

std::string SDKAccess::GetFieldName(uint64_t path)
{
    return this->fieldNames[path];
}

SDKFieldType_t SDKAccess::GetFieldType(uint64_t path)
{
    return this->fieldTypes[path];
}

std::string SDKAccess::GetFieldClass(uint64_t path)
{
    return this->fieldClass[path];
}

uint32_t SDKAccess::GetFieldSize(uint64_t path)
{
    return this->fieldSizes[path];
}

bool SDKAccess::ExistsField(uint64_t path)
{
    return (this->fieldNames.find(path) != this->fieldNames.end());
}

EXT_API void* swiftly_GetSDKPtr(void* ptr, const char* className, const char* fieldName)
{
    auto m_key = sch::GetOffset(className, fieldName);
    return (void*)((uintptr_t)ptr + m_key);
}

EXT_API void swiftly_SetStateChanged(void* ptr, const char* className, const char* fieldName, int extraOffset)
{
    SetStateChanged((uintptr_t)ptr, className, fieldName, extraOffset);
}