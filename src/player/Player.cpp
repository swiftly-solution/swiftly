#include "Player.h"

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