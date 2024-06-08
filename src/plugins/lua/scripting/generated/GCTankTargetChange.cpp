#include "../../../core/scripting/generated/classes/GCTankTargetChange.h"
#include "../core.h"

void SetupLuaClassGCTankTargetChange(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTankTargetChange>("CTankTargetChange")
        .addProperty("NewTargetName", &GCTankTargetChange::GetNewTargetName, &GCTankTargetChange::SetNewTargetName)
        .endClass();
}