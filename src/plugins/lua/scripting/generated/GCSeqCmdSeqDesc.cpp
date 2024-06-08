#include "../../../core/scripting/generated/classes/GCSeqCmdSeqDesc.h"
#include "../core.h"

void SetupLuaClassGCSeqCmdSeqDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqCmdSeqDesc>("CSeqCmdSeqDesc")
        .addProperty("Name", &GCSeqCmdSeqDesc::GetName, &GCSeqCmdSeqDesc::SetName)
        .addProperty("Flags", &GCSeqCmdSeqDesc::GetFlags, &GCSeqCmdSeqDesc::SetFlags)
        .addProperty("Transition", &GCSeqCmdSeqDesc::GetTransition, &GCSeqCmdSeqDesc::SetTransition)
        .addProperty("FrameRangeSequence", &GCSeqCmdSeqDesc::GetFrameRangeSequence, &GCSeqCmdSeqDesc::SetFrameRangeSequence)
        .addProperty("FrameCount", &GCSeqCmdSeqDesc::GetFrameCount, &GCSeqCmdSeqDesc::SetFrameCount)
        .addProperty("FPS", &GCSeqCmdSeqDesc::GetFPS, &GCSeqCmdSeqDesc::SetFPS)
        .addProperty("SubCycles", &GCSeqCmdSeqDesc::GetSubCycles, &GCSeqCmdSeqDesc::SetSubCycles)
        .addProperty("NumLocalResults", &GCSeqCmdSeqDesc::GetNumLocalResults, &GCSeqCmdSeqDesc::SetNumLocalResults)
        .addProperty("CmdLayerArray", &GCSeqCmdSeqDesc::GetCmdLayerArray, &GCSeqCmdSeqDesc::SetCmdLayerArray)
        .addProperty("EventArray", &GCSeqCmdSeqDesc::GetEventArray, &GCSeqCmdSeqDesc::SetEventArray)
        .addProperty("ActivityArray", &GCSeqCmdSeqDesc::GetActivityArray, &GCSeqCmdSeqDesc::SetActivityArray)
        .addProperty("PoseSettingArray", &GCSeqCmdSeqDesc::GetPoseSettingArray, &GCSeqCmdSeqDesc::SetPoseSettingArray)
        .endClass();
}