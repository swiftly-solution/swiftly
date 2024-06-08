#include "../../../core/scripting/generated/classes/GCNmFootEvent.h"
#include "../core.h"

void SetupLuaClassGCNmFootEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmFootEvent>("CNmFootEvent")
        .addProperty("Phase", &GCNmFootEvent::GetPhase, &GCNmFootEvent::SetPhase)
        .endClass();
}