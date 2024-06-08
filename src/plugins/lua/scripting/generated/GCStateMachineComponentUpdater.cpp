#include "../../../core/scripting/generated/classes/GCStateMachineComponentUpdater.h"
#include "../core.h"

void SetupLuaClassGCStateMachineComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStateMachineComponentUpdater>("CStateMachineComponentUpdater")
        .addProperty("StateMachine", &GCStateMachineComponentUpdater::GetStateMachine, &GCStateMachineComponentUpdater::SetStateMachine)
        .endClass();
}