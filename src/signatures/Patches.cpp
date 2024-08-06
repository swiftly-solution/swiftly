#include "Patches.h"
#include "Signatures.h"
#include "../common.h"
#include "../utils/plat.h"
#include "../files/Files.h"
#include "../configuration/Configuration.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

#define HAS_MEMBER(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                \
    if (!DOCUMENT.HasMember(MEMBER_NAME))                                             \
    {                                                                                 \
        PatchesError(string_format("The field \"%s\" doesn't exists.", MEMBER_PATH)); \
        continue;                                                                     \
    }

#define IS_STRING(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                  \
    if (!DOCUMENT[MEMBER_NAME].IsString())                                             \
    {                                                                                  \
        PatchesError(string_format("The field \"%s\" is not a string.", MEMBER_PATH)); \
        continue;                                                                      \
    }

byte *HexToByte(const char *src, size_t &length);

void PatchesError(std::string text)
{
    if (!g_SMAPI)
        return;

    PRINTF("Patches", "%s\n", text.c_str());
}

void Patches::LoadPatches()
{
    rapidjson::Document patchesFile;
    patchesFile.Parse(Files::Read("addons/swiftly/gamedata/patches.json").c_str());
    if (patchesFile.HasParseError())
        return PatchesError(string_format("A parsing error has been detected.\nError (offset %u): %s\n", (unsigned)patchesFile.GetErrorOffset(), GetParseError_En(patchesFile.GetParseError())));

    if (patchesFile.IsArray())
        return PatchesError("Patches file cannot be an array.");

    for (auto it = patchesFile.MemberBegin(); it != patchesFile.MemberEnd(); ++it)
    {
        std::string name = it->name.GetString();

        HAS_MEMBER(it->value, "signature", string_format("%s.signature", name))
        HAS_MEMBER(it->value, "windows", string_format("%s.windows", name))
        HAS_MEMBER(it->value, "linux", string_format("%s.linux", name))

        IS_STRING(it->value, "signature", string_format("%s.signature", name))
        IS_STRING(it->value, "windows", string_format("%s.windows", name))
        IS_STRING(it->value, "linux", string_format("%s.linux", name))

        std::string signature = it->value["signature"].GetString();
        if (!g_Signatures->Exists(signature))
        {
            PatchesError(string_format("%s: Signature '%s' does not exists in signatures file.\n", name.c_str(), signature.c_str()));
            continue;
        }

        this->patches.insert(std::make_pair(name, std::string(it->value[WIN_LINUX("windows", "linux")].GetString())));
        this->signatures.insert(std::make_pair(name, signature));
    }
}

void Patches::PerformPatch(std::string patch_name)
{
    if (this->patches.find(patch_name) == this->patches.end())
    {
        PLUGIN_PRINTF("Patch", "Invalid patch name: \"%s\".\n", patch_name.c_str());
        return;
    }

    void *patchAddress = g_Signatures->FetchRawSignature(this->signatures.at(patch_name));

    size_t iLength = 0;
    byte *patch = HexToByte(this->patches.at(patch_name).c_str(), iLength);

    Plat_WriteMemory(patchAddress, (byte *)patch, iLength);
    PLUGIN_PRINTF("Patch", "Patched \"%s\" using signature \"%s\".\n", patch_name.c_str(), this->signatures.at(patch_name).c_str());
}

void Patches::PerformPatches()
{
    if (g_Config->HasKey("core.patches_to_perform"))
    {
        std::vector<std::string> patchesToPerform = explode(g_Config->FetchValue<std::string>("core.patches_to_perform"), " ");

        uint32_t patchesPerformed = 0;
        for (std::string &patchName : patchesToPerform)
        {
            if (patchName == "")
                continue;

            this->PerformPatch(patchName);
            ++patchesPerformed;
        }

        PLUGIN_PRINTF("Patch", "Patches performed: %02d.\n", patchesPerformed);
        patchesToPerform.clear();
    }
}