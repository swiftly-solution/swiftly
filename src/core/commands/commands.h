#ifndef _core_commands_h
#define _core_commands_h

#include <core/entrypoint.h>
#include <public/tier1/strtools.h>
#include <utils/utils.h>
#include <utils/common.h>

//////////////////////////////////////////////////////////////
/////////////////           Utilities          //////////////
////////////////////////////////////////////////////////////

#ifndef GITHUB_SHA
#define GITHUB_SHA "LOCAL"
#endif

const char* GetCppVersion();
std::string seconds_to_time(unsigned int number);

template <typename... T>
void PrintToClientOrConsole(CPlayerSlot slot, std::string category, std::string message, T... args)
{
    if (slot.Get() == -1)
        PLUGIN_PRINTF(category, message, args...);
    else
        CLIENT_PRINTF(slot, category, message, args...);
}

//////////////////////////////////////////////////////////////
/////////////////           Functions          //////////////
////////////////////////////////////////////////////////////

void SwiftlyChatManager(CPlayerSlot slot, const char* subcmd);
void ShowSwiftlyCommands(CPlayerSlot slot, int page);
void SwiftlyConfigurationManager(CPlayerSlot slot, const char* subcmd);
void ShowSwiftlyCredits(CPlayerSlot slot);
void SwiftlyConvarsManager(CPlayerSlot slot, int page);
void SwiftlyExtensionManager(CPlayerSlot slot, const char* subcmd);
void ShowSwiftlyCommandHelp(CPlayerSlot slot);
void SwiftlyList(CPlayerSlot slot);
void SwiftlyPluginManager(CPlayerSlot slot, const char* subcmd, const char* plugin_name);
void SwiftlyResourceMonitorManager(CPlayerSlot slot, const char* subcmd, const char* subcmd2);
void SwiftlyStatus(CPlayerSlot slot);
void SwiftlyTranslationManager(CPlayerSlot slot, const char* subcmd);
void SwiftlyGCManager(CPlayerSlot slot, const char* subcmd, const char* subcmd2);
void SwiftlyVersion(CPlayerSlot slot);

#endif