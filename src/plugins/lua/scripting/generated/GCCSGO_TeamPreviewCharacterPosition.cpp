#include "../../../core/scripting/generated/classes/GCCSGO_TeamPreviewCharacterPosition.h"
#include "../core.h"

void SetupLuaClassGCCSGO_TeamPreviewCharacterPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamPreviewCharacterPosition>("CCSGO_TeamPreviewCharacterPosition")
        .addProperty("Variant", &GCCSGO_TeamPreviewCharacterPosition::GetVariant, &GCCSGO_TeamPreviewCharacterPosition::SetVariant)
        .addProperty("Random", &GCCSGO_TeamPreviewCharacterPosition::GetRandom, &GCCSGO_TeamPreviewCharacterPosition::SetRandom)
        .addProperty("Ordinal", &GCCSGO_TeamPreviewCharacterPosition::GetOrdinal, &GCCSGO_TeamPreviewCharacterPosition::SetOrdinal)
        .addProperty("WeaponName", &GCCSGO_TeamPreviewCharacterPosition::GetWeaponName, &GCCSGO_TeamPreviewCharacterPosition::SetWeaponName)
        .addProperty("Xuid", &GCCSGO_TeamPreviewCharacterPosition::GetXuid, &GCCSGO_TeamPreviewCharacterPosition::SetXuid)
        .addProperty("AgentItem", &GCCSGO_TeamPreviewCharacterPosition::GetAgentItem, &GCCSGO_TeamPreviewCharacterPosition::SetAgentItem)
        .addProperty("GlovesItem", &GCCSGO_TeamPreviewCharacterPosition::GetGlovesItem, &GCCSGO_TeamPreviewCharacterPosition::SetGlovesItem)
        .addProperty("WeaponItem", &GCCSGO_TeamPreviewCharacterPosition::GetWeaponItem, &GCCSGO_TeamPreviewCharacterPosition::SetWeaponItem)
        .endClass();
}