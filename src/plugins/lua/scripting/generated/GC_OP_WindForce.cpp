#include "../../../core/scripting/generated/classes/GC_OP_WindForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_WindForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_WindForce>("C_OP_WindForce")
        .addProperty("Force", &GC_OP_WindForce::GetForce, &GC_OP_WindForce::SetForce)
        .endClass();
}