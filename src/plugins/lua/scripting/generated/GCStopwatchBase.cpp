#include "../../../core/scripting/generated/classes/GCStopwatchBase.h"
#include "../core.h"

void SetupLuaClassGCStopwatchBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStopwatchBase>("CStopwatchBase")
        .addProperty("IsRunning", &GCStopwatchBase::GetIsRunning, &GCStopwatchBase::SetIsRunning)
        .endClass();
}