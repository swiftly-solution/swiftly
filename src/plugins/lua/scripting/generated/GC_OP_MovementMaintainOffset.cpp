#include "../../../core/scripting/generated/classes/GC_OP_MovementMaintainOffset.h"
#include "../core.h"

void SetupLuaClassGC_OP_MovementMaintainOffset(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_MovementMaintainOffset>("C_OP_MovementMaintainOffset")
        .addProperty("Offset", &GC_OP_MovementMaintainOffset::GetOffset, &GC_OP_MovementMaintainOffset::SetOffset)
        .addProperty("CP", &GC_OP_MovementMaintainOffset::GetCP, &GC_OP_MovementMaintainOffset::SetCP)
        .addProperty("RadiusScale", &GC_OP_MovementMaintainOffset::GetRadiusScale, &GC_OP_MovementMaintainOffset::SetRadiusScale)
        .endClass();
}