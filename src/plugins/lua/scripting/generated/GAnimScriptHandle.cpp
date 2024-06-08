#include "../../../core/scripting/generated/classes/GAnimScriptHandle.h"
#include "../core.h"

void SetupLuaClassGAnimScriptHandle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimScriptHandle>("AnimScriptHandle")
        .addProperty("Id", &GAnimScriptHandle::GetId, &GAnimScriptHandle::SetId)
        .endClass();
}