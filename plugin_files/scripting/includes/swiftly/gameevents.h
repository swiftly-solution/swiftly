#ifndef _swiftly_gameevents_h
#define _swiftly_gameevents_h

#include "playermanager.h"

class Player;

void ThreadFunction() __attribute__((weak));

void print(const char *str, ...);

void OnPluginStart() __attribute__((weak));
void OnPluginStop() __attribute__((weak));
void OnProgramLoad(const char *pluginName, const char *mainFilePath);
bool OnClientConnect(Player *player) __attribute__((weak));
void OnClientDisconnect(Player *player) __attribute__((weak));
void OnClientFullConnected(Player *player) __attribute__((weak));
void OnPlayerSpawn(Player *player) __attribute__((weak));
void OnGameTick(bool simulating, bool bFirstTick, bool bLastTick) __attribute__((weak));
bool OnPlayerChat(Player *player, const char *text, bool teamonly) __attribute__((weak));
void OnRoundStart(long timelimit, long fraglimit, const char *objective) __attribute__((weak));
void OnRoundEnd(unsigned char winner, unsigned char reason, const char *message, unsigned char legacy, short player_count, unsigned char nomusic) __attribute__((weak));
void OnRoundPrestart() __attribute__((weak));
void OnBombBeginPlant(Player *player, unsigned short site) __attribute__((weak));
void OnBombAbortPlant(Player *player, unsigned short site) __attribute__((weak));
void OnBombPlanted(Player *player, unsigned short site) __attribute__((weak));
void OnBombBeginDefuse(Player *player, unsigned short site) __attribute__((weak));
void OnBombAbortDefuse(Player *player, unsigned short site) __attribute__((weak));
void OnBombDefused(Player *player, unsigned short site) __attribute__((weak));
void OnBombExploded(Player *player, unsigned short site) __attribute__((weak));
void OnBombDropped(Player *player) __attribute__((weak));
void OnBombPickup(Player *player) __attribute__((weak));
void OnMapLoad(const char *mapName) __attribute__((weak));
void OnMapUnload(const char *mapName) __attribute__((weak));
bool OnClientGameMessage(Player *player, int destination, const char *message) __attribute__((weak));
void OnPlayerDeath(Player *player, Player *attacker, Player *assister, bool assistedflash, const char *weapon, bool headshot, short dominated, short revenge, short wipe, short penetrated, bool noreplay, bool noscope, bool thrusmoke, bool attackerblind, float distance, short dmg_health, short dmg_armor, short hitgroup) __attribute__((weak));
void OnPlayerHurt(Player *player, Player *attacker, short dmgHealth, short dmgArmor, short hitgroup, const char *weapon, bool fatal) __attribute__((weak));
void OnPlayerBlind(Player *player, Player *attacker, short entityid, float duration) __attribute__((weak));
void OnPlayerFullUpdate(Player *player, short count) __attribute__((weak));
void OnItemPickup(Player *player, const char *item, bool silent, long defindex) __attribute__((weak));
void OnEnterBuyzone(Player *player, bool canbuy) __attribute__((weak));
void OnExitBuyzone(Player *player, bool canbuy) __attribute__((weak));
void OnEnterBombzone(Player *player, bool hasbomb, bool isplanted) __attribute__((weak));
void OnExitBombzone(Player *player, bool hasbomb, bool isplanted) __attribute__((weak));
void OnPlayerFallDamage(Player *player, float damage) __attribute__((weak));
void OnPlayerJump(Player *player) __attribute__((weak));
bool ShouldHearVoice(Player *player) __attribute__((weak));
bool OnWeaponSpawned(Player *player, Weapon *weapon) __attribute__((weak));
void OnClientKeyStateChange(Player *player, const char *button, bool pressed) __attribute__((weak));
void OnClientExecuteCommand(Player *player, const char *command) __attribute__((weak));

