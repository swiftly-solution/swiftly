#include "commands.h"
#include <server/translations/translations.h>

void SwiftlyTranslationManagerHelp(CPlayerSlot slot)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Translation Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly translations <command>\n");
    PrintToClientOrConsole(slot, "Commands", " reload    - Reloads the translations.\n");
}

void SwiftlyTranslationReload(CPlayerSlot slot)
{
    g_translations.LoadTranslations();
    PrintToClientOrConsole(slot, "Translations", "All translations have been succesfully reloaded.\n");
}

void SwiftlyTranslationManager(CPlayerSlot slot, const char* subcmd)
{
    if (slot.Get() != -1)
        return;

    std::string sbcmd = subcmd;
    if (sbcmd.size() == 0)
    {
        SwiftlyTranslationManagerHelp(slot);
        return;
    }

    if (sbcmd == "reload")
        SwiftlyTranslationReload(slot);
    else
        SwiftlyTranslationManagerHelp(slot);
}