#include "../../../core/scripting/generated/classes/GCScriptTriggerHurt.h"
#include "../core.h"

void SetupLuaClassGCScriptTriggerHurt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptTriggerHurt>("CScriptTriggerHurt")
        .addProperty("Extent", &GCScriptTriggerHurt::GetExtent, &GCScriptTriggerHurt::SetExtent)
        .endClass();
}