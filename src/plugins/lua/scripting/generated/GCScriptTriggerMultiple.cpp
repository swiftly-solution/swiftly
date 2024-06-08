#include "../../../core/scripting/generated/classes/GCScriptTriggerMultiple.h"
#include "../core.h"

void SetupLuaClassGCScriptTriggerMultiple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptTriggerMultiple>("CScriptTriggerMultiple")
        .addProperty("Extent", &GCScriptTriggerMultiple::GetExtent, &GCScriptTriggerMultiple::SetExtent)
        .endClass();
}