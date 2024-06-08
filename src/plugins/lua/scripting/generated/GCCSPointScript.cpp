#include "../../../core/scripting/generated/classes/GCCSPointScript.h"
#include "../core.h"

void SetupLuaClassGCCSPointScript(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScript>("CCSPointScript")
        .addProperty("Parent", &GCCSPointScript::GetParent, &GCCSPointScript::SetParent)
        .endClass();
}