#include "../../../core/scripting/generated/classes/GCBaseIssue.h"
#include "../core.h"

void SetupLuaClassGCBaseIssue(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseIssue>("CBaseIssue")
        .addProperty("TypeString", &GCBaseIssue::GetTypeString, &GCBaseIssue::SetTypeString)
        .addProperty("DetailsString", &GCBaseIssue::GetDetailsString, &GCBaseIssue::SetDetailsString)
        .addProperty("NumYesVotes", &GCBaseIssue::GetNumYesVotes, &GCBaseIssue::SetNumYesVotes)
        .addProperty("NumNoVotes", &GCBaseIssue::GetNumNoVotes, &GCBaseIssue::SetNumNoVotes)
        .addProperty("NumPotentialVotes", &GCBaseIssue::GetNumPotentialVotes, &GCBaseIssue::SetNumPotentialVotes)
        .endClass();
}