#include "../../../core/scripting/generated/classes/GC_INIT_PositionOffsetToCP.h"
#include "../core.h"

void SetupLuaClassGC_INIT_PositionOffsetToCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_PositionOffsetToCP>("C_INIT_PositionOffsetToCP")
        .addProperty("ControlPointNumberStart", &GC_INIT_PositionOffsetToCP::GetControlPointNumberStart, &GC_INIT_PositionOffsetToCP::SetControlPointNumberStart)
        .addProperty("ControlPointNumberEnd", &GC_INIT_PositionOffsetToCP::GetControlPointNumberEnd, &GC_INIT_PositionOffsetToCP::SetControlPointNumberEnd)
        .addProperty("LocalCoords", &GC_INIT_PositionOffsetToCP::GetLocalCoords, &GC_INIT_PositionOffsetToCP::SetLocalCoords)
        .endClass();
}