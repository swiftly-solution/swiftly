#include "../../../core/scripting/generated/classes/GCBaseDMStart.h"
#include "../core.h"

void SetupLuaClassGCBaseDMStart(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseDMStart>("CBaseDMStart")
        .addProperty("Master", &GCBaseDMStart::GetMaster, &GCBaseDMStart::SetMaster)
        .endClass();
}