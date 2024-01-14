#ifndef _player_h
#define _player_h

#include "../sdk/entity/CBasePlayerController.h"
#include "../sdk/entity/CCSPlayerController.h"
#include "../sdk/entity/CBasePlayerPawn.h"
#include "../sdk/entity/CCSPlayerPawn.h"
#include "../sdk/entity/CCSPlayerPawnBase.h"

#include <public/mathlib/vector.h>
#include <public/playerslot.h>
#include <ctime>
#include <any>

#define HUD_PRINTNOTIFY 1
#define HUD_PRINTCONSOLE 2
#define HUD_PRINTTALK 3
#define HUD_PRINTCENTER 4

enum ENetworkDisconnectionReason
{
    NETWORK_DISCONNECT_INVALID = 0,
    NETWORK_DISCONNECT_SHUTDOWN = 1,
    NETWORK_DISCONNECT_DISCONNECT_BY_USER = 2,
    NETWORK_DISCONNECT_DISCONNECT_BY_SERVER = 3,
    NETWORK_DISCONNECT_LOST = 4,
    NETWORK_DISCONNECT_OVERFLOW = 5,
    NETWORK_DISCONNECT_STEAM_BANNED = 6,
    NETWORK_DISCONNECT_STEAM_INUSE = 7,
    NETWORK_DISCONNECT_STEAM_TICKET = 8,
    NETWORK_DISCONNECT_STEAM_LOGON = 9,
    NETWORK_DISCONNECT_STEAM_AUTHCANCELLED = 10,
    NETWORK_DISCONNECT_STEAM_AUTHALREADYUSED = 11,
    NETWORK_DISCONNECT_STEAM_AUTHINVALID = 12,
    NETWORK_DISCONNECT_STEAM_VACBANSTATE = 13,
    NETWORK_DISCONNECT_STEAM_LOGGED_IN_ELSEWHERE = 14,
    NETWORK_DISCONNECT_STEAM_VAC_CHECK_TIMEDOUT = 15,
    NETWORK_DISCONNECT_STEAM_DROPPED = 16,
    NETWORK_DISCONNECT_STEAM_OWNERSHIP = 17,
    NETWORK_DISCONNECT_SERVERINFO_OVERFLOW = 18,
    NETWORK_DISCONNECT_TICKMSG_OVERFLOW = 19,
    NETWORK_DISCONNECT_STRINGTABLEMSG_OVERFLOW = 20,
    NETWORK_DISCONNECT_DELTAENTMSG_OVERFLOW = 21,
    NETWORK_DISCONNECT_TEMPENTMSG_OVERFLOW = 22,
    NETWORK_DISCONNECT_SOUNDSMSG_OVERFLOW = 23,
    NETWORK_DISCONNECT_SNAPSHOTOVERFLOW = 24,
    NETWORK_DISCONNECT_SNAPSHOTERROR = 25,
    NETWORK_DISCONNECT_RELIABLEOVERFLOW = 26,
    NETWORK_DISCONNECT_BADDELTATICK = 27,
    NETWORK_DISCONNECT_NOMORESPLITS = 28,
    NETWORK_DISCONNECT_TIMEDOUT = 29,
    NETWORK_DISCONNECT_DISCONNECTED = 30,
    NETWORK_DISCONNECT_LEAVINGSPLIT = 31,
    NETWORK_DISCONNECT_DIFFERENTCLASSTABLES = 32,
    NETWORK_DISCONNECT_BADRELAYPASSWORD = 33,
    NETWORK_DISCONNECT_BADSPECTATORPASSWORD = 34,
    NETWORK_DISCONNECT_HLTVRESTRICTED = 35,
    NETWORK_DISCONNECT_NOSPECTATORS = 36,
    NETWORK_DISCONNECT_HLTVUNAVAILABLE = 37,
    NETWORK_DISCONNECT_HLTVSTOP = 38,
    NETWORK_DISCONNECT_KICKED = 39,
    NETWORK_DISCONNECT_BANADDED = 40,
    NETWORK_DISCONNECT_KICKBANADDED = 41,
    NETWORK_DISCONNECT_HLTVDIRECT = 42,
    NETWORK_DISCONNECT_PURESERVER_CLIENTEXTRA = 43,
    NETWORK_DISCONNECT_PURESERVER_MISMATCH = 44,
    NETWORK_DISCONNECT_USERCMD = 45,
    NETWORK_DISCONNECT_REJECTED_BY_GAME = 46,
    NETWORK_DISCONNECT_MESSAGE_PARSE_ERROR = 47,
    NETWORK_DISCONNECT_INVALID_MESSAGE_ERROR = 48,
    NETWORK_DISCONNECT_BAD_SERVER_PASSWORD = 49,
    NETWORK_DISCONNECT_DIRECT_CONNECT_RESERVATION = 50,
    NETWORK_DISCONNECT_CONNECTION_FAILURE = 51,
    NETWORK_DISCONNECT_NO_PEER_GROUP_HANDLERS = 52,
    NETWORK_DISCONNECT_RECONNECTION = 53,
    NETWORK_DISCONNECT_LOOPSHUTDOWN = 54,
    NETWORK_DISCONNECT_LOOPDEACTIVATE = 55,
    NETWORK_DISCONNECT_HOST_ENDGAME = 56,
    NETWORK_DISCONNECT_LOOP_LEVELLOAD_ACTIVATE = 57,
    NETWORK_DISCONNECT_CREATE_SERVER_FAILED = 58,
    NETWORK_DISCONNECT_EXITING = 59,
    NETWORK_DISCONNECT_REQUEST_HOSTSTATE_IDLE = 60,
    NETWORK_DISCONNECT_REQUEST_HOSTSTATE_HLTVRELAY = 61,
    NETWORK_DISCONNECT_CLIENT_CONSISTENCY_FAIL = 62,
    NETWORK_DISCONNECT_CLIENT_UNABLE_TO_CRC_MAP = 63,
    NETWORK_DISCONNECT_CLIENT_NO_MAP = 64,
    NETWORK_DISCONNECT_CLIENT_DIFFERENT_MAP = 65,
    NETWORK_DISCONNECT_SERVER_REQUIRES_STEAM = 66,
    NETWORK_DISCONNECT_STEAM_DENY_MISC = 67,
    NETWORK_DISCONNECT_STEAM_DENY_BAD_ANTI_CHEAT = 68,
    NETWORK_DISCONNECT_SERVER_SHUTDOWN = 69
};

