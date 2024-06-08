#include "../../../core/scripting/generated/classes/GCNetworkVarChainer.h"
#include "../core.h"

void SetupLuaClassGCNetworkVarChainer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkVarChainer>("CNetworkVarChainer")
        .addProperty("PathIndex", &GCNetworkVarChainer::GetPathIndex, &GCNetworkVarChainer::SetPathIndex)
        .endClass();
}