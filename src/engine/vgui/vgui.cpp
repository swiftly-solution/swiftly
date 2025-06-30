/***************************************************************************************
 * Credits for VGUI
 * @electronix - Method for static rendering of a text using predicted_viewmodel
 * @Nyano1337 - Methods for background and text spawning in the world + attachment
 *      - https://github.com/CS2Surf-CN/Timer
 * @Kxnrl - FyS Server Menu Background Color
****************************************************************************************/

#include "vgui.h"

#include <core/entrypoint.h>
#include <sdk/components/EntityCheckTransmit.h>
#include <server/player/manager.h>
#include <plugins/manager.h>

SH_DECL_EXTERN7_void(ISource2GameEntities, CheckTransmit, SH_NOATTRIB, 0, CCheckTransmitInfo**, int, CBitVec<16384>&, const Entity2Networkable_t**, const uint16_t*, int, bool);

VGUI::~VGUI()
{
    for (auto it = screenTexts.begin(); it != screenTexts.end(); ++it)
        delete it->second;
}

uint64_t VGUI::RegisterScreenText()
{
    internalScreenTextID++;
    ScreenText* txt = new ScreenText();
    screenTexts.insert({ internalScreenTextID, txt });

    return internalScreenTextID;
}

ScreenText* VGUI::GetScreenText(uint64_t id)
{
    if (screenTexts.find(id) == screenTexts.end()) return nullptr;

    return screenTexts[id];
}

void VGUI::DeleteScreenText(uint64_t id)
{
    if (screenTexts.find(id) == screenTexts.end()) return;

    ScreenText* txt = screenTexts[id];
    delete txt;

    screenTexts.erase(id);
}

void VGUI::ResetStateOfScreenTexts()
{
    for (auto it = screenTexts.begin(); it != screenTexts.end(); ++it) {
        it->second->ResetSpawnState();
    }
}

void VGUI::RegenerateScreenTexts()
{
    for (auto it = screenTexts.begin(); it != screenTexts.end(); ++it) {
        it->second->RegenerateText();
    }
}

void VGUI::FilterRenderingItems(Player* player, CCheckTransmitInfo* pInfo)
{
    for (auto it = screenTexts.begin(); it != screenTexts.end(); ++it) {
        if (it->second->GetPlayer() != player) {
            int entIndex = it->second->GetEntityIndex();
            pInfo->m_pTransmitEntity->Clear(entIndex);
            if (pInfo->m_pTransmitAlways->Get(entIndex))
                pInfo->m_pTransmitAlways->Clear(entIndex);
        }
    }
}

void VGUI::CheckRenderForPlayer(int pid, Player* player, CHandle<CEntityInstance> specView)
{
    bool shouldRegenerate = false;
    if (((rendersToSpectator & (1ULL << pid)) != 0) && !specView) {
        rendersToSpectator &= ~(1ULL << pid);
        shouldRegenerate = true;
    }
    else if (((rendersToSpectator & (1ULL << pid)) == 0) && specView.IsValid()) {
        rendersToSpectator |= (1ULL << pid);
        shouldRegenerate = true;
    }

    if (shouldRegenerate) {
        for (auto it = screenTexts.begin(); it != screenTexts.end(); ++it) {
            if (it->second->GetPlayer() == player) {
                it->second->RegenerateText(false);
                it->second->SetRenderingTo(specView.Get());
            }
        }
    }
    else {
        for (auto it = screenTexts.begin(); it != screenTexts.end(); ++it) {
            if (it->second->GetPlayer() == player && !it->second->IsRenderingTo(specView)) {
                it->second->RegenerateText(false);
                it->second->SetRenderingTo(specView.Get());
            }
        }
    }
}

void VGUI::Unregister(Player* player)
{
    std::vector<uint64_t> eraseIDs;
    for (auto it = screenTexts.begin(); it != screenTexts.end(); ++it) {
        if (it->second->GetPlayer() == player) {
            delete it->second;
            eraseIDs.push_back(it->first);
        }
    }

    for (auto id : eraseIDs)
        screenTexts.erase(id);
}

void VGUI::Initialize()
{
    SH_ADD_HOOK_MEMFUNC(ISource2GameEntities, CheckTransmit, g_pSource2GameEntities, this, &VGUI::CheckTransmit, true);
}

void VGUI::Shutdown()
{
    SH_REMOVE_HOOK_MEMFUNC(ISource2GameEntities, CheckTransmit, g_pSource2GameEntities, this, &VGUI::CheckTransmit, true);
}

ClassData* checktransmitEvent = new ClassData({ {"plugin_name", std::string("core")} }, "Event", nullptr);

void VGUI::CheckTransmit(CCheckTransmitInfo** ppInfoList, int infoCount, CBitVec<16384>& unionTransmitEdicts, const Entity2Networkable_t** pNetworkables, const uint16_t* pEntityIndicies, int nEntities, bool bEnablePVSBits)
{
    if (!g_pGameEntitySystem) return;

    for (int i = 0; i < infoCount; i++)
    {
        auto& pInfo = (EntityCheckTransmit*&)ppInfoList[i];
        int playerid = pInfo->m_nClientEntityIndex.Get();
        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) continue;

        ClassData* tInfo = new ClassData({ { "transmit_ptr", (void*)pInfo } }, "CCheckTransmitInfo", nullptr);
        g_pluginManager.ExecuteEvent("core", "OnPlayerCheckTransmit", { playerid, tInfo }, checktransmitEvent);
        delete tInfo;

        FilterRenderingItems(player, (CCheckTransmitInfo*)pInfo);
    }
}