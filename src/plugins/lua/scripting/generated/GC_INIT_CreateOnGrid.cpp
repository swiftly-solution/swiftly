#include "../../../core/scripting/generated/classes/GC_INIT_CreateOnGrid.h"
#include "../core.h"

void SetupLuaClassGC_INIT_CreateOnGrid(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_CreateOnGrid>("C_INIT_CreateOnGrid")
        .addProperty("XCount", &GC_INIT_CreateOnGrid::GetXCount, &GC_INIT_CreateOnGrid::SetXCount)
        .addProperty("YCount", &GC_INIT_CreateOnGrid::GetYCount, &GC_INIT_CreateOnGrid::SetYCount)
        .addProperty("ZCount", &GC_INIT_CreateOnGrid::GetZCount, &GC_INIT_CreateOnGrid::SetZCount)
        .addProperty("XSpacing", &GC_INIT_CreateOnGrid::GetXSpacing, &GC_INIT_CreateOnGrid::SetXSpacing)
        .addProperty("YSpacing", &GC_INIT_CreateOnGrid::GetYSpacing, &GC_INIT_CreateOnGrid::SetYSpacing)
        .addProperty("ZSpacing", &GC_INIT_CreateOnGrid::GetZSpacing, &GC_INIT_CreateOnGrid::SetZSpacing)
        .addProperty("ControlPointNumber", &GC_INIT_CreateOnGrid::GetControlPointNumber, &GC_INIT_CreateOnGrid::SetControlPointNumber)
        .addProperty("LocalSpace", &GC_INIT_CreateOnGrid::GetLocalSpace, &GC_INIT_CreateOnGrid::SetLocalSpace)
        .addProperty("Center", &GC_INIT_CreateOnGrid::GetCenter, &GC_INIT_CreateOnGrid::SetCenter)
        .addProperty("Hollow", &GC_INIT_CreateOnGrid::GetHollow, &GC_INIT_CreateOnGrid::SetHollow)
        .endClass();
}