#include "../../../core/scripting/generated/classes/GC_INIT_NormalOffset.h"
#include "../core.h"

void SetupLuaClassGC_INIT_NormalOffset(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_NormalOffset>("C_INIT_NormalOffset")
        .addProperty("OffsetMin", &GC_INIT_NormalOffset::GetOffsetMin, &GC_INIT_NormalOffset::SetOffsetMin)
        .addProperty("OffsetMax", &GC_INIT_NormalOffset::GetOffsetMax, &GC_INIT_NormalOffset::SetOffsetMax)
        .addProperty("ControlPointNumber", &GC_INIT_NormalOffset::GetControlPointNumber, &GC_INIT_NormalOffset::SetControlPointNumber)
        .addProperty("LocalCoords", &GC_INIT_NormalOffset::GetLocalCoords, &GC_INIT_NormalOffset::SetLocalCoords)
        .addProperty("Normalize", &GC_INIT_NormalOffset::GetNormalize, &GC_INIT_NormalOffset::SetNormalize)
        .endClass();
}