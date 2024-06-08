#include "../../../core/scripting/generated/classes/GC_OP_ConstrainLineLength.h"
#include "../core.h"

void SetupLuaClassGC_OP_ConstrainLineLength(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ConstrainLineLength>("C_OP_ConstrainLineLength")
        .addProperty("MinDistance", &GC_OP_ConstrainLineLength::GetMinDistance, &GC_OP_ConstrainLineLength::SetMinDistance)
        .addProperty("MaxDistance", &GC_OP_ConstrainLineLength::GetMaxDistance, &GC_OP_ConstrainLineLength::SetMaxDistance)
        .endClass();
}