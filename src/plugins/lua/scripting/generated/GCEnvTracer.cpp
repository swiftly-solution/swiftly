#include "../../../core/scripting/generated/classes/GCEnvTracer.h"
#include "../core.h"

void SetupLuaClassGCEnvTracer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvTracer>("CEnvTracer")
        .addProperty("End", &GCEnvTracer::GetEnd, &GCEnvTracer::SetEnd)
        .addProperty("Delay", &GCEnvTracer::GetDelay, &GCEnvTracer::SetDelay)
        .endClass();
}