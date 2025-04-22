#include "commands.h"

#include <texttable/TextTable.h>
#include <server/player/manager.h>
#include <sstream>

void SwiftlyStatus(CPlayerSlot slot)
{
    TextTable statusTable('-', '|', '+');

    statusTable.add(" playerid ");
    statusTable.add(" name ");
    statusTable.add(" steamid ");
    statusTable.add(" time ");
    statusTable.add(" state ");
    statusTable.endOfRow();

    for (uint16 i = 0; i < g_playerManager.GetPlayerCap(); i++)
    {
        auto player = g_playerManager.GetPlayer(i);
        if (!player)
            continue;

        statusTable.add(string_format(" #%d ", player->GetSlot()));
        statusTable.add(string_format(" %s ", player->GetName()));
        statusTable.add(string_format(" %s ", player->IsFakeClient() ? "BOT" : std::to_string(player->GetSteamID()).c_str()));
        statusTable.add(string_format(" %s ", seconds_to_time(player->GetConnectedTime()).c_str()));
        statusTable.add(string_format(" %s ", "Active"));
        statusTable.endOfRow();
    }

    auto PrintTT = [slot](std::string category, TextTable table) -> void
        {
            std::stringstream outputTable;
            outputTable << table;
            std::vector<std::string> rows = explode(outputTable.str(), "\n");
            for (int i = 0; i < rows.size() - 1; i++)
                PrintToClientOrConsole(slot, category, "%s\n", rows[i].c_str());
        };

    PrintTT("Status", statusTable);

    PrintToClientOrConsole(slot, "Status", "end of status\n");
}