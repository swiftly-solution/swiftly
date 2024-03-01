#include "swiftly_scripting_utils.h"

void print(const char *str, ...);

int GetPlayerId(const char *str, bool matchbots)
{
    int target = StringToInt(str);
    if (target != -1)
        return target;

    std::string match = ToLower(str);
    for (uint16_t i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player *player = g_playerManager->GetPlayer(i);
        if (player == nullptr)
            continue;
        if (!matchbots && player->IsFakeClient())
            continue;

        if (std::to_string(player->GetSteamID()) == match || std::string(ToLower(player->GetName())).find(match) != std::string::npos)
            return i;
    }
    return -1;
}

void CreateThread(std::function<void()> fn)
{
    std::thread(fn).detach();
}