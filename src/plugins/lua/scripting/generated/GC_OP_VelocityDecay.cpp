#include "../../../core/scripting/generated/classes/GC_OP_VelocityDecay.h"
#include "../core.h"

void SetupLuaClassGC_OP_VelocityDecay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_VelocityDecay>("C_OP_VelocityDecay")
        .addProperty("MinVelocity", &GC_OP_VelocityDecay::GetMinVelocity, &GC_OP_VelocityDecay::SetMinVelocity)
        .endClass();
}