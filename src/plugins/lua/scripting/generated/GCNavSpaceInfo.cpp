#include "../../../core/scripting/generated/classes/GCNavSpaceInfo.h"
#include "../core.h"

void SetupLuaClassGCNavSpaceInfo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavSpaceInfo>("CNavSpaceInfo")
        .addProperty("CreateFlightSpace", &GCNavSpaceInfo::GetCreateFlightSpace, &GCNavSpaceInfo::SetCreateFlightSpace)
        .endClass();
}