#include "../../../core/scripting/generated/classes/GCTriggerRemove.h"
#include "../core.h"

void SetupLuaClassGCTriggerRemove(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerRemove>("CTriggerRemove")
        .addProperty("OnRemove", &GCTriggerRemove::GetOnRemove, &GCTriggerRemove::SetOnRemove)
        .endClass();
}