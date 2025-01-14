#ifndef _engine_vgui_h
#define _engine_vgui_h

#include "ScreenText.h"
#include "ScreenPanel.h"
#include <map>
#include <public/iservernetworkable.h>

class VGUI
{
private:
    uint64_t internalScreenTextID = 0;
    uint64_t internalScreenPanelID = 0;
    std::map<uint64_t, ScreenText*> screenTexts;
    std::map<uint64_t, ScreenPanel*> screenPanels;
    uint64_t rendersToSpectator = 0;

public:
    VGUI() = default;
    ~VGUI();

    uint64_t RegisterScreenText();
    ScreenText* GetScreenText(uint64_t id);
    void DeleteScreenText(uint64_t id);

    uint64_t RegisterScreenPanel();
    ScreenPanel* GetScreenPanel(uint64_t id);
    void DeleteScreenPanel(uint64_t id);
    
    void RegenerateScreenTexts();
    void RegenerateScreenPanels();

    void FilterRenderingItems(Player* player, CCheckTransmitInfo* pInfo);

    void CheckRenderForPlayer(int pid, Player* player, CHandle<CBaseEntity> specView);
    void Unregister(Player* player);
};

extern VGUI* g_pVGUI;

#endif