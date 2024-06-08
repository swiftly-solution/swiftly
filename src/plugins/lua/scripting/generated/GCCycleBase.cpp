#include "../../../core/scripting/generated/classes/GCCycleBase.h"
#include "../core.h"

void SetupLuaClassGCCycleBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCycleBase>("CCycleBase")
        .addProperty("Cycle", &GCCycleBase::GetCycle, &GCCycleBase::SetCycle)
        .endClass();
}