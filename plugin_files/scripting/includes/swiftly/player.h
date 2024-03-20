#ifndef _swiftly_player_h
#define _swiftly_player_h

#include <stdint.h>
#include "swiftly_memory.h"
#include "types.h"
#include <cstdarg>
#include "swiftly_utils.h"

#include "player/health.h"
#include "player/armor.h"
#include "player/clantag.h"
#include "player/team.h"
#include "player/vars.h"
#include "player/stats.h"
#include "player/coords.h"
#include "player/money.h"
#include "player/velocity.h"
#include "player/weapons.h"
#include "player/gravity.h"
#include "player/speed.h"
#include "player/eyeangle.h"
#include "player/fov.h"

class Player
{
private:
    uint32_t m_playerSlot;
    bool m_fakeClient = false;

public:
    Health *health;
    Armor *armor;
    ClanTag *clantag;
    Team *team;
    Vars *vars;
    Stats *stats;
    Coords *coords;
    Money *money;
    Velocity *velocity;
    Weapons *weapons;
    Gravity *gravity;
    Speed *speed;
    EyeAngle *eyeangle;
    Fov *fov;

public:
    Player(uint32_t playerSlot, bool fakeClient) : m_playerSlot(playerSlot), m_fakeClient(fakeClient)
    {
        this->health = new Health(playerSlot);
        this->armor = new Armor(playerSlot);
        this->clantag = new ClanTag(playerSlot);
        this->team = new Team(playerSlot);
        this->vars = new Vars(playerSlot);
        this->stats = new Stats(playerSlot);
        this->coords = new Coords(playerSlot);
        this->money = new Money(playerSlot);
        this->velocity = new Velocity(playerSlot);
        this->weapons = new Weapons(playerSlot);
        this->gravity = new Gravity(playerSlot);
        this->speed = new Speed(playerSlot);
        this->eyeangle = new EyeAngle(playerSlot);
        this->fov = new Fov(playerSlot);
    }

    ~Player()
    {
        delete this->health;
        delete this->armor;
        delete this->clantag;
        delete this->team;
        delete this->vars;
        delete this->stats;
        delete this->coords;
        delete this->money;
        delete this->velocity;
        delete this->weapons;
        delete this->gravity;
        delete this->speed;
        delete this->eyeangle;
        delete this->fov;
    }

    uint32_t GetSlot() { return this->m_playerSlot; }

    const char *GetName()
    {
        REGISTER_METHOD(const char *, "", scripting_Player_GetName, this->m_playerSlot);
    }

    uint64_t GetSteamID()
    {
        if (this->IsFakeClient())
            return 0;

        REGISTER_METHOD(uint64_t, 0, scripting_Player_GetSteamID, this->m_playerSlot);
    }

    const char *GetSteamID2()
    {
        if (this->IsFakeClient())
            return "STEAM_0:0:000000000";

        REGISTER_METHOD(const char *, "STEAM_0:0:000000000", scripting_Player_GetSteamID2, this->m_playerSlot);
    }

    bool IsFirstSpawn()
    {
        REGISTER_METHOD(bool, false, scripting_Player_IsFirstSpawn, this->m_playerSlot);
    }
    bool IsFakeClient() { return this->m_fakeClient; }

    void Drop(ENetworkDisconnectionReason reason)
    {
        if (this->IsFakeClient())
            return;

        REGISTER_METHOD_VOID(scripting_Player_Drop, this->m_playerSlot, reason);
    }

    void Kill()
    {
        REGISTER_METHOD_VOID(scripting_Player_Kill, this->m_playerSlot);
    }

    bool IsAuthenticated()
    {
        REGISTER_METHOD(bool, false, scripting_Player_IsAuthenticated, this->m_playerSlot);
    }

    const char *GetConvarValue(const char *name)
    {
        if (name == nullptr)
            return "";

        REGISTER_METHOD(const char *, "", scripting_Player_GetConvar, this->m_playerSlot, name);
    }

    void SetConvar(const char *name, const char *value)
    {
        if (name == nullptr || value == nullptr)
            return;

        REGISTER_METHOD_VOID(scripting_Player_SetConvar, this->m_playerSlot, name, value);
    }

    const char *GetIPAddress()
    {
        REGISTER_METHOD(const char *, "", scripting_Player_GetIPAddress, this->m_playerSlot);
    }

    void SendMsg(HudDestination dest, const char *message, ...)
    {
        va_list ap;
        char buffer[2048];

        va_start(ap, message);
        UTIL_FormatArgs(buffer, sizeof(buffer), message, ap);
        va_end(ap);

        REGISTER_METHOD_VOID(scripting_Player_SendMessage, this->m_playerSlot, dest, buffer);
    }

    uint32_t GetConnectedTime()
    {
        REGISTER_METHOD(uint32_t, 0, scripting_Player_GetConnectedTime, this->m_playerSlot);
    }

    void ExecuteCommand(const char *cmd, ...)
    {
        va_list ap;
        char buffer[2048];

        va_start(ap, cmd);
        UTIL_FormatArgs(buffer, sizeof(buffer), cmd, ap);
        va_end(ap);

        REGISTER_METHOD_VOID(scripting_Player_ExecuteCommand, this->m_playerSlot, buffer);
    }

    void SetModel(const char *model)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetModel, this->m_playerSlot, model);
    }

    void SetMusicKit(int id)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetMusicKit, this->m_playerSlot, id);
    }

    void ShowMenu(const char *menuid)
    {
        REGISTER_METHOD_VOID(scripting_Player_ShowMenu, this->m_playerSlot, menuid);
    }

    void HideMenu()
    {
        REGISTER_METHOD_VOID(scripting_Player_HideMenu, this->m_playerSlot);
    }

    void SetFlashDuration(float duration)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetFlashDuration, this->m_playerSlot, duration);
    }

    void SetGloves(uint16_t defindex, int paintkit, int seed, float wear)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetGloves, this->m_playerSlot, defindex, paintkit, seed, wear);
    }

    int GetLatency()
    {
        REGISTER_METHOD(int, 0, scripting_Player_GetLatency, this->m_playerSlot);
    }

    void Respawn()
    {
        REGISTER_METHOD_VOID(scripting_Player_Respawn, this->m_playerSlot);
    }

    void SetHealthShotBoostEffectExpirationTime(float expiretime)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHealthShotBoostEffectExpirationTime, this->m_playerSlot, expiretime);
    }

    const char *GetChatTag()
    {
        REGISTER_METHOD(const char *, "", scripting_Player_GetChatTag, this->m_playerSlot);
    }

    void SetChatTag(const char *tag)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetChatTag, this->m_playerSlot, tag);
    }

    void SetChatTagColor(const char *color)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetChatTagColor, this->m_playerSlot, color);
    }

    void SetNameColor(const char *color)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNameColor, this->m_playerSlot, color);
    }

    void SetChatColor(const char *color)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetChatColor, this->m_playerSlot, color);
    }

    void SetName(const char *name)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetName, this->m_playerSlot, name);
    }

    void SetCompetitiveRanking(int ranking)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCompetitiveRanking, this->m_playerSlot, ranking);
    }

    void SetCompetitiveRankType(int type)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCompetitiveRankType, this->m_playerSlot, type);
    }
};

#endif