#include "Signatures.h"
#include "../common.h"
#include "../files/Files.h"

#include "../utils/utils.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

#include <module.h>
#include "../utils/module.h"

#ifdef _WIN32
#define ROOTBIN "/bin/win64/"
#define GAMEBIN "/csgo/bin/win64/"
#else
#define ROOTBIN "/bin/linuxsteamrt64/"
#define GAMEBIN "/csgo/bin/linuxsteamrt64/"
#endif

#define HAS_MEMBER(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                   \
    if (!DOCUMENT.HasMember(MEMBER_NAME))                                                \
    {                                                                                    \
        SignaturesError(string_format("The field \"%s\" doesn't exists.", MEMBER_PATH)); \
        continue;                                                                        \
    }

#define IS_STRING(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                     \
    if (!DOCUMENT[MEMBER_NAME].IsString())                                                \
    {                                                                                     \
        SignaturesError(string_format("The field \"%s\" is not a string.", MEMBER_PATH)); \
        continue;                                                                         \
    }

int HexStringToUint8Array(const char *hexString, uint8_t *byteArray, size_t maxBytes)
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

byte *HexToByte(const char *src, size_t &length)
{
    if (!src || strlen(src) <= 0)
        return nullptr;

    length = strlen(src) / 4;
    uint8_t *dest = new uint8_t[length];
    int byteCount = HexStringToUint8Array(src, dest, length);
    if (byteCount <= 0)
        return nullptr;
    return (byte *)dest;
}

void *FindSignature(const char *moduleName, const char *bytes)
{
    if (moduleName == nullptr || bytes == nullptr)
        return nullptr;

    CModule *mdl = new CModule(std::string(moduleName) == "server" ? GAMEBIN : ROOTBIN, moduleName);
    size_t iLength = 0;
    if (bytes[0] == '@')
    {
        return dlsym(mdl->m_hModule, bytes + 1);
    }
    else
    {
        byte *pSignature = HexToByte(bytes, iLength);
        if (!pSignature)
            return nullptr;
        return mdl->FindSignature(pSignature, iLength);
    }
}

void SignaturesError(std::string text)
{
    if (!g_SMAPI)
        return;

    PLUGIN_PRINTF("Signatures", "%s\n", text.c_str());
}

bool Signatures::Exists(std::string name)
{
    return (this->signatures.find(name) != this->signatures.end());
}

void Signatures::LoadSignatures()
{
    rapidjson::Document signaturesFile;
    signaturesFile.Parse(Files::Read("addons/swiftly/gamedata/signatures.json").c_str());
    if (signaturesFile.HasParseError())
        return SignaturesError(string_format("A parsing error has been detected.\nError (offset %u): %s\n", (unsigned)signaturesFile.GetErrorOffset(), GetParseError_En(signaturesFile.GetParseError())));

    if (signaturesFile.IsArray())
        return SignaturesError("Signatures file cannot be an array.");

    for (auto it = signaturesFile.MemberBegin(); it != signaturesFile.MemberEnd(); ++it)
    {
        std::string name = it->name.GetString();

        HAS_MEMBER(it->value, "lib", string_format("%s.lib", name))
        HAS_MEMBER(it->value, "windows", string_format("%s.windows", name))
        HAS_MEMBER(it->value, "linux", string_format("%s.linux", name))

        IS_STRING(it->value, "lib", string_format("%s.lib", name))
        IS_STRING(it->value, "windows", string_format("%s.windows", name))
        IS_STRING(it->value, "linux", string_format("%s.linux", name))

        const char *lib = it->value["lib"].GetString();
        std::string rawSig = it->value[WIN_LINUX("windows", "linux")].GetString();
        SignaturesError(string_format("Searching for \"%s\"...\n", rawSig.c_str()));

        void *sig = nullptr;
        if (rawSig.find("?") == std::string::npos)
        {
            std::string finalSig = (rawSig.at(0) == '@') ? rawSig : ("\\x" + replace(rawSig, " ", "\\x"));
            sig = FindSignature(lib, finalSig.c_str());
            if (sig == nullptr)
            {
                SignaturesError(string_format("Couldn't find the signature for '%s' (Library '%s').", name.c_str(), lib));
                continue;
            }
            SignaturesError(string_format("Found function '%s' (Library '%s') pointing at %p.", name.c_str(), lib, sig));
        }
        else
        {
            DynLibUtils::CModule module(std::string(lib) == "server" ? server : nullptr);
            DynLibUtils::CMemory sg = module.FindPattern(rawSig);
            if (!sg)
            {
                SignaturesError(string_format("Couldn't find the signature for '%s' (Library '%s').", name.c_str(), lib));
                continue;
            }
            sig = sg.RCast<void *>();
            SignaturesError(string_format("Found function '%s' (Library '%s') pointing at %p.", name.c_str(), lib, sig));
        }
        SignaturesError(string_format("Found function '%s' (Library '%s') pointing at %p.", name.c_str(), lib, sig));

        this->signatures.insert(std::make_pair(name, sig));
    }
}