#include "../../../core/scripting/generated/classes/GCEnvWindShared__WindAveEvent_t.h"
#include "../core.h"

void SetupLuaClassGCEnvWindShared__WindAveEvent_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvWindShared__WindAveEvent_t>("CEnvWindShared__WindAveEvent_t")
        .addProperty("StartWindSpeed", &GCEnvWindShared__WindAveEvent_t::GetStartWindSpeed, &GCEnvWindShared__WindAveEvent_t::SetStartWindSpeed)
        .addProperty("AveWindSpeed", &GCEnvWindShared__WindAveEvent_t::GetAveWindSpeed, &GCEnvWindShared__WindAveEvent_t::SetAveWindSpeed)
        .endClass();
}