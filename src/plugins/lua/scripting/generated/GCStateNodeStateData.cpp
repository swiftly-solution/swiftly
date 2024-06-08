#include "../../../core/scripting/generated/classes/GCStateNodeStateData.h"
#include "../core.h"

void SetupLuaClassGCStateNodeStateData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStateNodeStateData>("CStateNodeStateData")
        .addProperty("Child", &GCStateNodeStateData::GetChild, &GCStateNodeStateData::SetChild)
        .endClass();
}