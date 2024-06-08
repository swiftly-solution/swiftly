#include "../../../core/scripting/generated/classes/GCCSGameModeRules_Deathmatch.h"
#include "../core.h"

void SetupLuaClassGCCSGameModeRules_Deathmatch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGameModeRules_Deathmatch>("CCSGameModeRules_Deathmatch")
        .addProperty("DMBonusTimeLength", &GCCSGameModeRules_Deathmatch::GetDMBonusTimeLength, &GCCSGameModeRules_Deathmatch::SetDMBonusTimeLength)
        .addProperty("DMBonusWeapon", &GCCSGameModeRules_Deathmatch::GetDMBonusWeapon, &GCCSGameModeRules_Deathmatch::SetDMBonusWeapon)
        .endClass();
}