#include "gamedata.h"

#include <core/entrypoint.h>
#include <memory/encoders/json.h>
#include <filesystem/files/files.h>
#include <utils/utils.h>
#include <utils/common.h>
#include <sdk/game.h>
#include <utils/platform/platform.h>
#include <server/configuration/configuration.h>
#include <dynlibutils/module.h>
#include <swiftly-ext/core.h>

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

#define IS_STRING(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                     \
    if (!DOCUMENT[MEMBER_NAME].IsString())                                                \
    {                                                                                     \
        SignaturesError(string_format("The field \"%s\" is not a string.", MEMBER_PATH)); \
        continue;                                                                         \
    }

DynLibUtils::CModule DetermineModuleByLibrary(std::string library) {
    if (library == "server")
        return DynLibUtils::CModule(server);
    else if (library == "engine2")
        return DynLibUtils::CModule(engine);
    else
        return DynLibUtils::CModule(library);
}

void SignaturesError(std::string text)
{
    if (!g_SMAPI)
        return;

    PLUGIN_PRINTF("Signatures", "%s\n", text.c_str());
}

void OffsetsError(std::string text)
{
    if (!g_SMAPI)
        return;

    PLUGIN_PRINTF("Offsets", "%s\n", text.c_str());
}

void PatchesError(std::string text)
{
    if (!g_SMAPI)
        return;

    PLUGIN_PRINTF("Patches", "%s\n", text.c_str());
}

void GameData::LoadGameData()
{
    std::string game_name = GetGameName();

    if (game_name == "unknown") {
        PRINT("Unknown game detected, not loading any game data.\n");
        return;
    }

    LoadSignatures(game_name);
    LoadOffsets(game_name);
    LoadPatches(game_name);
}

void* GameData::FetchRawSignature(std::string name)
{
    if (!ExistsSignature(name)) return nullptr;

    return signatures[name];
}

bool GameData::ExistsSignature(std::string name)
{
    return signatures.find(name) != signatures.end();
}

void GameData::LoadSignatures(std::string game_folder)
{
    auto files = Files::FetchFileNames("addons/swiftly/gamedata/" + game_folder);
    for (auto file : files) {
        if (!ends_with(file, "signatures.json")) continue;

        auto j = encoders::json::FromString(Files::Read(file), file);
        if (!j.IsObject()) {
            SignaturesError(string_format("'%s' needs to contain an object.\n", file.c_str()));
            continue;
        }

        for (auto it = j.MemberBegin(); it != j.MemberEnd(); ++it) {
            std::string name = it->name.GetString();

            if (signatures.find(name) != signatures.end()) {
                SignaturesError(string_format("The signature for '%s' has been already loaded.", name.c_str()));
                continue;
            }

            HAS_MEMBER(it->value, "lib", string_format("%s.lib", name.c_str()));
            HAS_MEMBER(it->value, "windows", string_format("%s.windows", name.c_str()));
            HAS_MEMBER(it->value, "linux", string_format("%s.linux", name.c_str()));

            IS_STRING(it->value, "lib", string_format("%s.lib", name.c_str()));
            IS_STRING(it->value, "windows", string_format("%s.windows", name.c_str()));
            IS_STRING(it->value, "linux", string_format("%s.linux", name.c_str()));

            std::string lib = it->value["lib"].GetString();
            std::string rawSig = it->value[WIN_LINUX("windows", "linux")].GetString();
            SignaturesError(string_format("Searching for \"%s\"...", rawSig.c_str()));

            DynLibUtils::CModule module = DetermineModuleByLibrary(lib);
            void* sig = nullptr;
            if (rawSig.at(0) == '@') sig = module.GetFunctionByName((rawSig.c_str() + 1)).RCast<void*>();
            else sig = module.FindPattern(rawSig).RCast<void*>();

            if (!sig)
            {
                SignaturesError(string_format("Couldn't find the signature for '%s' (Library '%s').", name.c_str(), lib.c_str()));
                continue;
            }

            SignaturesError(string_format("Found function '%s' (Library '%s') pointing at %p.", name.c_str(), lib.c_str(), sig));

            signatures.insert({ name, sig });
        }
    }
    SignaturesError(string_format("Succesfully loaded %02d signatures.", signatures.size()));
}

void GameData::LoadOffsets(std::string game_folder)
{
    auto files = Files::FetchFileNames("addons/swiftly/gamedata/" + game_folder);
    for (auto file : files) {
        if (!ends_with(file, "offsets.json")) continue;

        auto j = encoders::json::FromString(Files::Read(file), file);
        if (!j.IsObject()) {
            OffsetsError(string_format("'%s' needs to contain an object.\n", file.c_str()));
            continue;
        }

        for (auto it = j.MemberBegin(); it != j.MemberEnd(); ++it) {
            std::string name = it->name.GetString();

            if (offsets.find(name) != offsets.end()) {
                OffsetsError(string_format("The offsets for '%s' has been already loaded.", name.c_str()));
                continue;
            }

            HAS_MEMBER(it->value, "windows", string_format("%s.windows", name.c_str()))
                HAS_MEMBER(it->value, "linux", string_format("%s.linux", name.c_str()))

                IS_NUMBER(it->value, "windows", string_format("%s.windows", name.c_str()))
                IS_NUMBER(it->value, "linux", string_format("%s.linux", name.c_str()))

                offsets.insert({ name, it->value[WIN_LINUX("windows", "linux")].GetInt() });
        }
    }

    OffsetsError(string_format("Succesfully loaded %02d offsets.", offsets.size()));
}

