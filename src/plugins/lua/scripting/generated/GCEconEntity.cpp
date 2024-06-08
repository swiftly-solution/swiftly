#include "../../../core/scripting/generated/classes/GCEconEntity.h"
#include "../core.h"

void SetupLuaClassGCEconEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEconEntity>("CEconEntity")
        .addProperty("AttributeManager", &GCEconEntity::GetAttributeManager, &GCEconEntity::SetAttributeManager)
        .addProperty("OriginalOwnerXuidLow", &GCEconEntity::GetOriginalOwnerXuidLow, &GCEconEntity::SetOriginalOwnerXuidLow)
        .addProperty("OriginalOwnerXuidHigh", &GCEconEntity::GetOriginalOwnerXuidHigh, &GCEconEntity::SetOriginalOwnerXuidHigh)
        .addProperty("FallbackPaintKit", &GCEconEntity::GetFallbackPaintKit, &GCEconEntity::SetFallbackPaintKit)
        .addProperty("FallbackSeed", &GCEconEntity::GetFallbackSeed, &GCEconEntity::SetFallbackSeed)
        .addProperty("FallbackWear", &GCEconEntity::GetFallbackWear, &GCEconEntity::SetFallbackWear)
        .addProperty("FallbackStatTrak", &GCEconEntity::GetFallbackStatTrak, &GCEconEntity::SetFallbackStatTrak)
        .addProperty("OldProvidee", &GCEconEntity::GetOldProvidee, &GCEconEntity::SetOldProvidee)
        .addProperty("OldOwnerClass", &GCEconEntity::GetOldOwnerClass, &GCEconEntity::SetOldOwnerClass)
        .endClass();
}