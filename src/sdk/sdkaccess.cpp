#include "sdkaccess.h"
#include "../files/Files.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

SDKAccess::SDKAccess() {}
SDKAccess::~SDKAccess() {
    fieldNames.clear();
    fieldTypes.clear();
    fieldSizes.clear();
    fieldClass.clear();
    structStates.clear();
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
        if (it->value.IsObject()) {
            for (auto it2 = it->value.MemberBegin(); it2 != it->value.MemberEnd(); ++it2)
            {
                std::string fieldName = it2->name.GetString();
                if (fieldName == "struct")
                    this->structStates.insert({ className, it2->value.IsBool() ? it2->value.GetBool() : false });

                if (it2->value.IsObject()) {
                    if (!it2->value.HasMember("field") || !it2->value.HasMember("type")) continue;
                    if (!it2->value["field"].IsString() || !it2->value["type"].IsUint()) continue;

                    this->fieldNames.insert({ className + "." + fieldName, it2->value["field"].GetString() });
                    this->fieldTypes.insert({ className + "." + fieldName, (SDKFieldType_t)it2->value["type"].GetUint() });
                    if (it2->value.HasMember("size") && it2->value["size"].IsUint()) this->fieldSizes.insert({ className + "." + fieldName, it2->value["size"].GetUint() });
                    if (it2->value.HasMember("classname") && it2->value["classname"].IsString()) this->fieldClass.insert({ className + "." + fieldName, it2->value["classname"].GetString() });
                }
            }
        }
    }
}

std::string SDKAccess::GetFieldName(std::string path)
{
    return this->fieldNames.at(path);
}

SDKFieldType_t SDKAccess::GetFieldType(std::string path)
{
    return this->fieldTypes.at(path);
}

std::string SDKAccess::GetFieldClass(std::string path)
{
    return this->fieldClass.at(path);
}

uint32_t SDKAccess::GetFieldSize(std::string path)
{
    return this->fieldSizes.at(path);
}

bool SDKAccess::GetClassStructState(std::string className)
{
    return this->structStates.at(className);
}

bool SDKAccess::ExistsField(std::string path)
{
    return (this->fieldNames.find(path) != this->fieldNames.end());
}
