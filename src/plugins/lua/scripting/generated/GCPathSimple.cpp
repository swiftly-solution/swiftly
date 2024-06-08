#include "../../../core/scripting/generated/classes/GCPathSimple.h"
#include "../core.h"

void SetupLuaClassGCPathSimple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathSimple>("CPathSimple")
        .addProperty("PathString", &GCPathSimple::GetPathString, &GCPathSimple::SetPathString)
        .endClass();
}