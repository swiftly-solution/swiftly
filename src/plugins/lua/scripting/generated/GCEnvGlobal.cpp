#include "../../../core/scripting/generated/classes/GCEnvGlobal.h"
#include "../core.h"

void SetupLuaClassGCEnvGlobal(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvGlobal>("CEnvGlobal")
        .addProperty("Globalstate", &GCEnvGlobal::GetGlobalstate, &GCEnvGlobal::SetGlobalstate)
        .addProperty("Triggermode", &GCEnvGlobal::GetTriggermode, &GCEnvGlobal::SetTriggermode)
        .addProperty("Initialstate", &GCEnvGlobal::GetInitialstate, &GCEnvGlobal::SetInitialstate)
        .addProperty("Counter", &GCEnvGlobal::GetCounter, &GCEnvGlobal::SetCounter)
        .endClass();
}