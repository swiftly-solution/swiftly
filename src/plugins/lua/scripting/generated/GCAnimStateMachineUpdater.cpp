#include "../../../core/scripting/generated/classes/GCAnimStateMachineUpdater.h"
#include "../core.h"

void SetupLuaClassGCAnimStateMachineUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimStateMachineUpdater>("CAnimStateMachineUpdater")
        .addProperty("States", &GCAnimStateMachineUpdater::GetStates, &GCAnimStateMachineUpdater::SetStates)
        .addProperty("Transitions", &GCAnimStateMachineUpdater::GetTransitions, &GCAnimStateMachineUpdater::SetTransitions)
        .addProperty("StartStateIndex", &GCAnimStateMachineUpdater::GetStartStateIndex, &GCAnimStateMachineUpdater::SetStartStateIndex)
        .endClass();
}