#include "../../../core/scripting/generated/classes/GCBaseFlex.h"
#include "../core.h"

void SetupLuaClassGCBaseFlex(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseFlex>("CBaseFlex")
        .addProperty("FlexWeight", &GCBaseFlex::GetFlexWeight, &GCBaseFlex::SetFlexWeight)
        .addProperty("LookTargetPosition", &GCBaseFlex::GetLookTargetPosition, &GCBaseFlex::SetLookTargetPosition)
        .addProperty("Blinktoggle", &GCBaseFlex::GetBlinktoggle, &GCBaseFlex::SetBlinktoggle)
        .addProperty("NextSceneEventId", &GCBaseFlex::GetNextSceneEventId, &GCBaseFlex::SetNextSceneEventId)
        .addProperty("UpdateLayerPriorities", &GCBaseFlex::GetUpdateLayerPriorities, &GCBaseFlex::SetUpdateLayerPriorities)
        .endClass();
}