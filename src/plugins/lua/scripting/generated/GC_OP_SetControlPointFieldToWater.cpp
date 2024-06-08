#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointFieldToWater.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointFieldToWater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointFieldToWater>("C_OP_SetControlPointFieldToWater")
        .addProperty("SourceCP", &GC_OP_SetControlPointFieldToWater::GetSourceCP, &GC_OP_SetControlPointFieldToWater::SetSourceCP)
        .addProperty("DestCP", &GC_OP_SetControlPointFieldToWater::GetDestCP, &GC_OP_SetControlPointFieldToWater::SetDestCP)
        .addProperty("CPField", &GC_OP_SetControlPointFieldToWater::GetCPField, &GC_OP_SetControlPointFieldToWater::SetCPField)
        .endClass();
}