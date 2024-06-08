#include "../../../core/scripting/generated/classes/GCItemDefuser.h"
#include "../core.h"

void SetupLuaClassGCItemDefuser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemDefuser>("CItemDefuser")
        .addProperty("EntitySpottedState", &GCItemDefuser::GetEntitySpottedState, &GCItemDefuser::SetEntitySpottedState)
        .addProperty("SpotRules", &GCItemDefuser::GetSpotRules, &GCItemDefuser::SetSpotRules)
        .endClass();
}