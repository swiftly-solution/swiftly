#include "../../../core/scripting/generated/classes/GCFiringModeFloat.h"
#include "../core.h"

void SetupLuaClassGCFiringModeFloat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFiringModeFloat>("CFiringModeFloat")
        .addProperty("Values", &GCFiringModeFloat::GetValues, &GCFiringModeFloat::SetValues)
        .endClass();
}