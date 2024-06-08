#include "../../../core/scripting/generated/classes/GCInfoGameEventProxy.h"
#include "../core.h"

void SetupLuaClassGCInfoGameEventProxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoGameEventProxy>("CInfoGameEventProxy")
        .addProperty("EventName", &GCInfoGameEventProxy::GetEventName, &GCInfoGameEventProxy::SetEventName)
        .addProperty("Range", &GCInfoGameEventProxy::GetRange, &GCInfoGameEventProxy::SetRange)
        .endClass();
}