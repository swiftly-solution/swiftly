#include "../../../core/scripting/generated/classes/GCGameGibManager.h"
#include "../core.h"

void SetupLuaClassGCGameGibManager(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameGibManager>("CGameGibManager")
        .addProperty("AllowNewGibs", &GCGameGibManager::GetAllowNewGibs, &GCGameGibManager::SetAllowNewGibs)
        .addProperty("CurrentMaxPieces", &GCGameGibManager::GetCurrentMaxPieces, &GCGameGibManager::SetCurrentMaxPieces)
        .addProperty("MaxPieces", &GCGameGibManager::GetMaxPieces, &GCGameGibManager::SetMaxPieces)
        .addProperty("LastFrame", &GCGameGibManager::GetLastFrame, &GCGameGibManager::SetLastFrame)
        .endClass();
}