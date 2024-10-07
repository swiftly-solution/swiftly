#include "Offsets.h"

#include "../../common.h"
#include "../../filesystem/files/Files.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

#define HAS_MEMBER(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                \
    if (!DOCUMENT.HasMember(MEMBER_NAME))                                             \
    {                                                                                 \
        OffsetsError(string_format("The field \"%s\" doesn't exists.", MEMBER_PATH)); \
        continue;                                                                     \
    }

#define IS_NUMBER(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                  \
    if (!DOCUMENT[MEMBER_NAME].IsInt())                                                \
    {                                                                                  \
        OffsetsError(string_format("The field \"%s\" is not a number.", MEMBER_PATH)); \
        continue;                                                                      \
    }

void OffsetsError(std::string text)
{
    if (!g_SMAPI)
        return;

    PLUGIN_PRINTF("Offsets", "%s\n", text.c_str());
}

void Offsets::LoadOffsets()
{
    auto files = Files::FetchFileNames("addons/swiftly/gamedata");
    for(auto file : files) {
        if(!ends_with(file, "offsets.json")) continue;

        rapidjson::Document offsetsFile;
        offsetsFile.Parse(Files::Read(file).c_str());
        if (offsetsFile.HasParseError()) {
            OffsetsError(string_format("A parsing error has been detected.\nError (offset %u): %s\n", (unsigned)offsetsFile.GetErrorOffset(), GetParseError_En(offsetsFile.GetParseError())));
            continue;
        }

        if (offsetsFile.IsArray()) {
            OffsetsError("Offsets file cannot be an array.");
            continue;
        }

        for (auto it = offsetsFile.MemberBegin(); it != offsetsFile.MemberEnd(); ++it)
        {
            std::string name = it->name.GetString();
            if(this->offsets.find(name) != this->offsets.end()) {
                OffsetsError(string_format("The offsets for '%s' has been already loaded.", name.c_str()));
                continue;
            }

            HAS_MEMBER(it->value, "windows", string_format("%s.windows", name))
            HAS_MEMBER(it->value, "linux", string_format("%s.linux", name))

            IS_NUMBER(it->value, "windows", string_format("%s.windows", name))
            IS_NUMBER(it->value, "linux", string_format("%s.linux", name))

            int offset = it->value[WIN_LINUX("windows", "linux")].GetInt();

            this->offsets.insert(std::make_pair(name, offset));
        }
    }
}

int Offsets::GetOffset(std::string name)
{
    if (this->offsets.find(name) == this->offsets.end())
        return -1;

    return this->offsets.at(name);
}