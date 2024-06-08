#include "../../../core/scripting/generated/classes/GCAnimNodePath.h"
#include "../core.h"

void SetupLuaClassGCAnimNodePath(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimNodePath>("CAnimNodePath")
        .addProperty("Path", &GCAnimNodePath::GetPath, &GCAnimNodePath::SetPath)
        .addProperty("Count", &GCAnimNodePath::GetCount, &GCAnimNodePath::SetCount)
        .endClass();
}