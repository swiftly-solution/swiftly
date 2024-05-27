#include "Player.h"

#include "../entrypoint.h"
#include "../common.h"
#include "../utils/utils.h"

typedef IGameEventListener2 *(*GetLegacyGameEventListener)(CPlayerSlot slot);

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

Player::Player(bool m_isFakeClient, int m_slot, const char *m_name, uint64 m_xuid, std::string ip_address)
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

CBasePlayerController *Player::GetController()
{
    return (CBasePlayerController *)g_pEntitySystem->GetEntityInstance(CEntityIndex(this->slot + 1));
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
    return (CCSPlayerController *)g_pEntitySystem->GetEntityInstance(CEntityIndex(this->slot + 1));
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
        // this->centerMessageEndTime = GetTime() + 5000;
        // this->centerMessageText = msg;
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

const char *Player::GetName()
{
    CBasePlayerController *controller = this->GetController();
    if (!controller)
        return this->name;

    return reinterpret_cast<char *>(controller->m_iszPlayerName());
}

void Player::Authenticate()
{
    this->isAuthenticated = true;
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

bool Player::IsFirstSpawn() { return this->firstSpawn; }
void Player::SetFirstSpawn(bool value) { this->firstSpawn = value; }

bool Player::IsFakeClient() { return this->isFakeClient; };
bool Player::IsAuthenticated() { return this->isAuthenticated; };
CPlayerSlot Player::GetSlot() { return CPlayerSlot(this->slot); };
uint32 Player::GetConnectedTime() { return (std::time(0) - this->connectTime); };
std::string Player::GetIPAddress() { return this->ip_address; }

void Player::SetConnected(bool connected) { this->isConnected = connected; };
bool Player::IsConnected() { return this->isConnected; };