#include "../../../core/scripting/generated/classes/GCResponseQueue.h"
#include "../core.h"

void SetupLuaClassGCResponseQueue(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCResponseQueue>("CResponseQueue")
        .addProperty("ExpresserTargets", &GCResponseQueue::GetExpresserTargets, &GCResponseQueue::SetExpresserTargets)
        .endClass();
}