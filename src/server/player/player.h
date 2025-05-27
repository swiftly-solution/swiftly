#ifndef _server_player_player_h
#define _server_player_player_h

#include <string>
#include <any>
#include <map>

#include <embedder/src/Embedder.h>

#include <public/playerslot.h>
#include <public/mathlib/vector.h>
#include <public/igameevents.h>
#include <server/menus/MenuRenderer.h>
#include <ctime>

class Player
{
private:
    int slot;
    bool isFakeClient = false;

    time_t connectTime;
    const char* name;
    uint64_t xuid;
    std::string ip_address = "0.0.0.0";

    bool firstSpawn = true;

    int m_listenMap[66] = {};
    int m_voiceFlag = 0;

    ClassData* playerObject = nullptr;

    std::map<std::string, std::any> internalVars;

    IGameEventListener2* playerListener = nullptr;

    uint64_t centerMessageEndTime = 0;
    std::string centerMessageText;

    uint64_t buttons;

public:
    MenuRenderer* menu_renderer = nullptr;

    Player(bool m_isFakeClient, int m_slot, const char* m_name, uint64_t m_xuid, std::string ip_address);
    ~Player();

    bool IsFakeClient();
    int GetSlot();
    uint32_t GetConnectedTime();
    std::string GetIPAddress();

    void SendMsg(int dest, const char* msg, ...);

    const char* GetName();
    uint64_t GetSteamID();

    void* GetController();
    void* GetPawn();
    void* GetPlayerPawn();

    Vector GetCoords();
    void SetCoords(Vector vec);
    void SetCoords(float x, float y, float z);

    void SwitchTeam(int team);
    void ChangeTeam(int team);

    bool IsFirstSpawn();
    void SetFirstSpawn(bool value);

    void PerformCommand(std::string command);
    void SetClientConvar(std::string cmd, std::string val);

    std::any GetInternalVar(std::string name);
    void SetInternalVar(std::string name, std::any value);

    void SetListen(CPlayerSlot slot, int listen);
    int GetListen(CPlayerSlot slot);

    void SetVoiceFlags(int flags);
    int GetVoiceFlags();

    void* EnsureCustomView(int index);
    ClassData* GetPlayerObject();

    void Think();

    void SetButtons(uint64_t button);

    CPlayerBitVec m_selfMutes[64] = {};
};

#endif