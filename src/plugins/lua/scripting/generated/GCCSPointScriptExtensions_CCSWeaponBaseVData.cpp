#include "../../../core/scripting/generated/classes/GCCSPointScriptExtensions_CCSWeaponBaseVData.h"
#include "../core.h"

void SetupLuaClassGCCSPointScriptExtensions_CCSWeaponBaseVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPointScriptExtensions_CCSWeaponBaseVData>("CCSPointScriptExtensions_CCSWeaponBaseVData")

        .endClass();
}