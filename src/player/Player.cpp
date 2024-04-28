#include "Player.h"
#include "../sig/Signatures.h"
#include <metamod_util.h>
#include <algorithm>
#include "../events/gameevents.h"
#include "../hooks/Hooks.h"
#include "../menus/Menus.h"
#include "networkbasetypes.pb.h"
#include <thread>
#include "../sdk/entity/CRecipientFilters.h"

typedef IGameEventListener2 *(*GetLegacyGameEventListener)(CPlayerSlot slot);

typedef void (*CCSPlayerController_SwitchTeam)(CCSPlayerController *pController, unsigned int team);

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

std::string ProcessColor(std::string str, int team = CS_TEAM_CT)
{
    str = replace(str, "{TEAMCOLOR}", team == CS_TEAM_CT ? "{LIGHTBLUE}" : "{GOLD}");
    str = replace(str, "{teamcolor}", team == CS_TEAM_CT ? "{lightblue}" : "{gold}");
    for (auto it = colors.begin(); it != colors.end(); ++it)
    {
        str = replace(str, it->first, it->second);
        str = replace(str, str_tolower(it->first), it->second);
    }
    return str;
}

CBasePlayerController *Player::GetController()
{
    return (CBasePlayerController *)g_pEntitySystem->GetBaseEntity(CEntityIndex(this->GetSlot()->Get() + 1));
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
    return (CCSPlayerController *)g_pEntitySystem->GetBaseEntity(CEntityIndex(this->GetSlot()->Get() + 1));
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
        CALL_VIRTUAL(void, g_Offsets->GetOffset("ChangeTeam"), playerController, team);
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

    return reinterpret_cast<char *>(controller->m_iszPlayerName());
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

    if (dest == HUD_PRINTTALK || dest == HUD_PRINTNOTIFY)
    {
        va_list args;
        char buffer[4096];
        va_start(args, msg);

        size_t len = vsnprintf(buffer, sizeof(buffer), msg, args);
        if (len >= sizeof(buffer))
        {
            len = sizeof(buffer) - 1;
            buffer[len] = '\0';
        }
        va_end(args);

        std::string message(buffer);
        if (message.size() != 0)
        {
            if (ends_with(message, "\n"))
                message.pop_back();
            message += "\x01";
            bool startsWithColor = (message.at(0) == '{');

            message = ProcessColor(message, controller->m_iTeamNum());

            if (startsWithColor)
                message = " " + message;
        }

        controller->SendMsg(dest, message.c_str());
    }
    else if (dest == HUD_PRINTCENTER)
    {
        this->centerMessageEndTime = GetTime() + 5000;
        this->centerMessageText = msg;
    }
    else if (dest == HUD_PRINTCONSOLE)
    {
        if (!g_SMAPI)
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
        if (message.size() != 0)
        {
            for (auto it = colors.begin(); it != colors.end(); ++it)
            {
                message = replace(message, it->first, "");
                message = replace(message, str_tolower(it->first), "");
            }
            engine->ClientPrintf(*this->GetSlot(), message.c_str());
        }
    }
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

Vector Player::GetCoords()
{
    CCSPlayerPawn *pawn = this->GetPlayerPawn();
    if (!pawn)
    {
        Vector vec(0.0, 0.0, 0.0);
        return vec;
    }
    return pawn->m_CBodyComponent->m_pSceneNode->m_vecAbsOrigin();
}

void Player::SetCoords(float x, float y, float z)
{
    CBasePlayerPawn *pawn = this->GetPawn();
    if (!pawn)
        return;

    Vector vec(x, y, z);
    pawn->Teleport(&vec, nullptr, nullptr);
}

CBasePlayerWeapon *Player::GetPlayerWeaponFromID(uint32 weaponid)
{
    CCSPlayerPawn *pawn = this->GetPlayerPawn();
    if (!pawn)
        return nullptr;

    CPlayer_WeaponServices *weaponServices = pawn->m_pWeaponServices();
    if (!weaponServices)
        return nullptr;

    CUtlVector<CHandle<CBasePlayerWeapon>> *weapons = weaponServices->m_hMyWeapons();
    if (!weapons)
        return nullptr;

    FOR_EACH_VEC(*weapons, i)
    {
        CHandle<CBasePlayerWeapon> &weaponHandle = (*weapons)[i];
        if (!weaponHandle.IsValid())
            continue;

        CBasePlayerWeapon *weapon = weaponHandle.Get();
        if (!weapon)
            continue;

        if (weapon->m_AttributeManager().m_Item().m_iItemDefinitionIndex() == weaponid)
            return weapon;
    }

    return nullptr;
}

CBasePlayerWeapon *Player::GetPlayerWeaponFromSlot(gear_slot_t slot)
{
    CCSPlayerPawn *pawn = this->GetPlayerPawn();
    if (!pawn)
        return nullptr;

    CPlayer_WeaponServices *weaponServices = pawn->m_pWeaponServices();
    if (!weaponServices)
        return nullptr;

    if (slot == GEAR_SLOT_CURRENT_WEAPON)
        return weaponServices->m_hActiveWeapon();

    CUtlVector<CHandle<CBasePlayerWeapon>> *weapons = weaponServices->m_hMyWeapons();
    if (!weapons)
        return nullptr;

    FOR_EACH_VEC(*weapons, i)
    {
        CHandle<CBasePlayerWeapon> &weaponHandle = (*weapons)[i];
        if (!weaponHandle.IsValid())
            continue;

        CBasePlayerWeapon *weapon = weaponHandle.Get();
        if (!weapon)
            continue;

        CCSWeaponBaseVData *vData = weapon->GetWeaponVData();
        if (!vData)
            continue;

        if (vData->m_GearSlot() == slot)
            return weapon;
    }

    return nullptr;
}

const std::vector<std::string> key_buttons = {
    "mouse1",
    "space",
    "ctrl",
    "w",
    "s",
    "e",
    "esc",
    "a",
    "d",
    "a",
    "d",
    "mouse2",
    "unknown_key_run",
    "r",
    "alt",
    "alt",
    "shift",
    "unknown_key_speed",
    "shift",
    "unknown_key_hudzoom",
    "unknown_key_weapon1",
    "unknown_key_weapon2",
    "unknown_key_bullrush",
    "unknown_key_grenade1",
    "unknown_key_grenade2",
    "unknown_key_lookspin",
    "unknown_key_26",
    "unknown_key_27",
    "unknown_key_28",
    "unknown_key_29",
    "unknown_key_30",
    "tab",
};

void Player::SetButtons(uint64_t new_buttons)
{
    for (uint16_t i = 0; i < key_buttons.size(); i++)
    {
        if (this->IsButtonPressed((1 << i)) && (new_buttons & (1 << i)) == 0)
            hooks::emit(OnClientKeyStateChange(this->GetSlot(), key_buttons[i].c_str(), false));
        else if (!this->IsButtonPressed((1 << i)) && (new_buttons & (1 << i)) != 0)
            hooks::emit(OnClientKeyStateChange(this->GetSlot(), key_buttons[i].c_str(), true));
    }

    this->buttons = new_buttons;
}

uint64_t Player::GetButtons()
{
    return this->buttons;
}

bool Player::IsButtonPressed(uint64_t but)
{
    return ((this->buttons & but) != 0);
}

void Player::ShowMenu(std::string menuid)
{
    if (this->menu != nullptr)
        return;

    Menu *m = g_menus->FetchMenu(menuid);
    if (m == nullptr)
        return;

    this->menu = m;
    this->page = 1;
    this->selected = 0;

    this->RenderMenu();
}

void Player::RenderCenterText()
{
    if (this->centerMessageEndTime != 0)
    {
        if (this->centerMessageEndTime >= GetTime())
        {
            IGameEvent *pEvent = g_gameEventManager->CreateEvent("show_survival_respawn_status", true);
            if (pEvent)
            {
                pEvent->SetString("loc_token", this->centerMessageText.c_str());
                pEvent->SetUint64("duration", 1);
                pEvent->SetInt("userid", this->GetController()->GetEntityIndex().Get() - 1);

                IGameEventListener2 *playerListener = g_Signatures->FetchSignature<GetLegacyGameEventListener>("LegacyGameEventListener")(*this->GetSlot());

                playerListener->FireGameEvent(pEvent);
                g_gameEventManager->FreeEvent(pEvent);
            }
        }
        else
            this->centerMessageEndTime = 0;
    }
}

void Player::RenderMenu()
{
    if (this->menu == nullptr)
        return;

    if (this->centerMessageEndTime > 0)
        this->centerMessageEndTime = 0;

    IGameEvent *pEvent = g_gameEventManager->CreateEvent("show_survival_respawn_status", true);
    if (pEvent)
    {
        pEvent->SetString("loc_token", this->menu->GenerateItems(this->page, this->selected).c_str());
        pEvent->SetUint64("duration", 10);
        pEvent->SetInt("userid", this->GetController()->GetEntityIndex().Get() - 1);

        IGameEventListener2 *playerListener = g_Signatures->FetchSignature<GetLegacyGameEventListener>("LegacyGameEventListener")(*this->GetSlot());

        playerListener->FireGameEvent(pEvent);
        g_gameEventManager->FreeEvent(pEvent);
    }
}

void Player::HideMenu()
{
    if (this->menu == nullptr)
        return;

    this->page = 0;
    this->selected = 0;
    this->menu = nullptr;

    IGameEvent *pEvent = g_gameEventManager->CreateEvent("show_survival_respawn_status", true);
    if (pEvent)
    {
        pEvent->SetString("loc_token", "Exiting...");
        pEvent->SetUint64("duration", 1);
        pEvent->SetInt("userid", this->GetController()->GetEntityIndex().Get() - 1);

        IGameEventListener2 *playerListener = g_Signatures->FetchSignature<GetLegacyGameEventListener>("LegacyGameEventListener")(*this->GetSlot());

        playerListener->FireGameEvent(pEvent);
        g_gameEventManager->FreeEvent(pEvent);
    }
}

ConVar *FetchCVar(const char *name);

void Player::SetClientConvar(std::string cmd, std::string val)
{
    ConVar *cv = FetchCVar(cmd.c_str());
    if (!cv)
        return;

    INetworkSerializable *netmsg = g_pNetworkMessages->FindNetworkMessagePartial("SetConVar");
    CNETMsg_SetConVar *msg = new CNETMsg_SetConVar;
    CMsg_CVars_CVar *cvar = msg->mutable_convars()->add_cvars();
    cvar->set_name(cv->m_pszName);
    cvar->set_value(val.c_str());

    CSingleRecipientFilter filter(this->GetSlot()->Get());
    g_pGameEventSystem->PostEventAbstract(0, false, &filter, netmsg, msg, 0);
}