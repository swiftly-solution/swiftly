#include "../../../core/scripting/generated/classes/GCCSPointScriptExtensions_weapon_cs_base.h"
#include "../core.h"

void SetupLuaClassGCCSPointScriptExtensions_weapon_cs_base(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptExtensions_weapon_cs_base>("CCSPointScriptExtensions_weapon_cs_base")

        .endClass();
}