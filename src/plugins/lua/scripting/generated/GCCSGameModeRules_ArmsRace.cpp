#include "../../../core/scripting/generated/classes/GCCSGameModeRules_ArmsRace.h"
#include "../core.h"

void SetupLuaClassGCCSGameModeRules_ArmsRace(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGameModeRules_ArmsRace>("CCSGameModeRules_ArmsRace")
        .addProperty("WeaponSequence", &GCCSGameModeRules_ArmsRace::GetWeaponSequence, &GCCSGameModeRules_ArmsRace::SetWeaponSequence)
        .endClass();
}