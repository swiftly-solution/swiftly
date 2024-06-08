class GCTeam;

#ifndef _gccteam_h
#define _gccteam_h

#include "../../../scripting.h"


#include "GCBasePlayerController.h"
#include "GCBasePlayerPawn.h"

class GCTeam
{
private:
    void *m_ptr;

public:
    GCTeam() {}
    GCTeam(void *ptr) : m_ptr(ptr) {}

    GCBasePlayerController* GetPlayerControllers() const { return GetSchemaValue<GCBasePlayerController*>(m_ptr, "CTeam", "m_aPlayerControllers"); }
    void SetPlayerControllers(GCBasePlayerController* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PlayerControllers' is not possible.\n"); }
    GCBasePlayerPawn* GetPlayers() const { return GetSchemaValue<GCBasePlayerPawn*>(m_ptr, "CTeam", "m_aPlayers"); }
    void SetPlayers(GCBasePlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Players' is not possible.\n"); }
    int32_t GetScore() const { return GetSchemaValue<int32_t>(m_ptr, "CTeam", "m_iScore"); }
    void SetScore(int32_t value) { SetSchemaValue(m_ptr, "CTeam", "m_iScore", false, value); }
    std::string GetTeamname() const { return GetSchemaValue<char*>(m_ptr, "CTeam", "m_szTeamname"); }
    void SetTeamname(std::string value) { SetSchemaValue(m_ptr, "CTeam", "m_szTeamname", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif