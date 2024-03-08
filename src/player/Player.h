#ifndef _player_h
#define _player_h

#include "../sdk/entity/CBasePlayerController.h"
#include "../sdk/entity/CCSPlayerController.h"
#include "../sdk/entity/CBasePlayerPawn.h"
#include "../sdk/entity/CCSPlayerPawn.h"
#include "../sdk/entity/CCSPlayerPawnBase.h"
#include "../menus/Menu.h"

#include <public/mathlib/vector.h>
#include <public/playerslot.h>
#include <ctime>
#include <any>

#define HUD_PRINTNOTIFY 1
#define HUD_PRINTCONSOLE 2
#define HUD_PRINTTALK 3
#define HUD_PRINTCENTER 4

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

    void SetClientConvar(std::string cmd, std::string val);

    std::any GetInternalVar(std::string name);
    void SetInternalVar(std::string name, std::any value);

    CBasePlayerWeapon *GetPlayerWeaponFromSlot(gear_slot_t slot);
    CBasePlayerWeapon *GetPlayerWeaponFromID(uint32 weaponid);

    void SetButtons(uint64_t new_buttons);
    uint64_t GetButtons();
    bool IsButtonPressed(uint64_t but);

    void ShowMenu(std::string menuid);
    void RenderMenu();
    void HideMenu();
    bool HasMenuShown() { return (this->menu != nullptr); }
    Menu *GetMenu() { return this->menu; }

    int GetPage() { return this->page; }
    void SetPage(int pg)
    {
        this->page = pg;
        this->selected = 0;
    }
    int GetSelection() { return this->selected; }
    void MoveSelection()
    {
        if (this->page == 0)
            return;

        int itemsPerPage = this->menu->GetItemsOnPage(this->page);
        ++this->selected;
        if (itemsPerPage == this->selected)
            this->selected = 0;
    }

    void RenderCenterText();

    std::string tag = "";
    std::string tagcolor = "{default}";
    std::string namecolor = "{teamcolor}";
    std::string chatcolor = "{default}";

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

    Menu *menu = nullptr;
    int page = 0;
    int selected = 0;

    uint64_t buttons = 0;

    std::map<std::string, std::any> internalVars;

    uint64_t centerMessageEndTime = 0;
    std::string centerMessageText;
};

#endif