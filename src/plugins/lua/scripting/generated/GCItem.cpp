#include "../../../core/scripting/generated/classes/GCItem.h"
#include "../core.h"

void SetupLuaClassGCItem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItem>("CItem")
        .addProperty("OnPlayerTouch", &GCItem::GetOnPlayerTouch, &GCItem::SetOnPlayerTouch)
        .addProperty("OnPlayerPickup", &GCItem::GetOnPlayerPickup, &GCItem::SetOnPlayerPickup)
        .addProperty("ActivateWhenAtRest", &GCItem::GetActivateWhenAtRest, &GCItem::SetActivateWhenAtRest)
        .addProperty("OnCacheInteraction", &GCItem::GetOnCacheInteraction, &GCItem::SetOnCacheInteraction)
        .addProperty("OnGlovePulled", &GCItem::GetOnGlovePulled, &GCItem::SetOnGlovePulled)
        .addProperty("OriginalSpawnOrigin", &GCItem::GetOriginalSpawnOrigin, &GCItem::SetOriginalSpawnOrigin)
        .addProperty("OriginalSpawnAngles", &GCItem::GetOriginalSpawnAngles, &GCItem::SetOriginalSpawnAngles)
        .addProperty("PhysStartAsleep", &GCItem::GetPhysStartAsleep, &GCItem::SetPhysStartAsleep)
        .endClass();
}