#include "../../../core/scripting/generated/classes/GCTeam.h"
#include "../core.h"

void SetupLuaClassGCTeam(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTeam>("CTeam")
        .addProperty("PlayerControllers", &GCTeam::GetPlayerControllers, &GCTeam::SetPlayerControllers)
        .addProperty("Players", &GCTeam::GetPlayers, &GCTeam::SetPlayers)
        .addProperty("Score", &GCTeam::GetScore, &GCTeam::SetScore)
        .addProperty("Teamname", &GCTeam::GetTeamname, &GCTeam::SetTeamname)
        .endClass();
}