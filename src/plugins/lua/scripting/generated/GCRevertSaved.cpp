#include "../../../core/scripting/generated/classes/GCRevertSaved.h"
#include "../core.h"

void SetupLuaClassGCRevertSaved(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRevertSaved>("CRevertSaved")
        .addProperty("LoadTime", &GCRevertSaved::GetLoadTime, &GCRevertSaved::SetLoadTime)
        .addProperty("Duration", &GCRevertSaved::GetDuration, &GCRevertSaved::SetDuration)
        .addProperty("HoldTime", &GCRevertSaved::GetHoldTime, &GCRevertSaved::SetHoldTime)
        .endClass();
}