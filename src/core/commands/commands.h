#ifndef _core_commands_commands_h
#define _core_commands_commands_h

#include <string>
#include <TextTable.h>

#include <tier1/convar.h>

#include "../../entrypoint.h"
#include "../../common.h"
#include "../../engine/convars/convars.h"
#include "../../server/configuration/Configuration.h"
#include "../../utils/utils.h"
#include "../../player/playermanager/PlayerManager.h"
#include "../../server/translations/Translations.h"
#include "../../plugins/PluginManager.h"
#include "../../tools/resourcemonitor/ResourceMonitor.h"
#include "../../server/commands/CommandsManager.h"
#include "../../extensions/ExtensionManager.h"
#include "../../server/chat/Chat.h"

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
void SwiftlyVersion(CPlayerSlot slot);

#endif