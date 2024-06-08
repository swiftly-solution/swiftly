#include "../../../core/scripting/generated/classes/GC_OP_SDFForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_SDFForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SDFForce>("C_OP_SDFForce")
        .addProperty("ForceScale", &GC_OP_SDFForce::GetForceScale, &GC_OP_SDFForce::SetForceScale)
        .endClass();
}