#include "../../../core/scripting/generated/classes/GSkeletonDemoDb_t.h"
#include "../core.h"

void SetupLuaClassGSkeletonDemoDb_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonDemoDb_t>("SkeletonDemoDb_t")
        .addProperty("AnimCaptures", &GSkeletonDemoDb_t::GetAnimCaptures, &GSkeletonDemoDb_t::SetAnimCaptures)
        .addProperty("CameraTrack", &GSkeletonDemoDb_t::GetCameraTrack, &GSkeletonDemoDb_t::SetCameraTrack)
        .addProperty("RecordingTime", &GSkeletonDemoDb_t::GetRecordingTime, &GSkeletonDemoDb_t::SetRecordingTime)
        .endClass();
}