int GameData::GetOffset(std::string name)
{
    if (offsets.find(name) == offsets.end()) return -1;
    return offsets[name];
}

int HexStringToUint8Array(const char* hexString, uint8_t* byteArray, size_t maxBytes)
{
    if (!hexString)
        return -1;

    size_t hexStringLength = strlen(hexString);
    size_t byteCount = hexStringLength / 4;

    if (hexStringLength % 4 != 0 || byteCount == 0 || byteCount > maxBytes)
        return -1;

    for (size_t i = 0; i < hexStringLength; i += 4)
    {
        if (sscanf(hexString + i, "\\x%2hhX", &byteArray[i / 4]) != 1)
            return -1;
    }

    byteArray[byteCount] = '\0';

    return byteCount;
}

byte* HexToByte(const char* src, size_t& length)
{
    if (!src || strlen(src) <= 0)
        return nullptr;

    length = strlen(src) / 4;
    uint8_t* dest = new uint8_t[length];
    int byteCount = HexStringToUint8Array(src, dest, length);
    if (byteCount <= 0)
        return nullptr;

    return (byte*)dest;
}

void GameData::LoadPatches(std::string game_folder)
{
    auto files = Files::FetchFileNames("addons/swiftly/gamedata/" + game_folder);
    for (auto file : files) {
        if (!ends_with(file, "patches.json")) continue;

        auto j = encoders::json::FromString(Files::Read(file), file);
        if (!j.IsObject()) {
            PatchesError(string_format("'%s' needs to contain an object.\n", file.c_str()));
            continue;
        }

        for (auto it = j.MemberBegin(); it != j.MemberEnd(); ++it) {
            std::string name = it->name.GetString();

            if (patches.find(name) != patches.end()) {
                PatchesError(string_format("The patch for '%s' has been already loaded.", name.c_str()));
                continue;
            }

            HAS_MEMBER(it->value, "signature", string_format("%s.signature", name.c_str()));
            HAS_MEMBER(it->value, "windows", string_format("%s.windows", name.c_str()));
            HAS_MEMBER(it->value, "linux", string_format("%s.linux", name.c_str()));

            IS_STRING(it->value, "signature", string_format("%s.signature", name.c_str()));
            IS_STRING(it->value, "windows", string_format("%s.windows", name.c_str()));
            IS_STRING(it->value, "linux", string_format("%s.linux", name.c_str()));

            std::string signature = it->value["signature"].GetString();
            if (!ExistsSignature(signature))
            {
                PatchesError(string_format("%s: Signature '%s' does not exists in signatures file.\n", name.c_str(), signature.c_str()));
                continue;
            }

            patches.insert({ name, std::string(it->value[WIN_LINUX("windows", "linux")].GetString()) });
            patches_signatures.insert({ name, signature });
        }
    }

    PatchesError(string_format("Succesfully loaded %02d patches.", patches.size()));
}

void GameData::PerformPatch(std::string patch_name)
{
    if (patches.find(patch_name) == patches.end())
    {
        PLUGIN_PRINTF("Patch", "Invalid patch name: \"%s\".\n", patch_name.c_str());
        return;
    }

    if (patches.at(patch_name) == "") return;

    void* patchAddress = FetchRawSignature(patches_signatures[patch_name]);

    size_t iLength = 0;
    byte* patch = HexToByte(("\\x" + replace(patches.at(patch_name), " ", "\\x")).c_str(), iLength);

    Plat_WriteMemory(patchAddress, patch, iLength);
    PLUGIN_PRINTF("Patch", "Patched \"%s\" using signature \"%s\".\n", patch_name.c_str(), patches_signatures[patch_name].c_str());
}

void GameData::PerformPatches()
{
    if (g_Config.HasKey("core.patches_to_perform"))
    {
        std::vector<std::string> patchesToPerform = explode(g_Config.FetchValue<std::string>("core.patches_to_perform"), " ");

        uint32_t patchesPerformed = 0;
        for (std::string& patchName : patchesToPerform)
        {
            if (patchName == "")
                continue;

            PerformPatch(patchName);
            ++patchesPerformed;
        }

        PLUGIN_PRINTF("Patch", "Patches performed: %02d.\n", patchesPerformed);
    }
}

EXT_API int swiftly_GetOffset(const char* name)
{
    return g_GameData.GetOffset(name);
}

EXT_API void* swiftly_GetSignature(const char* name)
{
    return g_GameData.FetchRawSignature(name);
}

EXT_API void* swiftly_AccessVTable(const char* module, const char* vTableName)
{
    return DetermineModuleByLibrary(module).GetVirtualTableByName(vTableName).RCast<void*>();
}