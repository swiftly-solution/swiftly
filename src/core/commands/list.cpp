#include "commands.h"

#include <server/player/manager.h>

void SwiftlyList(CPlayerSlot slot)
{
    PrintToClientOrConsole(slot, "List", "Connected players: %02d/%02d\n", g_playerManager.GetPlayers(), engine->GetServerGlobals()->maxClients);
    uint16 idx = 0;
    for (uint16 i = 0; i < g_playerManager.GetPlayerCap(); i++)
    {
        Player* player = g_playerManager.GetPlayer(i);
        if (!player)
            continue;

        ++idx;
        PrintToClientOrConsole(slot, "List", "%d. %s%s (%llu)\n", idx, player->GetName(), player->IsFakeClient() ? " (BOT)" : "", player->GetSteamID());
    }
}