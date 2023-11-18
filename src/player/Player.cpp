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
    return this->GetController()->m_hPawn();
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

    g_Signatures->FetchSignature<ClientPrint>("ClientPrint")(controller, dest, reinterpret_cast<const char *>(buffer), nullptr, nullptr, nullptr, nullptr);
}

const char *Player::GetClanTag()
{
    CBasePlayerController *controller = this->GetController();
    if (!controller)
        return "";

    return controller->m_szClan().String();
}

void Player::SetClanTag(const char *clantag)
{
    CBasePlayerController *controller = this->GetController();
    if (!controller)
        return;

    controller->m_szClan() = CUtlSymbolLarge(clantag);
}