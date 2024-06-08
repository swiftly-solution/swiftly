#include "../../../core/scripting/generated/classes/GCScriptTriggerPush.h"
#include "../core.h"

void SetupLuaClassGCScriptTriggerPush(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptTriggerPush>("CScriptTriggerPush")
        .addProperty("Extent", &GCScriptTriggerPush::GetExtent, &GCScriptTriggerPush::SetExtent)
        .endClass();
}