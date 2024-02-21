/**************************************************
 * This feature was taken from https://github.com/Source2ZE/CS2Fixes/commit/98cc65a8a10f03ef8a96003f2e23f74be48284bb
 * Thanks to CS2Fixes for providing this method.
 ***************************************************/

#include "addons.h"
#include "../files/Files.h"
#include "../common.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

#define HAS_MEMBER(DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT.HasMember(MEMBER_NAME))              \
    return AddonsError(string_format("The field \"%s\" doesn't exists.", MEMBER_PATH))

#define IS_ARRAY(DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT[MEMBER_NAME].IsArray())            \
    return AddonsError(string_format("The field \"%s\" is not an array.", MEMBER_PATH))
#define IS_STRING(DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT[MEMBER_NAME].IsString())            \
    return AddonsError(string_format("The field \"%s\" is not a string.", MEMBER_PATH))
#define IS_BOOL(DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT[MEMBER_NAME].IsBool())            \
    return AddonsError(string_format("The field \"%s\" is not a boolean.", MEMBER_PATH))
#define IS_UINT(DOCUMENT, MEMBER_NAME, MEMBER_PATH) \
    if (!DOCUMENT[MEMBER_NAME].IsUint())            \
    return AddonsError(string_format("The field \"%s\" is not a boolean.", MEMBER_PATH))

void AddonsError(std::string text)
{
    if (!g_SMAPI)
        return;

    PRINTF("Addons", "%s\n", text.c_str());
}

void Addons::RegisterAddons()
{
    std::vector<std::string> addons;

    rapidjson::Document addonsFile;
    addonsFile.Parse(Files::Read("addons/swiftly/configs/addons.json").c_str());
    if (addonsFile.HasParseError())
        return AddonsError(string_format("A parsing error has been detected.\nError (offset %u): %s\n", (unsigned)addonsFile.GetErrorOffset(), GetParseError_En(addonsFile.GetParseError())).c_str());

    if (addonsFile.IsArray())
        return AddonsError("Addons file cannot be an array.");

    HAS_MEMBER(addonsFile, "enabled", "enabled");
    IS_BOOL(addonsFile, "enabled", "enabled");
    this->SetStatus(addonsFile["enabled"].GetBool());

    HAS_MEMBER(addonsFile, "timeout", "timeout");
    IS_UINT(addonsFile, "timeout", "timeout");
    this->SetTimeout(addonsFile["timeout"].GetUint());

    HAS_MEMBER(addonsFile, "addons", "addons");
    IS_ARRAY(addonsFile, "addons", "addons");

    for (rapidjson::size_t i = 0; i < addonsFile["addons"].Size(); i++)
    {
        IS_STRING(addonsFile["addons"], i, string_format("addons[%d]", i).c_str());
        if (std::string(addonsFile["addons"][i].GetString()).size() > 0)
            addons.push_back(addonsFile["addons"][i].GetString());
    }

    this->addons_str = implode(addons, ",");
    AddonsError(string_format("Loaded %d addons.", addons.size()).c_str());
}