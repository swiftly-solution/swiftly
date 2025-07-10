#include "access.h"
#include "game.h"

#include <filesystem/files/files.h>
#include <memory/encoders/json.h>
#include "schema.h"

#include <rapidjson/json.hpp>

#include <swiftly-ext/core.h>

extern std::set<uint32_t> structCache;
void PopulateClassData(const char* className, uint32_t classOffset);

void SDKAccess::LoadSDKData()
{
    std::string game_name = GetGameName();
    if (game_name == "unknown") {
        PRINT("Unknown game detected, not loading any SDK data.\n");
        return;
    }

    std::string gamedata_path = string_format("addons/swiftly/gamedata/%s/", game_name.c_str());
    auto j = encoders::json::FromString(Files::Read(gamedata_path + "sdk.json"), gamedata_path + "sdk.json");
    if (!j.IsObject()) return;

    for (auto it = j.MemberBegin(); it != j.MemberEnd(); ++it)
    {
        std::string className = it->name.GetString();
        uint32_t classOffset = hash_32_fnv1a_const(className.c_str());
        PopulateClassData(className.c_str(), classOffset);
        classes.insert(className);

        if (it->value.IsObject()) {
            for (auto it2 = it->value.MemberBegin(); it2 != it->value.MemberEnd(); ++it2)
            {
                std::string fieldName = it2->name.GetString();

                if (it2->value.IsObject()) {
                    if (!it2->value.HasMember("field") || !it2->value.HasMember("type")) continue;
                    if (!it2->value["field"].IsString() || !it2->value["type"].IsUint()) continue;

                    uint64_t key = ((uint64_t)hash_32_fnv1a_const(className.c_str()) << 32 | hash_32_fnv1a_const(fieldName.c_str()));

                    processedFieldNames.insert(fieldName);
                    fieldNames.insert({ key, it2->value["field"].GetString() });
                    fieldTypes.insert({ key, (SDKFieldType_t)(it2->value["type"].GetUint()) });
                    if (it2->value.HasMember("size") && it2->value["size"].IsUint()) fieldSizes.insert({ key, it2->value["size"].GetUint() });
                    if (it2->value.HasMember("classname") && it2->value["classname"].IsString()) fieldClass.insert({ key, it2->value["classname"].GetString() });
                }
            }
        }
    }

    PRINTF("Succesfully loaded %lld SDK fields and %lld classes.\n", fieldNames.size(), classes.size());

    j = encoders::json::FromString(Files::Read(gamedata_path + "sdk_types.json"), gamedata_path + "sdk_types.json");
    if (!j.IsObject()) return;

    for (auto it = j.MemberBegin(); it != j.MemberEnd(); ++it)
    {
        std::string typeName = it->name.GetString();
        if (sdktypes.find(typeName) == sdktypes.end()) sdktypes.insert({ typeName, {} });

        if (it->value.IsObject()) {
            for (auto it2 = it->value.MemberBegin(); it2 != it->value.MemberEnd(); ++it2)
            {
                std::string fieldName = it2->name.GetString();
                int64_t value = it2->value.GetInt64();
                sdktypes[typeName].insert({ fieldName, value });
            }
        }
    }

    PRINTF("Succesfully loaded %lld SDK types.\n", sdktypes.size());

    j = encoders::json::FromString(Files::Read(gamedata_path + "blocked_fields_by_guidelines.json"), gamedata_path + "blocked_fields_by_guidelines.json");
    if (!j.IsArray()) return;

    for (auto it = j.Begin(); it != j.End(); ++it)
    {
        if (!it->IsString()) continue;
        std::string fieldName = it->GetString();
        blockedFields.insert(fieldName);
    }

    PRINTF("Succesfully loaded %lld blocked SDK types.\n", blockedFields.size());
}

std::set<std::string> SDKAccess::GetClasses()
{
    return classes;
}

std::map<std::string, std::map<std::string, int64_t>> SDKAccess::GetSDKTypes()
{
    return sdktypes;
}

std::string& SDKAccess::GetFieldName(uint64_t path)
{
    return fieldNames[path];
}

SDKFieldType_t SDKAccess::GetFieldType(uint64_t path)
{
    return fieldTypes[path];
}

std::string SDKAccess::GetFieldClass(uint64_t path)
{
    return fieldClass[path];
}

uint32_t SDKAccess::GetFieldSize(uint64_t path)
{
    return fieldSizes[path];
}

bool SDKAccess::ExistsField(uint64_t path)
{
    return (fieldNames.find(path) != fieldNames.end());
}

std::set<std::string> SDKAccess::GetProcessedFieldNames()
{
    return processedFieldNames;
}

bool SDKAccess::IsFieldBlocked(std::string field)
{
    return blockedFields.find(field) != blockedFields.end();
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