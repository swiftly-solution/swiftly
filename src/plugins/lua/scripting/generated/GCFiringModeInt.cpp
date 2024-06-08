#include "../../../core/scripting/generated/classes/GCFiringModeInt.h"
#include "../core.h"

void SetupLuaClassGCFiringModeInt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFiringModeInt>("CFiringModeInt")
        .addProperty("Values", &GCFiringModeInt::GetValues, &GCFiringModeInt::SetValues)
        .endClass();
}