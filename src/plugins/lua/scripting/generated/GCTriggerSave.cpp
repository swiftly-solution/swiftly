#include "../../../core/scripting/generated/classes/GCTriggerSave.h"
#include "../core.h"

void SetupLuaClassGCTriggerSave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerSave>("CTriggerSave")
        .addProperty("ForceNewLevelUnit", &GCTriggerSave::GetForceNewLevelUnit, &GCTriggerSave::SetForceNewLevelUnit)
        .addProperty("DangerousTimer", &GCTriggerSave::GetDangerousTimer, &GCTriggerSave::SetDangerousTimer)
        .addProperty("MinHitPoints", &GCTriggerSave::GetMinHitPoints, &GCTriggerSave::SetMinHitPoints)
        .endClass();
}