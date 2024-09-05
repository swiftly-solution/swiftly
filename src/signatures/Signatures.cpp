#include "Signatures.h"
#include "../common.h"
#include "../files/Files.h"

#include "../utils/utils.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

#include "../../vendor/dynlib/module.h"

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

bool Signatures::Exists(std::string name)
{
    return (this->signatures.find(name) != this->signatures.end());
}

void Signatures::LoadSignatures()
{
    rapidjson::Document signaturesFile;
    signaturesFile.Parse(Files::Read("addons/swiftly/gamedata/signatures.json").c_str());
    if (signaturesFile.HasParseError())
        return SignaturesError(string_format("A parsing error has been detected.\nError (offset %u): %s", (unsigned)signaturesFile.GetErrorOffset(), GetParseError_En(signaturesFile.GetParseError())));

    if (signaturesFile.IsArray())
        return SignaturesError("Signatures file cannot be an array.");

    for (auto it = signaturesFile.MemberBegin(); it != signaturesFile.MemberEnd(); ++it)
    {
        std::string name = it->name.GetString();

        HAS_MEMBER(it->value, "lib", string_format("%s.lib", name));
        HAS_MEMBER(it->value, "windows", string_format("%s.windows", name));
        HAS_MEMBER(it->value, "linux", string_format("%s.linux", name));

        IS_STRING(it->value, "lib", string_format("%s.lib", name));
        IS_STRING(it->value, "windows", string_format("%s.windows", name));
        IS_STRING(it->value, "linux", string_format("%s.linux", name));

        const char* lib = it->value["lib"].GetString();
        std::string rawSig = it->value[WIN_LINUX("windows", "linux")].GetString();
        SignaturesError(string_format("Searching for \"%s\"...", rawSig.c_str()));

        DynLibUtils::CModule module = DetermineModuleByLibrary(lib);
        void* sig = nullptr;
        if (rawSig.at(0) == '@') sig = module.GetFunctionByName((rawSig.c_str() + 1)).RCast<void*>();
        else sig = module.FindPattern(rawSig).RCast<void*>();

        if (!sig)
        {
            SignaturesError(string_format("Couldn't find the signature for '%s' (Library '%s').", name.c_str(), lib));
            continue;
        }

        SignaturesError(string_format("Found function '%s' (Library '%s') pointing at %p.", name.c_str(), lib, sig));

        this->signatures.insert(std::make_pair(name, sig));
    }
}