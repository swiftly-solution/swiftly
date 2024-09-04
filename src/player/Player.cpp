#include "Player.h"

#include "../entrypoint.h"
#include "../common.h"
#include "../utils/utils.h"
#include "../menus/MenuManager.h"
#include "../commands/CommandsManager.h"
#include "../configuration/Configuration.h"

#include "networkbasetypes.pb.h"
#include "../sdk/entity/CRecipientFilters.h"

#include <bitset>

#include "../convars/convars.h"

typedef IGameEventListener2* (*GetLegacyGameEventListener)(CPlayerSlot slot);

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

std::string ProcessColor(std::string str, int team = CS_TEAM_CT)
{
    str = replace(str, "{TEAMCOLOR}", team == CS_TEAM_CT ? "{LIGHTBLUE}" : (team == CS_TEAM_T ? "{GOLD}" : "{GREY}"));
    str = replace(str, "{teamcolor}", team == CS_TEAM_CT ? "{lightblue}" : (team == CS_TEAM_T ? "{gold}" : "{grey}"));
    for (auto it = colors.begin(); it != colors.end(); ++it)
    {
        str = replace(str, it->first, it->second);
        str = replace(str, str_tolower(it->first), it->second);
    }
    return str;
}

Player::Player(bool m_isFakeClient, int m_slot, const char* m_name, uint64 m_xuid, std::string ip_address)
{
    this->slot = m_slot;
    this->isFakeClient = m_isFakeClient;
    this->connectTime = std::time(0);
    this->name = m_name;
    this->xuid = m_xuid;
    this->ip_address = ip_address;
}

Player::~Player()
{
    this->isFakeClient = true;
    this->isAuthenticated = false;
}

CBasePlayerController* Player::GetController()
{
    return (CBasePlayerController*)g_pEntitySystem->GetEntityInstance(CEntityIndex(this->slot + 1));
}

CBasePlayerPawn* Player::GetPawn()
{
    CBasePlayerController* controller = this->GetController();
    if (controller == nullptr)
        return nullptr;

    return controller->m_hPawn();
}

CCSPlayerController* Player::GetPlayerController()
{
    return (CCSPlayerController*)g_pEntitySystem->GetEntityInstance(CEntityIndex(this->slot + 1));
}

CCSPlayerPawn* Player::GetPlayerPawn()
{
    CCSPlayerController* controller = this->GetPlayerController();
    if (controller == nullptr)
        return nullptr;

    return controller->m_hPlayerPawn().Get();
}

CCSPlayerPawnBase* Player::GetPlayerBasePawn()
{
    CCSPlayerPawn* pawn = this->GetPlayerPawn();
    if (pawn == nullptr)
        return nullptr;

    return (CCSPlayerPawnBase*)pawn;
}

uint64 Player::GetSteamID()
{
    if (this->IsFakeClient())
        return 0;

    CBasePlayerController* controller = this->GetController();
    if (!controller)
        return this->xuid;

    return controller->m_steamID();
}

void Player::SendMsg(int dest, const char* msg, ...)
{
    CBasePlayerController* controller = this->GetController();
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
            engine->ClientPrintf(this->GetSlot(), message.c_str());
        }
    }
}

const char* Player::GetName()
{
    CBasePlayerController* controller = this->GetController();
    if (!controller)
        return this->name;

    return reinterpret_cast<char*>(controller->m_iszPlayerName());
}

void Player::Authenticate()
{
    this->isAuthenticated = true;
}

Vector Player::GetCoords()
{
    CCSPlayerPawn* pawn = this->GetPlayerPawn();
    if (!pawn)
    {
        Vector vec(0.0, 0.0, 0.0);
        return vec;
    }
    return pawn->m_CBodyComponent->m_pSceneNode->m_vecAbsOrigin();
}

void Player::SetCoords(float x, float y, float z)
{
    CBasePlayerPawn* pawn = this->GetPawn();
    if (!pawn)
        return;

    Vector vec(x, y, z);
    pawn->Teleport(&vec, nullptr, nullptr);
}

