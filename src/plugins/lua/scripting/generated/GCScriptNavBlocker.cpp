#include "../../../core/scripting/generated/classes/GCScriptNavBlocker.h"
#include "../core.h"

void SetupLuaClassGCScriptNavBlocker(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptNavBlocker>("CScriptNavBlocker")
        .addProperty("Extent", &GCScriptNavBlocker::GetExtent, &GCScriptNavBlocker::SetExtent)
        .endClass();
}