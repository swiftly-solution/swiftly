#include "../../../core/scripting/generated/classes/GCHitBoxSetList.h"
#include "../core.h"

void SetupLuaClassGCHitBoxSetList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHitBoxSetList>("CHitBoxSetList")
        .addProperty("HitBoxSets", &GCHitBoxSetList::GetHitBoxSets, &GCHitBoxSetList::SetHitBoxSets)
        .endClass();
}