#include "../../../core/scripting/generated/classes/GSkeletonAnimCapture_t__FrameStamp_t.h"
#include "../core.h"

void SetupLuaClassGSkeletonAnimCapture_t__FrameStamp_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonAnimCapture_t__FrameStamp_t>("SkeletonAnimCapture_t__FrameStamp_t")
        .addProperty("Time", &GSkeletonAnimCapture_t__FrameStamp_t::GetTime, &GSkeletonAnimCapture_t__FrameStamp_t::SetTime)
        .addProperty("EntitySimTime", &GSkeletonAnimCapture_t__FrameStamp_t::GetEntitySimTime, &GSkeletonAnimCapture_t__FrameStamp_t::SetEntitySimTime)
        .addProperty("TeleportTick", &GSkeletonAnimCapture_t__FrameStamp_t::GetTeleportTick, &GSkeletonAnimCapture_t__FrameStamp_t::SetTeleportTick)
        .addProperty("Predicted", &GSkeletonAnimCapture_t__FrameStamp_t::GetPredicted, &GSkeletonAnimCapture_t__FrameStamp_t::SetPredicted)
        .addProperty("CurTime", &GSkeletonAnimCapture_t__FrameStamp_t::GetCurTime, &GSkeletonAnimCapture_t__FrameStamp_t::SetCurTime)
        .addProperty("RealTime", &GSkeletonAnimCapture_t__FrameStamp_t::GetRealTime, &GSkeletonAnimCapture_t__FrameStamp_t::SetRealTime)
        .addProperty("FrameCount", &GSkeletonAnimCapture_t__FrameStamp_t::GetFrameCount, &GSkeletonAnimCapture_t__FrameStamp_t::SetFrameCount)
        .addProperty("TickCount", &GSkeletonAnimCapture_t__FrameStamp_t::GetTickCount, &GSkeletonAnimCapture_t__FrameStamp_t::SetTickCount)
        .endClass();
}