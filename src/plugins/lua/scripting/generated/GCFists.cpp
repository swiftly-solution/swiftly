#include "../../../core/scripting/generated/classes/GCFists.h"
#include "../core.h"

void SetupLuaClassGCFists(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFists>("CFists")
        .addProperty("PlayingUninterruptableAct", &GCFists::GetPlayingUninterruptableAct, &GCFists::SetPlayingUninterruptableAct)
        .addProperty("UninterruptableActivity", &GCFists::GetUninterruptableActivity, &GCFists::SetUninterruptableActivity)
        .addProperty("RestorePrevWep", &GCFists::GetRestorePrevWep, &GCFists::SetRestorePrevWep)
        .addProperty("WeaponBeforePrevious", &GCFists::GetWeaponBeforePrevious, &GCFists::SetWeaponBeforePrevious)
        .addProperty("WeaponPrevious", &GCFists::GetWeaponPrevious, &GCFists::SetWeaponPrevious)
        .addProperty("DelayedHardPunchIncoming", &GCFists::GetDelayedHardPunchIncoming, &GCFists::SetDelayedHardPunchIncoming)
        .addProperty("DestroyAfterTaunt", &GCFists::GetDestroyAfterTaunt, &GCFists::SetDestroyAfterTaunt)
        .endClass();
}