void Player::SwitchTeam(int team)
{
    CCSPlayerController* playerController = this->GetPlayerController();
    if (!playerController)
        return;

    if (team == CS_TEAM_SPECTATOR || team == CS_TEAM_NONE)
        CALL_VIRTUAL(void, g_Offsets->GetOffset("CCSPlayerController_ChangeTeam"), playerController, team);
    else
        g_Signatures->FetchSignature<CCSPlayerController_SwitchTeam>("CCSPlayerController_SwitchTeam")(playerController, team);
}

void Player::ChangeTeam(int team)
{
    CCSPlayerController* playerController = this->GetPlayerController();
    if (!playerController)
        return;

    CALL_VIRTUAL(void, g_Offsets->GetOffset("CCSPlayerController_ChangeTeam"), playerController, team);
}

void Player::RenderCenterText()
{
    if (this->centerMessageEndTime != 0)
    {
        if (this->centerMessageEndTime >= GetTime())
        {
            IGameEvent* pEvent = g_gameEventManager->CreateEvent("show_survival_respawn_status", true);
            if (pEvent)
            {
                pEvent->SetString("loc_token", this->centerMessageText.c_str());
                pEvent->SetUint64("duration", 1);
                pEvent->SetInt("userid", this->GetController()->GetEntityIndex().Get() - 1);

                IGameEventListener2* playerListener = g_Signatures->FetchSignature<GetLegacyGameEventListener>("LegacyGameEventListener")(this->GetSlot());

                playerListener->FireGameEvent(pEvent);
                g_gameEventManager->FreeEvent(pEvent);
            }
        }
        else
            this->centerMessageEndTime = 0;
    }
}

bool Player::HasCenterText() { return (this->centerMessageEndTime != 0); }

bool Player::IsFirstSpawn() { return this->firstSpawn; }
void Player::SetFirstSpawn(bool value) { this->firstSpawn = value; }

bool Player::IsFakeClient() { return this->isFakeClient; }
bool Player::IsAuthenticated() { return this->isAuthenticated; }
CPlayerSlot Player::GetSlot() { return CPlayerSlot(this->slot); }
uint32 Player::GetConnectedTime() { return (std::time(0) - this->connectTime); }
std::string Player::GetIPAddress() { return this->ip_address; }

void Player::SetConnected(bool connected) { this->isConnected = connected; }
bool Player::IsConnected() { return this->isConnected; }

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
    "unknown_key_31",
    "unknown_key_32",
    "tab",
    "unknown_key_34",
    "f",
    "unknown_key_36",
    "unknown_key_37",
    "unknown_key_38",
    "unknown_key_39",
    "unknown_key_40",
    "unknown_key_41",
    "unknown_key_42",
    "unknown_key_43",
    "unknown_key_44",
    "unknown_key_45",
    "unknown_key_46",
    "unknown_key_47",
    "unknown_key_48",
    "unknown_key_49",
    "unknown_key_50",
    "unknown_key_51",
    "unknown_key_52",
    "unknown_key_53",
    "unknown_key_54",
    "unknown_key_55",
    "unknown_key_56",
    "unknown_key_57",
    "unknown_key_58",
    "unknown_key_59",
    "unknown_key_60",
    "unknown_key_61",
    "unknown_key_62",
    "unknown_key_63",
};

void OnClientKeyStateChange(int playerid, std::string key, bool pressed);

