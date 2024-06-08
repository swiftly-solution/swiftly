#include "../../../core/scripting/generated/classes/GCSeqPoseParamDesc.h"
#include "../core.h"

void SetupLuaClassGCSeqPoseParamDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqPoseParamDesc>("CSeqPoseParamDesc")
        .addProperty("Name", &GCSeqPoseParamDesc::GetName, &GCSeqPoseParamDesc::SetName)
        .addProperty("Start", &GCSeqPoseParamDesc::GetStart, &GCSeqPoseParamDesc::SetStart)
        .addProperty("End", &GCSeqPoseParamDesc::GetEnd, &GCSeqPoseParamDesc::SetEnd)
        .addProperty("Loop", &GCSeqPoseParamDesc::GetLoop, &GCSeqPoseParamDesc::SetLoop)
        .addProperty("Looping", &GCSeqPoseParamDesc::GetLooping, &GCSeqPoseParamDesc::SetLooping)
        .endClass();
}