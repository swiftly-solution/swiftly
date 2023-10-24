#include "../inc/BasicComponent.h"
#include "../../../hooks/Hooks.h"
#include "../../../common.h"
#include "../../../player/PlayerManager.h"

void BasicComponent::LoadComponent()
{
}

template <typename... Args>
std::string string_format(const std::string &format, Args... args)
{
    int size_s = snprintf(nullptr, 0, format.c_str(), args...) + 1; // Extra space for '\0'
    if (size_s <= 0)
        throw std::runtime_error("Error during formatting.");

    size_t size = static_cast<size_t>(size_s);
    std::unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args...);
    return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

std::string seconds_to_time(unsigned int number)
{
    return string_format("%02d:%02d:%02d", int(number / 3600), int((number % 3600) / 60), int((number % 3600) % 60));
}

CON_COMMAND_F(sw_status, "Shows the connection status to the server.", FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND)
{
    CPlayerSlot *slot = &context.GetPlayerSlot();

    auto PrintToClientOrConsole = [slot](std::string category, std::string message, auto... args)
    {
        if (slot->Get() == -1)
            PRINTF(category, message, args...);
        else
            CLIENT_PRINTF(*slot, category, message, args...);
    };

    PrintToClientOrConsole("Commands - Status", "userid\tname\tsteamid\t\ttime\t\tstate\n");

    for (uint16 i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player *player = g_playerManager->GetPlayer(i);
        if (!player)
            continue;

        CBasePlayerController *controller = player->GetController();
        if (!controller)
            continue;

        if (player->IsFakeClient())
            PrintToClientOrConsole("Commands - Status", "#%d\t%s\t%s\t%s\t%s\n",
                                   i + 1, controller->m_iszPlayerName(), "BOT\t", seconds_to_time(player->GetConnectedTime()), player->GetEHandlerIdx() == -1 ? "Initializing" : "Active");
        else
            PrintToClientOrConsole("Commands - Status", "#%d\t%s\t%llu\t%s\t%s\n",
                                   i + 1, controller->m_iszPlayerName(), controller->m_steamID(), seconds_to_time(player->GetConnectedTime()), player->GetEHandlerIdx() == -1 ? "Initializing" : "Active");
    }
    PrintToClientOrConsole("Commands - Status", "end of status\n");
}

CON_COMMAND_F(sw_list, "Shows the players connected on the server, including the number of those.", FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND)
{
    CPlayerSlot *slot = &context.GetPlayerSlot();

    auto PrintToClientOrConsole = [slot](std::string category, std::string message, auto... args)
    {
        if (slot->Get() == -1)
            PRINTF(category, message, args...);
        else
            CLIENT_PRINTF(*slot, category, message, args...);
    };

    PrintToClientOrConsole("Commands - List", "Connected players: %02d/%02d\n", g_playerManager->GetPlayers(), engine->GetServerGlobals()->maxClients);
    uint16 idx = 0;
    for (uint16 i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player *player = g_playerManager->GetPlayer(i);
        if (!player)
            continue;

        CBasePlayerController *controller = player->GetController();
        if (!controller)
            continue;

        ++idx;
        PrintToClientOrConsole("Commands - List", "%d. %s%s (%llu)\n", idx, controller->m_iszPlayerName(), player->IsFakeClient() ? " (BOT)" : "", controller->m_steamID());
    }
}