class Player
{
public:
    Player(bool m_isFakeClient, int m_slot, const char *m_name, uint64 m_xuid, std::string ip_address)
    {
        this->slot = m_slot;
        this->isFakeClient = m_isFakeClient;
        this->connectTime = std::time(0);
        this->name = m_name;
        this->xuid = m_xuid;
        this->ip_address = ip_address;
    }

    ~Player()
    {
        this->isFakeClient = true;
        this->isAuthenticated = false;
        this->internalVars.clear();
    }

    inline bool IsFakeClient() { return this->isFakeClient; };
    inline bool IsAuthenticated() { return this->isAuthenticated; };
    inline CPlayerSlot *GetSlot() { return new CPlayerSlot(this->slot); };
    inline void SetEHandlerIdx(int eHandleId) { this->eHandleId = eHandleId; };
    inline int GetEHandlerIdx() { return this->eHandleId; };
    inline uint32 GetConnectedTime() { return (std::time(0) - this->connectTime); };
    inline std::string GetIPAddress() { return this->ip_address; }

    inline void SetConnected(bool connected) { this->isConnected = connected; };
    inline bool IsConnected() { return this->isConnected; };

    void SendMsg(int dest, const char *msg, ...);

    void Authenticate();
    const char *GetName();
    uint64 GetSteamID();

    CBasePlayerController *GetController();
    CBasePlayerPawn *GetPawn();
    CCSPlayerController *GetPlayerController();
    CCSPlayerPawn *GetPlayerPawn();
    CCSPlayerPawnBase *GetPlayerBasePawn();
    Vector GetCoords();
    void SetCoords(float x, float y, float z);

    void SwitchTeam(int team);

    std::any GetInternalVar(std::string name);
    void SetInternalVar(std::string name, std::any value);

    CBasePlayerWeapon *GetPlayerWeaponFromSlot(gear_slot_t slot);
    CBasePlayerWeapon *GetPlayerWeaponFromID(uint32 weaponid);

private:
    int slot;
    bool isFakeClient = false;
    bool isAuthenticated = false;
    bool isConnected = false;
    int eHandleId = -1;
    std::time_t connectTime;
    const char *name;
    uint64 xuid;
    std::string ip_address = "0.0.0.0";

    std::map<std::string, std::any> internalVars;
};

#endif