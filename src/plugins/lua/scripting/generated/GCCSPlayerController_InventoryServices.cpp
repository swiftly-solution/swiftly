#include "../../../core/scripting/generated/classes/GCCSPlayerController_InventoryServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayerController_InventoryServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerController_InventoryServices>("CCSPlayerController_InventoryServices")
        .addProperty("MusicID", &GCCSPlayerController_InventoryServices::GetMusicID, &GCCSPlayerController_InventoryServices::SetMusicID)
        .addProperty("Rank", &GCCSPlayerController_InventoryServices::GetRank, &GCCSPlayerController_InventoryServices::SetRank)
        .addProperty("PersonaDataPublicLevel", &GCCSPlayerController_InventoryServices::GetPersonaDataPublicLevel, &GCCSPlayerController_InventoryServices::SetPersonaDataPublicLevel)
        .addProperty("PersonaDataPublicCommendsLeader", &GCCSPlayerController_InventoryServices::GetPersonaDataPublicCommendsLeader, &GCCSPlayerController_InventoryServices::SetPersonaDataPublicCommendsLeader)
        .addProperty("PersonaDataPublicCommendsTeacher", &GCCSPlayerController_InventoryServices::GetPersonaDataPublicCommendsTeacher, &GCCSPlayerController_InventoryServices::SetPersonaDataPublicCommendsTeacher)
        .addProperty("PersonaDataPublicCommendsFriendly", &GCCSPlayerController_InventoryServices::GetPersonaDataPublicCommendsFriendly, &GCCSPlayerController_InventoryServices::SetPersonaDataPublicCommendsFriendly)
        .addProperty("PersonaDataXpTrailLevel", &GCCSPlayerController_InventoryServices::GetPersonaDataXpTrailLevel, &GCCSPlayerController_InventoryServices::SetPersonaDataXpTrailLevel)
        .addProperty("EquippedPlayerSprayIDs", &GCCSPlayerController_InventoryServices::GetEquippedPlayerSprayIDs, &GCCSPlayerController_InventoryServices::SetEquippedPlayerSprayIDs)
        .addProperty("ServerAuthoritativeWeaponSlots", &GCCSPlayerController_InventoryServices::GetServerAuthoritativeWeaponSlots, &GCCSPlayerController_InventoryServices::SetServerAuthoritativeWeaponSlots)
        .endClass();
}