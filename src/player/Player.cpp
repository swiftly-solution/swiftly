#include "Player.h"
#include "../sig/Signatures.h"
#include <metamod_util.h>

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

    if (team == CS_TEAM_SPECTATOR)
        CALL_VIRTUAL(void, g_Offsets->GetOffset("ChangeTeam"), this, team);
    else
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
    {
        PRINTF("Player::SendMsg", "No controller present.\nSteamID: %llu", this->GetSteamID());
        return;
    }

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

    g_Signatures->FetchSignature<ClientPrint>("ClientPrint")(controller, dest, reinterpret_cast<const char *>(buffer), nullptr, nullptr, nullptr, nullptr);
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