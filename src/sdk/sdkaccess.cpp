#include "sdkaccess.h"
#include "../files/Files.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include "schema.h"

void PopulateClassData(const char* className, uint32_t classOffset);

SDKAccess::SDKAccess() {}
SDKAccess::~SDKAccess() {
    fieldNames.clear();
    fieldTypes.clear();
    fieldSizes.clear();
    fieldClass.clear();
    structStates.clear();
    classnames.clear();
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

                if (fieldName == "struct")
                    this->structStates.insert({ className, it2->value.IsBool() ? it2->value.GetBool() : false });

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

bool SDKAccess::GetClassStructState(std::string className)
{
    return this->structStates[className];
}

bool SDKAccess::ExistsField(uint64_t path)
{
    return (this->fieldNames.find(path) != this->fieldNames.end());
}
