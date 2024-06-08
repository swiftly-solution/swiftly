#include "../../../core/scripting/generated/classes/GSkeletonAnimCapture_t__Frame_t.h"
#include "../core.h"

void SetupLuaClassGSkeletonAnimCapture_t__Frame_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonAnimCapture_t__Frame_t>("SkeletonAnimCapture_t__Frame_t")
        .addProperty("Time", &GSkeletonAnimCapture_t__Frame_t::GetTime, &GSkeletonAnimCapture_t__Frame_t::SetTime)
        .addProperty("Stamp", &GSkeletonAnimCapture_t__Frame_t::GetStamp, &GSkeletonAnimCapture_t__Frame_t::SetStamp)
        .addProperty("Teleport", &GSkeletonAnimCapture_t__Frame_t::GetTeleport, &GSkeletonAnimCapture_t__Frame_t::SetTeleport)
        .addProperty("FeModelPos", &GSkeletonAnimCapture_t__Frame_t::GetFeModelPos, &GSkeletonAnimCapture_t__Frame_t::SetFeModelPos)
        .addProperty("FlexControllerWeights", &GSkeletonAnimCapture_t__Frame_t::GetFlexControllerWeights, &GSkeletonAnimCapture_t__Frame_t::SetFlexControllerWeights)
        .endClass();
}