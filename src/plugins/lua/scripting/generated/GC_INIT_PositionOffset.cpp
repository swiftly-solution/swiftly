#include "../../../core/scripting/generated/classes/GC_INIT_PositionOffset.h"
#include "../core.h"

void SetupLuaClassGC_INIT_PositionOffset(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_PositionOffset>("C_INIT_PositionOffset")
        .addProperty("OffsetMin", &GC_INIT_PositionOffset::GetOffsetMin, &GC_INIT_PositionOffset::SetOffsetMin)
        .addProperty("OffsetMax", &GC_INIT_PositionOffset::GetOffsetMax, &GC_INIT_PositionOffset::SetOffsetMax)
        .addProperty("TransformInput", &GC_INIT_PositionOffset::GetTransformInput, &GC_INIT_PositionOffset::SetTransformInput)
        .addProperty("LocalCoords", &GC_INIT_PositionOffset::GetLocalCoords, &GC_INIT_PositionOffset::SetLocalCoords)
        .addProperty("Proportional", &GC_INIT_PositionOffset::GetProportional, &GC_INIT_PositionOffset::SetProportional)
        .addProperty("RandomnessParameters", &GC_INIT_PositionOffset::GetRandomnessParameters, &GC_INIT_PositionOffset::SetRandomnessParameters)
        .endClass();
}