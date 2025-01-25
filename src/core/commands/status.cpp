#include "commands.h"

void SwiftlyStatus(CPlayerSlot slot)
{
    TextTable statusTable('-', '|', '+');

    statusTable.add(" playerid ");
    statusTable.add(" name ");
    statusTable.add(" steamid ");
    statusTable.add(" time ");
    statusTable.add(" state ");
    statusTable.endOfRow();

    for (uint16 i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player* player = g_playerManager->GetPlayer(i);
        if (!player)
            continue;

        CBasePlayerController* controller = player->GetController();
        if (!controller)
            continue;

        statusTable.add(string_format(" #%d ", player->GetSlot().Get()));
        statusTable.add(string_format(" %s ", player->GetName()));
        statusTable.add(string_format(" %s ", player->IsFakeClient() ? "BOT" : std::to_string(controller->m_steamID()).c_str()));
        statusTable.add(string_format(" %s ", seconds_to_time(player->GetConnectedTime()).c_str()));
        statusTable.add(string_format(" %s ", "Active"));
        statusTable.endOfRow();
    }

    auto PrintTT = [slot](std::string category, TextTable table) -> void
        {
            std::stringstream outputTable;
            outputTable << table;
            std::vector<std::string> rows = explode(outputTable.str(), "\n");
            for (size_t i = 0; i < rows.size() - 1; i++)
                PrintToClientOrConsole(slot, category, "%s\n", rows[i].c_str());
        };

    PrintTT("Status", statusTable);

    PrintToClientOrConsole(slot, "Status", "end of status\n");
}