#include "../../../core/scripting/generated/classes/GCLogicDistanceAutosave.h"
#include "../core.h"

void SetupLuaClassGCLogicDistanceAutosave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicDistanceAutosave>("CLogicDistanceAutosave")
        .addProperty("TargetEntity", &GCLogicDistanceAutosave::GetTargetEntity, &GCLogicDistanceAutosave::SetTargetEntity)
        .addProperty("DistanceToPlayer", &GCLogicDistanceAutosave::GetDistanceToPlayer, &GCLogicDistanceAutosave::SetDistanceToPlayer)
        .addProperty("ForceNewLevelUnit", &GCLogicDistanceAutosave::GetForceNewLevelUnit, &GCLogicDistanceAutosave::SetForceNewLevelUnit)
        .addProperty("CheckCough", &GCLogicDistanceAutosave::GetCheckCough, &GCLogicDistanceAutosave::SetCheckCough)
        .addProperty("ThinkDangerous", &GCLogicDistanceAutosave::GetThinkDangerous, &GCLogicDistanceAutosave::SetThinkDangerous)
        .addProperty("DangerousTime", &GCLogicDistanceAutosave::GetDangerousTime, &GCLogicDistanceAutosave::SetDangerousTime)
        .endClass();
}