extern "C"
{
    void Internal_OnPluginStart()
    {
        print("");
        if (OnPluginStart)
            OnPluginStart();
    }
    void Internal_OnPluginStop()
    {
        if (OnPluginStop)
            OnPluginStop();
    }
    void Internal_OnProgramLoad(const char *pluginName, const char *mainFilePath)
    {
        OnProgramLoad(pluginName, mainFilePath);
    }
    void Internal_OnClientDisconnect(uint32_t slot)
    {
        if (!OnClientDisconnect)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnClientDisconnect(player);
    }
    bool Internal_OnClientConnect(uint32_t slot)
    {
        if (!OnClientConnect)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return false;

        return OnClientConnect(player);
    }
    void Internal_OnClientFullConnected(uint32_t slot)
    {
        if (OnClientFullConnected)
        {
            Player *player = g_playerManager->GetPlayer(slot);
            if (player == nullptr)
                return;

            OnClientFullConnected(player);
        }
    }
    void Internal_OnPlayerSpawn(uint32_t slot)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnPlayerSpawn)
            OnPlayerSpawn(player);

        if (player->IsFirstSpawn())
            player->SetFirstSpawn(true);
    }
    bool Internal_OnPlayerChat(uint32_t slot, const char *text, bool teamonly)
    {
        if (!OnPlayerChat)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return false;

        return OnPlayerChat(player, text, teamonly);
    }
    bool Internal_OnClientGameMessage(uint32_t slot, int destination, const char *message)
    {
        if (!OnClientGameMessage)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return true;

        return OnClientGameMessage(player, destination, message);
    }
    void Internal_RegisterPlayer(uint32_t slot, bool fakeClient)
    {
        g_playerManager->RegisterPlayer(new Player(slot, fakeClient));
    }
    void Internal_UnregisterPlayer(uint32_t slot)
    {
        g_playerManager->UnregisterPlayer(slot);
    }
    void Internal_OnItemPickup(uint32_t slot, const char *item, bool silent, long defindex)
    {
        if (!OnItemPickup)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnItemPickup(player, item, silent, defindex);
    }
    void Interval_OnEnterBuyzone(uint32_t slot, bool canbuy)
    {
        if (!OnEnterBuyzone)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnEnterBuyzone(player, canbuy);
    }
    void Interval_OnEnterBombzone(uint32_t slot, bool hasbomb, bool isplanted)
    {
        if (!OnEnterBombzone)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnEnterBombzone(player, hasbomb, isplanted);
    }
    void Interval_OnExitBombzone(uint32_t slot, bool hasbomb, bool isplanted)
    {
        if (!OnExitBombzone)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnExitBombzone(player, hasbomb, isplanted);
    }
    void Interval_OnExitBuyzone(uint32_t slot, bool canbuy)
    {
        if (!OnExitBuyzone)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnExitBuyzone(player, canbuy);
    }
    void Internal_OnGameTick(bool simulating, bool bFirstTick, bool bLastTick)
    {
        if (ThreadFunction)
            ThreadFunction();

        if (OnGameTick)
            OnGameTick(simulating, bFirstTick, bLastTick);
    }
    void Internal_OnPlayerFullUpdate(uint32_t slot, short count)
    {
        if (!OnPlayerFullUpdate)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnPlayerFullUpdate(player, count);
    }
    void Internal_OnRoundEnd(unsigned char winner, unsigned char reason, const char *message, unsigned char legacy, short player_count, unsigned char nomusic)
    {
        if (OnRoundEnd)
            OnRoundEnd(winner, reason, message, legacy, player_count, nomusic);
    }
    void Internal_OnRoundStart(long timelimit, long fraglimit, const char *objective)
    {
        if (OnRoundStart)
            OnRoundStart(timelimit, fraglimit, objective);
    }
    void Internal_OnRoundPrestart()
    {
        if (OnRoundPrestart)
            OnRoundPrestart();
    }

    void Internal_BombBeginPlant(uint32_t slot, uint16_t site)
    {
        if (!OnBombBeginPlant)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombBeginPlant(player, site);
    }

    void Internal_BombAbortPlant(uint32_t slot, uint16_t site)
    {
        if (!OnBombAbortPlant)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombAbortPlant(player, site);
    }

    void Internal_BombPlanted(uint32_t slot, uint16_t site)
    {
        if (!OnBombPlanted)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombPlanted(player, site);
    }

    void Internal_BombBeginDefuse(uint32_t slot, uint16_t site)
    {
        if (!OnBombBeginDefuse)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombBeginDefuse(player, site);
    }

    void Internal_BombAbortDefuse(uint32_t slot, uint16_t site)
    {
        if (!OnBombAbortDefuse)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombAbortDefuse(player, site);
    }

    void Internal_BombDefused(uint32_t slot, uint16_t site)
    {
        if (!OnBombDefused)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombDefused(player, site);
    }

    void Internal_BombExploded(uint32_t slot, uint16_t site)
    {
        if (!OnBombExploded)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombExploded(player, site);
    }

    void Internal_BombDropped(uint32_t slot)
    {
        if (!OnBombDropped)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombDropped(player);
    }

    void Internal_BombPickup(uint32_t slot)
    {
        if (!OnBombPickup)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombPickup(player);
    }

    void Internal_OnMapLoad(const char *mapName)
    {
        if (OnMapLoad)
            OnMapLoad(mapName);
    }

    void Internal_OnMapUnload(const char *mapName)
    {
        if (OnMapUnload)
            OnMapUnload(mapName);
    }

    void Internal_OnPlayerDeath(int slot, int attacker, int assister, bool assistedflash, const char *weapon, bool headshot, short dominated, short revenge, short wipe, short penetrated, bool noreplay, bool noscope, bool thrusmoke, bool attackerblind, float distance, short dmg_health, short dmg_armor, short hitgroup)
    {
        if (!OnPlayerDeath)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        Player *attackerPlayer = nullptr, *assisterPlayer = nullptr;
        if (attacker != -1)
        {
            attackerPlayer = g_playerManager->GetPlayer(attacker);
            if (attackerPlayer == nullptr)
                return;
        }
        if (assister != -1)
        {
            assisterPlayer = g_playerManager->GetPlayer(assister);
            if (assisterPlayer == nullptr)
                return;
        }

        OnPlayerDeath(player, attackerPlayer, assisterPlayer, assistedflash, weapon, headshot, dominated, revenge, wipe, penetrated, noreplay, noscope, thrusmoke, attackerblind, distance, dmg_health, dmg_armor, hitgroup);
    }

    void Internal_OnPlayerBlind(int slot, int attacker, short entityid, float duration)
    {
        if (!OnPlayerBlind)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        Player *attackerPlayer = g_playerManager->GetPlayer(attacker);
        if (attackerPlayer == nullptr)
            return;

        OnPlayerBlind(player, attackerPlayer, entityid, duration);
    }

    void Internal_OnPlayerFallDamage(int slot, float damage)
    {
        if (!OnPlayerFallDamage)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnPlayerFallDamage(player, damage);
    }

    void Internal_OnPlayerJump(int slot)
    {
        if (!OnPlayerBlind)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnPlayerJump(player);
    }

    void Internal_OnPlayerHurt(int slot, int attacker, short dmgHealth, short dmgArmor, short hitgroup, const char *weapon)
    {
        if (!OnPlayerHurt)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        Player *attackerPlayer = g_playerManager->GetPlayer(attacker);
        if (attackerPlayer == nullptr)
            return;

        OnPlayerHurt(player, attackerPlayer, dmgHealth, dmgArmor, hitgroup, weapon, (player->health->Get() - dmgHealth <= 0));
    }

    bool Internal_ShouldHearVoice(uint32_t slot)
    {
        if (!ShouldHearVoice)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return true;

        return ShouldHearVoice(player);
    }

    void Internal_OnWeaponSpawned(uint32_t slot, uint32_t weaponid)
    {
        if (!OnWeaponSpawned)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (!player)
            return;

        OnWeaponSpawned(player, player->weapons->GetWeapon(weaponid));
    }

    void Internal_OnClientKeyStateChange(uint32_t slot, const char *button, bool pressed)
    {
        if (!OnClientKeyStateChange)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (!player)
            return;

        OnClientKeyStateChange(player, button, pressed);
    }

    void Internal_OnClientExecuteCommand(uint32_t slot, const char *command)
    {
        if (!OnClientExecuteCommand)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (!player)
            return;

        OnClientExecuteCommand(player, command);
    }

    const char *GetPluginAuthor();
    const char *GetPluginVersion();
    const char *GetPluginName();
    const char *GetPluginWebsite();
}

#endif