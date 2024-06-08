#include "../../../core/scripting/generated/classes/GC_OP_Cull.h"
#include "../core.h"

void SetupLuaClassGC_OP_Cull(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_Cull>("C_OP_Cull")
        .addProperty("CullPerc", &GC_OP_Cull::GetCullPerc, &GC_OP_Cull::SetCullPerc)
        .addProperty("CullStart", &GC_OP_Cull::GetCullStart, &GC_OP_Cull::SetCullStart)
        .addProperty("CullEnd", &GC_OP_Cull::GetCullEnd, &GC_OP_Cull::SetCullEnd)
        .addProperty("CullExp", &GC_OP_Cull::GetCullExp, &GC_OP_Cull::SetCullExp)
        .endClass();
}