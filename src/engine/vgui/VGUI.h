/***************************************************************************************
 * Credits for VGUI
 * @electronix - Method for static rendering of a text using predicted_viewmodel
 * @Nyano1337 - Methods for background and text spawning in the world + attachment
 *      - https://github.com/CS2Surf-CN/Timer
 * @Kxnrl - FyS Server Menu Background Color
****************************************************************************************/

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
    void Unregister(Player* player);
};

extern VGUI* g_pVGUI;

#endif