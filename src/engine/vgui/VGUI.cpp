#include "VGUI.h"

VGUI::~VGUI()
{
    for(auto it = screenTexts.begin(); it != screenTexts.end(); ++it) 
        delete it->second;
}

uint64_t VGUI::RegisterScreenText()
{
    internalScreenTextID++;
    ScreenText* txt = new ScreenText();
    screenTexts.insert({internalScreenTextID, txt});
    
    return internalScreenTextID;
}

ScreenText* VGUI::GetScreenText(uint64_t id)
{
    if(screenTexts.find(id) == screenTexts.end()) return nullptr;

    return screenTexts[id];
}

void VGUI::DeleteScreenText(uint64_t id)
{
    if(screenTexts.find(id) == screenTexts.end()) return;

    ScreenText* txt = screenTexts[id];
    delete txt;

    screenTexts.erase(id);
}

void VGUI::RegenerateScreenTexts()
{
    for(auto it = screenTexts.begin(); it != screenTexts.end(); ++it) {
        it->second->RegenerateText();
    }
}

void VGUI::FilterRenderingItems(Player* player, CCheckTransmitInfo* pInfo)
{
    #pragma omp parallel for
    for(auto it = screenTexts.begin(); it != screenTexts.end(); ++it) {
        if(it->second->GetPlayer() != player) {
            int entIndex = it->second->GetEntityIndex();
            pInfo->m_pTransmitEntity->Clear(entIndex);
            if(pInfo->m_pTransmitAlways->Get(entIndex))
                pInfo->m_pTransmitAlways->Clear(entIndex);
        }
    }
}

void VGUI::CheckRenderForPlayer(int pid, Player* player, CHandle<CBaseEntity> specView)
{
    bool shouldRegenerate = false;
    if(((rendersToSpectator & (1ULL << pid)) != 0) && !specView) {
        rendersToSpectator &= ~(1ULL << pid);
        shouldRegenerate = true;
    } else if(((rendersToSpectator & (1ULL << pid)) == 0) && specView.IsValid()) {
        rendersToSpectator |= (1ULL << pid);
        shouldRegenerate = true;
    }

    if(shouldRegenerate) {
        #pragma omp parallel for
        for(auto it = screenTexts.begin(); it != screenTexts.end(); ++it) {
            if(it->second->GetPlayer() == player) {
                it->second->RegenerateText();
                it->second->SetRenderingTo(specView.Get());
            }
        }
    } else {
        #pragma omp parallel for
        for(auto it = screenTexts.begin(); it != screenTexts.end(); ++it) {
            if(it->second->GetPlayer() == player && !it->second->IsRenderingTo(specView)) {
                it->second->RegenerateText();
                it->second->SetRenderingTo(specView.Get());
            }
        }
    }
}

void VGUI::UnregisterTexts(Player* player)
{
    std::vector<uint64_t> eraseIDs;
    for(auto it = screenTexts.begin(); it != screenTexts.end(); ++it) {
        if(it->second->GetPlayer() == player) {
            delete it->second;
            eraseIDs.push_back(it->first);
        }
    }

    for(auto id : eraseIDs)
        screenTexts.erase(id);
}