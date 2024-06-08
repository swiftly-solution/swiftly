#include "../../../core/scripting/generated/classes/GC_OP_MaxVelocity.h"
#include "../core.h"

void SetupLuaClassGC_OP_MaxVelocity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_MaxVelocity>("C_OP_MaxVelocity")
        .addProperty("MaxVelocity", &GC_OP_MaxVelocity::GetMaxVelocity, &GC_OP_MaxVelocity::SetMaxVelocity)
        .addProperty("MinVelocity", &GC_OP_MaxVelocity::GetMinVelocity, &GC_OP_MaxVelocity::SetMinVelocity)
        .addProperty("OverrideCP", &GC_OP_MaxVelocity::GetOverrideCP, &GC_OP_MaxVelocity::SetOverrideCP)
        .addProperty("OverrideCPField", &GC_OP_MaxVelocity::GetOverrideCPField, &GC_OP_MaxVelocity::SetOverrideCPField)
        .endClass();
}