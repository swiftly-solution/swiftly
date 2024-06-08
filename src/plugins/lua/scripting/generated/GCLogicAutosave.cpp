#include "../../../core/scripting/generated/classes/GCLogicAutosave.h"
#include "../core.h"

void SetupLuaClassGCLogicAutosave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicAutosave>("CLogicAutosave")
        .addProperty("ForceNewLevelUnit", &GCLogicAutosave::GetForceNewLevelUnit, &GCLogicAutosave::SetForceNewLevelUnit)
        .addProperty("MinHitPoints", &GCLogicAutosave::GetMinHitPoints, &GCLogicAutosave::SetMinHitPoints)
        .addProperty("MinHitPointsToCommit", &GCLogicAutosave::GetMinHitPointsToCommit, &GCLogicAutosave::SetMinHitPointsToCommit)
        .endClass();
}