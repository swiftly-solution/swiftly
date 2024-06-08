#include "../../../core/scripting/generated/classes/GCAnimUpdateNodeRef.h"
#include "../core.h"

void SetupLuaClassGCAnimUpdateNodeRef(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimUpdateNodeRef>("CAnimUpdateNodeRef")
        .addProperty("NodeIndex", &GCAnimUpdateNodeRef::GetNodeIndex, &GCAnimUpdateNodeRef::SetNodeIndex)
        .endClass();
}