void Player::SetButtons(uint64_t new_buttons)
{
    /*
    DEBUG: Button Presses

    for(uint64_t i = 0; i < 64; i++) {
        if((new_buttons & (1ULL << i)) != 0) {
            PRINTF("%s: %d\n", key_buttons[i].c_str(), i);
        }
    }
    PRINTF("Buttons: %s | %llu\n", std::bitset<64>(new_buttons).to_string().c_str(), new_buttons);
    */

    for (uint16_t i = 0; i < key_buttons.size(); i++)
    {
        if (this->IsButtonPressed((1ULL << i)) && (new_buttons & (1ULL << i)) == 0)
            OnClientKeyStateChange(this->GetSlot().Get(), key_buttons[i], false);
        else if (!this->IsButtonPressed((1ULL << i)) && (new_buttons & (1ULL << i)) != 0)
            OnClientKeyStateChange(this->GetSlot().Get(), key_buttons[i], true);
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

bool Player::HasMenuShown() { return (this->menu != nullptr); }
Menu* Player::GetMenu() { return this->menu; }

int Player::GetPage() { return this->page; }
void Player::SetPage(int pg)
{
    this->page = pg;
    this->selected = 0;
    this->menu->RegeneratePage(this->GetSlot().Get(), this->page, this->selected);
}
int Player::GetSelection() { return this->selected; }
void Player::MoveSelection()
{
    if (this->page == 0)
        return;

    int itemsPerPage = this->menu->GetItemsOnPage(this->page);
    ++this->selected;
    if (itemsPerPage == this->selected)
        this->selected = 0;

    this->menu->RegeneratePage(this->GetSlot().Get(), this->page, this->selected);
}

void Player::ShowMenu(std::string menuid)
{
    if (this->menu != nullptr)
        return;

    Menu* m = g_MenuManager->FetchMenu(menuid);
    if (m == nullptr)
        return;

    this->menu = m;
    this->page = 1;
    this->selected = 0;

    this->menu->RegeneratePage(this->GetSlot().Get(), this->page, this->selected);
    this->RenderMenu();
}

void Player::RenderMenu()
{
    if (this->menu == nullptr)
        return;

    if (this->centerMessageEndTime > 0)
        this->centerMessageEndTime = 0;

    IGameEvent* pEvent = g_gameEventManager->CreateEvent("show_survival_respawn_status", true);
    if (pEvent)
    {
        pEvent->SetString("loc_token", this->menu->GeneratedItems(this->GetSlot().Get(), this->page).c_str());
        pEvent->SetUint64("duration", 10);
        pEvent->SetInt("userid", this->GetController()->GetEntityIndex().Get() - 1);

        IGameEventListener2* playerListener = g_Signatures->FetchSignature<GetLegacyGameEventListener>("LegacyGameEventListener")(this->GetSlot());

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
    if (this->menu->IsTemporary())
    {
        std::string menuID = this->menu->GetID();
        g_MenuManager->UnregisterMenu(menuID);
    }
    this->menu = nullptr;

    IGameEvent* pEvent = g_gameEventManager->CreateEvent("show_survival_respawn_status", true);
    if (pEvent)
    {
        pEvent->SetString("loc_token", "Exiting...");
        pEvent->SetUint64("duration", 1);
        pEvent->SetInt("userid", this->GetController()->GetEntityIndex().Get() - 1);

        IGameEventListener2* playerListener = g_Signatures->FetchSignature<GetLegacyGameEventListener>("LegacyGameEventListener")(this->GetSlot());

        playerListener->FireGameEvent(pEvent);
        g_gameEventManager->FreeEvent(pEvent);
    }
}

void Player::PerformMenuAction(std::string button)
{
    if (!this->HasMenuShown())
        return;

    if (button == g_Config->FetchValue<std::string>("core.menu.buttons.scroll"))
    {
        CCSPlayerController* controller = this->GetPlayerController();
        CSingleRecipientFilter filter(this->GetSlot().Get());
        if (controller)
            controller->EmitSoundFilter(filter, g_Config->FetchValue<std::string>("core.menu.sound.scroll.name"), 1.0, g_Config->FetchValue<double>("core.menu.sound.scroll.volume"));

        this->MoveSelection();
        this->RenderMenu();
    }
    else if (!g_Config->FetchValue<bool>("core.menu.buttons.exit.option") && button == g_Config->FetchValue<std::string>("core.menu.buttons.exit.button"))
    {
        CCSPlayerController* controller = this->GetPlayerController();
        CSingleRecipientFilter filter(this->GetSlot().Get());
        if (controller)
            controller->EmitSoundFilter(filter, g_Config->FetchValue<std::string>("core.menu.sound.exit.name"), 1.0, g_Config->FetchValue<double>("core.menu.sound.exit.volume"));
        this->HideMenu();
    }
    else if (button == g_Config->FetchValue<std::string>("core.menu.buttons.use"))
    {
        std::string cmd = this->GetMenu()->GetCommandFromOption(this->GetPage(), this->GetSelection());
        CCSPlayerController* controller = this->GetPlayerController();
        CSingleRecipientFilter filter(this->GetSlot().Get());
        if (controller && cmd != "menuexit")
            controller->EmitSoundFilter(filter, g_Config->FetchValue<std::string>("core.menu.sound.use.name"), 1.0, g_Config->FetchValue<double>("core.menu.sound.use.volume"));
        if (cmd == "menunext")
        {
            this->SetPage(this->GetPage() + 1);
            this->RenderMenu();
        }
        else if (cmd == "menuback")
        {
            this->SetPage(this->GetPage() - 1);
            this->RenderMenu();
        }
        else if (g_Config->FetchValue<bool>("core.menu.buttons.exit.option") && cmd == "menuexit")
        {
            CCSPlayerController* controller = this->GetPlayerController();
            CSingleRecipientFilter filter(this->GetSlot().Get());
            if (controller)
                controller->EmitSoundFilter(filter, g_Config->FetchValue<std::string>("core.menu.sound.exit.name"), 1.0, g_Config->FetchValue<double>("core.menu.sound.exit.volume"));
            this->HideMenu();
        }
        else if (g_MenuManager->FetchMenu(cmd))
        {
            this->HideMenu();
            this->ShowMenu(cmd);
        }
        else if (starts_with(cmd, "sw_"))
        {
            CCommand tokenizedArgs;
            tokenizedArgs.Tokenize(cmd.c_str());

            std::vector<std::string> cmdString;
            for (int i = 1; i < tokenizedArgs.ArgC(); i++)
                cmdString.push_back(tokenizedArgs[i]);

            std::string commandName = replace(tokenizedArgs[0], "sw_", "");

            Command* cmd = g_commandsManager->FetchCommand(commandName);
            if (cmd)
                cmd->Execute(this->GetSlot().Get(), cmdString, true, "sw_");
        }
        else if (cmd != "")
            this->PerformCommand(cmd);
    }
}

void Player::PerformCommand(std::string command)
{
    engine->ClientCommand(this->GetSlot(), command.c_str());
}

void Player::SetClientConvar(std::string cmd, std::string val)
{
    ConVar* cv = FetchCVar(cmd);
    if (!cv)
        return;

    INetworkMessageInternal* netmsg = g_pNetworkMessages->FindNetworkMessagePartial("SetConVar");
    auto msg = netmsg->AllocateMessage()->ToPB<CNETMsg_SetConVar>();
    CMsg_CVars_CVar* cvar = msg->mutable_convars()->add_cvars();
    cvar->set_name(cv->m_pszName);
    cvar->set_value(val.c_str());

    CSingleRecipientFilter filter(this->GetSlot().Get());
    g_pGameEventSystem->PostEventAbstract(-1, false, &filter, netmsg, msg, 0);

    delete msg;
}

std::any Player::GetInternalVar(std::string name)
{
    if (this->internalVars.find(name) == this->internalVars.end())
        return nullptr;

    return this->internalVars.at(name);
}

void Player::SetInternalVar(std::string name, std::any value)
{
    this->internalVars[name] = value;
}

void Player::SetListen(CPlayerSlot slot, ListenOverride listen)
{
    m_listenMap[slot.Get()] = listen;
}

void Player::SetVoiceFlags(VoiceFlag_t flags)
{
    m_voiceFlag = flags;
}

VoiceFlag_t Player::GetVoiceFlags()
{
    return m_voiceFlag;
}

ListenOverride Player::GetListen(CPlayerSlot slot) const
{
    return m_listenMap[slot.Get()];
}
