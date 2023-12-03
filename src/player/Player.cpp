#include "Player.h"
#include "../sig/Signatures.h"
#include <metamod_util.h>
#include <algorithm>

std::string replace(std::string str, const std::string from, const std::string to);

std::map<std::string, std::string> colors = {
    {"{DEFAULT}", "\x01"},
    {"{WHITE}", "\x01"},
    {"{DARKRED}", "\x02"},
    {"{LIGHTPURPLE}", "\x03"},
    {"{GREEN}", "\x04"},
    {"{OLIVE}", "\x05"},
    {"{LIME}", "\x06"},
    {"{RED}", "\x07"},
    {"{GRAY}", "\x08"},
    {"{GREY}", "\x08"},
    {"{LIGHTYELLOW}", "\x09"},
    {"{YELLOW}", "\x09"},
    {"{SILVER}", "\x0A"},
    {"{BLUEGREY}", "\x0A"},
    {"{LIGHTBLUE}", "\x0B"},
    {"{BLUE}", "\x0B"},
    {"{DARKBLUE}", "\x0C"},
    {"{PURPLE}", "\x0E"},
    {"{MAGENTA}", "\x0E"},
    {"{LIGHTRED}", "\x0F"},
    {"{GOLD}", "\x10"},
    {"{ORANGE}", "\x10"},
};

std::string str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c)
                   { return std::tolower(c); });
    return s;
}

CBasePlayerController *Player::GetController()
{
    if (this->GetEHandlerIdx() == -1)
        return nullptr;

    return (CBasePlayerController *)g_pEntitySystem->GetBaseEntity(CEntityIndex(this->GetEHandlerIdx()));
}

CBasePlayerPawn *Player::GetPawn()
{
    CBasePlayerController *controller = this->GetController();
    if (controller == nullptr)
        return nullptr;

    return controller->m_hPawn();
}

CCSPlayerController *Player::GetPlayerController()
{
    if (this->GetEHandlerIdx() == -1)
        return nullptr;

    return (CCSPlayerController *)g_pEntitySystem->GetBaseEntity(CEntityIndex(this->GetEHandlerIdx()));
}

CCSPlayerPawn *Player::GetPlayerPawn()
{
    CCSPlayerController *controller = this->GetPlayerController();
    if (controller == nullptr)
        return nullptr;

    return controller->m_hPlayerPawn().Get();
}

CCSPlayerPawnBase *Player::GetPlayerBasePawn()
{
    CCSPlayerPawn *pawn = this->GetPlayerPawn();
    if (pawn == nullptr)
        return nullptr;

    return (CCSPlayerPawnBase *)pawn;
}

void Player::SwitchTeam(int team)
{
    CCSPlayerController *playerController = this->GetPlayerController();
    if (!playerController)
        return;

    g_Signatures->FetchSignature<CCSPlayerController_SwitchTeam>("CCSPlayerController_SwitchTeam")(playerController, team);
}

void Player::Authenticate()
{
    this->isAuthenticated = true;
}

const char *Player::GetName()
{
    CBasePlayerController *controller = this->GetController();
    if (!controller)
        return this->name;

    return controller->m_iszPlayerName();
}

uint64 Player::GetSteamID()
{
    if (this->IsFakeClient())
        return 0;

    CBasePlayerController *controller = this->GetController();
    if (!controller)
        return this->xuid;

    return controller->m_steamID();
}

void Player::SendMsg(int dest, const char *msg, ...)
{
    CBasePlayerController *controller = this->GetController();
    if (!controller)
        return;

    va_list args;
    char buffer[1024];
    va_start(args, msg);

    size_t len = vsnprintf(buffer, sizeof(buffer), msg, args);
    if (len >= sizeof(buffer))
    {
        len = sizeof(buffer) - 1;
        buffer[len] = '\0';
    }
    va_end(args);

    std::string message(buffer);
    bool startsWithColor = (message.at(0) == '{');

    for (auto it = colors.begin(); it != colors.end(); ++it)
    {
        message = replace(message, it->first, it->second);
        message = replace(message, str_tolower(it->first), it->second);
    }

    if (startsWithColor)
        message = " " + message;

    g_Signatures->FetchSignature<ClientPrint>("ClientPrint")(controller, dest, message.c_str(), nullptr, nullptr, nullptr, nullptr);
}

std::any Player::GetInternalVar(std::string name)
{
    if (this->internalVars.find(name) == this->internalVars.end())
        return 0;

    return this->internalVars.at(name);
}

void Player::SetInternalVar(std::string name, std::any value)
{
    if (this->internalVars.find(name) == this->internalVars.end())
        this->internalVars.insert(std::make_pair(name, value));
    else
        this->internalVars[name] = value;
}