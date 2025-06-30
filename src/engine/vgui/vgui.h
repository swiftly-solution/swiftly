#ifndef _engine_vgui_vgui_h
#define _engine_vgui_vgui_h

#include <map>
#include <server/player/player.h>
#include "ehandle.h"
#include "screentext.h"

class VGUI
{
private:
    uint64_t internalScreenTextID = 0;
    std::map<uint64_t, ScreenText*> screenTexts;
    uint64_t rendersToSpectator = 0;

public:
    ~VGUI();

    uint64_t RegisterScreenText();
    ScreenText* GetScreenText(uint64_t id);
    void DeleteScreenText(uint64_t id);

    void RegenerateScreenTexts();
    void ResetStateOfScreenTexts();

    void FilterRenderingItems(Player* player, CCheckTransmitInfo* pInfo);

    void CheckRenderForPlayer(int pid, Player* player, CHandle<CEntityInstance> specView);
    void Unregister(Player* player);

    void Initialize();
    void Shutdown();

    void CheckTransmit(CCheckTransmitInfo** ppInfoList, int infoCount, CBitVec<16384>& unionTransmitEdicts, const Entity2Networkable_t** pNetworkables, const uint16_t* pEntityIndicies, int nEntities, bool bEnablePVSBits);
};

extern VGUI g_VGUI;

#endif