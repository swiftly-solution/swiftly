#include "../../../core/scripting/generated/classes/GCNavLinkMovementVData.h"
#include "../core.h"

void SetupLuaClassGCNavLinkMovementVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavLinkMovementVData>("CNavLinkMovementVData")
        .addProperty("IsInterpolated", &GCNavLinkMovementVData::GetIsInterpolated, &GCNavLinkMovementVData::SetIsInterpolated)
        .addProperty("RecommendedDistance", &GCNavLinkMovementVData::GetRecommendedDistance, &GCNavLinkMovementVData::SetRecommendedDistance)
        .addProperty("AnimgraphVars", &GCNavLinkMovementVData::GetAnimgraphVars, &GCNavLinkMovementVData::SetAnimgraphVars)
        .endClass();
}