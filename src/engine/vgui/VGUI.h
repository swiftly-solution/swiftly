#ifndef _engine_vgui_h
#define _engine_vgui_h

#include "ScreenText.h"
#include <map>
#include <public/iservernetworkable.h>

class VGUI
{
private:
    uint64_t internalScreenTextID = 0;
    std::map<uint64_t, ScreenText*> screenTexts;
    uint64_t rendersToSpectator = 0;

public:
    VGUI() = default;
    ~VGUI();

    uint64_t RegisterScreenText();
    ScreenText* GetScreenText(uint64_t id);
    void DeleteScreenText(uint64_t id);
    
    void RegenerateScreenTexts();
    void FilterRenderingItems(Player* player, CCheckTransmitInfo* pInfo);

    void CheckRenderForPlayer(int pid, Player* player, CHandle<CBaseEntity> specView);
    void UnregisterTexts(Player* player);
};

extern VGUI* g_pVGUI;

#endif