#include "../../../core/scripting/generated/classes/GCNmTransitionEvent.h"
#include "../core.h"

void SetupLuaClassGCNmTransitionEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmTransitionEvent>("CNmTransitionEvent")
        .addProperty("Rule", &GCNmTransitionEvent::GetRule, &GCNmTransitionEvent::SetRule)
        .endClass();
}