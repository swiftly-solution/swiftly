#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointOrientation.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointOrientation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointOrientation>("C_OP_SetControlPointOrientation")
        .addProperty("UseWorldLocation", &GC_OP_SetControlPointOrientation::GetUseWorldLocation, &GC_OP_SetControlPointOrientation::SetUseWorldLocation)
        .addProperty("Randomize", &GC_OP_SetControlPointOrientation::GetRandomize, &GC_OP_SetControlPointOrientation::SetRandomize)
        .addProperty("SetOnce", &GC_OP_SetControlPointOrientation::GetSetOnce, &GC_OP_SetControlPointOrientation::SetSetOnce)
        .addProperty("CP", &GC_OP_SetControlPointOrientation::GetCP, &GC_OP_SetControlPointOrientation::SetCP)
        .addProperty("HeadLocation", &GC_OP_SetControlPointOrientation::GetHeadLocation, &GC_OP_SetControlPointOrientation::SetHeadLocation)
        .addProperty("Rotation", &GC_OP_SetControlPointOrientation::GetRotation, &GC_OP_SetControlPointOrientation::SetRotation)
        .addProperty("RotationB", &GC_OP_SetControlPointOrientation::GetRotationB, &GC_OP_SetControlPointOrientation::SetRotationB)
        .addProperty("Interpolation", &GC_OP_SetControlPointOrientation::GetInterpolation, &GC_OP_SetControlPointOrientation::SetInterpolation)
        .endClass();
}