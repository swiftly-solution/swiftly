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
        void *player_GetName = FetchFunctionPtr(nullptr, "scripting_Player_GetName");
        if (player_GetName)
            return reinterpret_cast<Player_GetName>(player_GetName)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_GetName");
            return "";
        }
    }

    uint64_t GetSteamID()
    {
        if (this->IsFakeClient())
            return 0;

        void *player_GetSteamID = FetchFunctionPtr(nullptr, "scripting_Player_GetSteamID");
        if (player_GetSteamID)
            return reinterpret_cast<Player_GetSteamID>(player_GetSteamID)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_GetSteamID");
            return 0;
        }
    }

    const char *GetSteamID2()
    {
        if (this->IsFakeClient())
            return "STEAM_0:0:000000000";

        void *player_GetSteamID2 = FetchFunctionPtr(nullptr, "scripting_Player_GetSteamID2");
        if (player_GetSteamID2)
            return reinterpret_cast<Player_GetName>(player_GetSteamID2)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_GetSteamID2");
            return "STEAM_0:0:000000000";
        }
    }

    bool IsFirstSpawn()
    {
        void *player_IsFirstSpawn = FetchFunctionPtr(nullptr, "scripting_Player_IsFirstSpawn");
        if (player_IsFirstSpawn)
            return reinterpret_cast<Player_IsFirstSpawn>(player_IsFirstSpawn)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_IsFirstSpawn");
            return false;
        }
    }
    bool IsFakeClient() { return this->m_fakeClient; }

    void Drop(ENetworkDisconnectionReason reason)
    {
        if (this->IsFakeClient())
            return;

        void *player_Drop = FetchFunctionPtr(nullptr, "scripting_Player_Drop");
        if (player_Drop)
            reinterpret_cast<Player_Drop>(player_Drop)(this->m_playerSlot, reason);
        else
            NOT_SUPPORTED("scripting_Player_Drop");
    }

    void Kill()
    {
        void *player_Kill = FetchFunctionPtr(nullptr, "scripting_Player_Kill");
        if (player_Kill)
            reinterpret_cast<Player_Kill>(player_Kill)(this->m_playerSlot);
        else
            NOT_SUPPORTED("scripting_Player_Kill");
    }

    bool IsAuthenticated()
    {
        void *player_IsAuthenticated = FetchFunctionPtr(nullptr, "scripting_Player_IsAuthenticated");
        if (player_IsAuthenticated)
            return reinterpret_cast<Player_IsAuthenticated>(player_IsAuthenticated)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_IsAuthenticated");
            return false;
        }
    }

    const char *GetConvarValue(const char *name)
    {
        if (name == nullptr)
            return "";

        void *player_GetConvar = FetchFunctionPtr(nullptr, "scripting_Player_GetConvar");
        if (player_GetConvar)
            return reinterpret_cast<Player_GetConvar>(player_GetConvar)(this->m_playerSlot, name);
        else
        {
            NOT_SUPPORTED("scripting_Player_GetConvar");
            return "";
        }
    }

    void SetConvar(const char *name, const char *value)
    {
        if (name == nullptr || value == nullptr)
            return;

        void *player_SetConvar = FetchFunctionPtr(nullptr, "scripting_Player_SetConvar");
        if (player_SetConvar)
            reinterpret_cast<Player_SetConvar>(player_SetConvar)(this->m_playerSlot, name, value);
        else
            NOT_SUPPORTED("scripting_Player_SetConvar");
    }

    void SendMsg(HudDestination dest, const char *message, ...)
    {
        va_list ap;
        char buffer[2048];

        va_start(ap, message);
        UTIL_FormatArgs(buffer, sizeof(buffer), message, ap);
        va_end(ap);

        void *player_SendMessage = FetchFunctionPtr(nullptr, "scripting_Player_SendMessage");
        if (player_SendMessage)
            reinterpret_cast<Player_SendMessage>(player_SendMessage)(this->m_playerSlot, dest, buffer);
        else
            NOT_SUPPORTED("scripting_Player_SendMessage");
    }

    uint32_t GetConnectedTime()
    {
        void *player_GetConnectedTime = FetchFunctionPtr(nullptr, "scripting_Player_GetConnectedTime");
        if (player_GetConnectedTime)
            return reinterpret_cast<Player_GetConnectedTime>(player_GetConnectedTime)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_GetConnectedTime");
            return 0;
        }
    }

    void ExecuteCommand(const char *cmd, ...)
    {
        va_list ap;
        char buffer[2048];

        va_start(ap, cmd);
        UTIL_FormatArgs(buffer, sizeof(buffer), cmd, ap);
        va_end(ap);

        void *player_ExecuteCommand = FetchFunctionPtr(nullptr, "scripting_Player_ExecuteCommand");
        if (player_ExecuteCommand)
            reinterpret_cast<Player_ExecuteCommand>(player_ExecuteCommand)(this->m_playerSlot, buffer);
        else
            NOT_SUPPORTED("scripting_Player_ExecuteCommand");
    }

    void SetModel(const char *model)
    {
        void *player_SetModel = FetchFunctionPtr(nullptr, "scripting_Player_SetModel");
        if (player_SetModel)
            reinterpret_cast<Player_SetModel>(player_SetModel)(this->m_playerSlot, model);
        else
            NOT_SUPPORTED("scripting_Player_SetModel");
    }

    void SetMusicKit(int id)
    {
        void *player_SetMusicKit = FetchFunctionPtr(nullptr, "scripting_Player_SetMusicKit");
        if (player_SetMusicKit)
            reinterpret_cast<Player_SetMusicKit>(player_SetMusicKit)(this->m_playerSlot, id);
        else
            NOT_SUPPORTED("scripting_Player_SetMusicKit");
    }

    void ShowMenu(const char *menuid)
    {
        void *player_ShowMenu = FetchFunctionPtr(nullptr, "scripting_Player_ShowMenu");
        if (player_ShowMenu)
            reinterpret_cast<Player_ShowMenu>(player_ShowMenu)(this->m_playerSlot, menuid);
        else
            NOT_SUPPORTED("scripting_Player_ShowMenu");
    }

    void HideMenu()
    {
        void *player_HideMenu = FetchFunctionPtr(nullptr, "scripting_Player_HideMenu");
        if (player_HideMenu)
            reinterpret_cast<Player_HideMenu>(player_HideMenu)(this->m_playerSlot);
        else
            NOT_SUPPORTED("scripting_Player_HideMenu");
    }

    void SetFlashDuration(float duration)
    {
        void *player_SetFlashDuration = FetchFunctionPtr(nullptr, "scripting_Player_SetFlashDuration");
        if (player_SetFlashDuration)
            reinterpret_cast<Player_SetFlashDuration>(player_SetFlashDuration)(this->m_playerSlot, duration);
        else
            NOT_SUPPORTED("scripting_Player_SetFlashDuration");
    }

    void SetGloves(uint16_t defindex, int paintkit, int seed, float wear)
    {
        void *player_SetGloves = FetchFunctionPtr(nullptr, "scripting_Player_SetGloves");
        if (player_SetGloves)
            reinterpret_cast<Player_SetGloves>(player_SetGloves)(this->m_playerSlot, defindex, paintkit, seed, wear);
        else
            NOT_SUPPORTED("scripting_Player_SetGloves");
    }

    int GetLatency()
    {
        void *player_GetLatency = FetchFunctionPtr(nullptr, "scripting_Player_GetLatency");
        if (player_GetLatency)
            return reinterpret_cast<Player_GetLatency>(player_GetLatency)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_GetLatency");
            return 0;
        }
    }

    void Respawn()
    {
        void *player_Respawn = FetchFunctionPtr(nullptr, "scripting_Player_Respawn");
        if (player_Respawn)
            reinterpret_cast<Player_Kill>(player_Respawn)(this->m_playerSlot);
        else
            NOT_SUPPORTED("scripting_Player_Respawn");
    }

    void SetHealthShotBoostEffectExpirationTime(float expiretime)
    {
        void *player_SetHealthShotBoostEffectExpirationTime = FetchFunctionPtr(nullptr, "scripting_Player_SetHealthShotBoostEffectExpirationTime");
        if (player_SetHealthShotBoostEffectExpirationTime)
            reinterpret_cast<Player_SetGravity>(player_SetHealthShotBoostEffectExpirationTime)(this->m_playerSlot, expiretime);
        else
            NOT_SUPPORTED("scripting_Player_SetHealthShotBoostEffectExpirationTime");
    }

    const char *GetChatTag()
    {
        void *player_GetChatTag = FetchFunctionPtr(nullptr, "scripting_Player_GetChatTag");
        if (player_GetChatTag)
            return reinterpret_cast<Player_GetChatTag>(player_GetChatTag)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_GetChatTag");
            return "";
        }
    }

    void SetChatTag(const char *tag)
    {
        void *player_SetChatTag = FetchFunctionPtr(nullptr, "scripting_Player_SetChatTag");
        if (player_SetChatTag)
            reinterpret_cast<Player_SetColorGeneral>(player_SetChatTag)(this->m_playerSlot, tag);
        else
            NOT_SUPPORTED("scripting_Player_SetChatTag");
    }

    void SetChatTagColor(const char *color)
    {
        void *player_SetChatTagColor = FetchFunctionPtr(nullptr, "scripting_Player_SetChatTagColor");
        if (player_SetChatTagColor)
            reinterpret_cast<Player_SetColorGeneral>(player_SetChatTagColor)(this->m_playerSlot, color);
        else
            NOT_SUPPORTED("scripting_Player_SetChatTagColor");
    }

    void SetNameColor(const char *color)
    {
        void *player_SetNameColor = FetchFunctionPtr(nullptr, "scripting_Player_SetNameColor");
        if (player_SetNameColor)
            reinterpret_cast<Player_SetColorGeneral>(player_SetNameColor)(this->m_playerSlot, color);
        else
            NOT_SUPPORTED("scripting_Player_SetNameColor");
    }

    void SetChatColor(const char *color)
    {
        void *player_SetChatColor = FetchFunctionPtr(nullptr, "scripting_Player_SetChatColor");
        if (player_SetChatColor)
            reinterpret_cast<Player_SetColorGeneral>(player_SetChatColor)(this->m_playerSlot, color);
        else
            NOT_SUPPORTED("scripting_Player_SetChatColor");
    }

    void SetName(const char *name)
    {
        void *player_SetName = FetchFunctionPtr(nullptr, "scripting_Player_SetName");
        if (player_SetName)
            reinterpret_cast<Player_SetColorGeneral>(player_SetName)(this->m_playerSlot, name);
        else
            NOT_SUPPORTED("scripting_Player_SetName");
    }

    void SetCompetitiveRanking(int ranking)
    {
        void *player_SetCompetitiveRanking = FetchFunctionPtr(nullptr, "scripting_Player_SetCompetitiveRanking");
        if (player_SetCompetitiveRanking)
            reinterpret_cast<Player_SetMusicKit>(player_SetCompetitiveRanking)(this->m_playerSlot, ranking);
        else
            NOT_SUPPORTED("scripting_Player_SetCompetitiveRanking");
    }

    void SetCompetitiveRankType(int type)
    {
        void *player_SetCompetitiveRankType = FetchFunctionPtr(nullptr, "scripting_Player_SetCompetitiveRankType");
        if (player_SetCompetitiveRankType)
            reinterpret_cast<Player_SetMusicKit>(player_SetCompetitiveRankType)(this->m_playerSlot, type);
        else
            NOT_SUPPORTED("scripting_Player_SetCompetitiveRankType");
    }
};

#endif