#include "../../../core/scripting/generated/classes/GCScriptTriggerOnce.h"
#include "../core.h"

void SetupLuaClassGCScriptTriggerOnce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptTriggerOnce>("CScriptTriggerOnce")
        .addProperty("Extent", &GCScriptTriggerOnce::GetExtent, &GCScriptTriggerOnce::SetExtent)
        .endClass();
}