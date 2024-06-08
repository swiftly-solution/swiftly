#include "../../../core/scripting/generated/classes/GC_OP_RandomForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_RandomForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RandomForce>("C_OP_RandomForce")
        .addProperty("MinForce", &GC_OP_RandomForce::GetMinForce, &GC_OP_RandomForce::SetMinForce)
        .addProperty("MaxForce", &GC_OP_RandomForce::GetMaxForce, &GC_OP_RandomForce::SetMaxForce)
        .endClass();
}