#include "../../../core/scripting/generated/classes/GCSequenceGroupData.h"
#include "../core.h"

void SetupLuaClassGCSequenceGroupData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSequenceGroupData>("CSequenceGroupData")
        .addProperty("Name", &GCSequenceGroupData::GetName, &GCSequenceGroupData::SetName)
        .addProperty("Flags", &GCSequenceGroupData::GetFlags, &GCSequenceGroupData::SetFlags)
        .addProperty("LocalSequenceNameArray", &GCSequenceGroupData::GetLocalSequenceNameArray, &GCSequenceGroupData::SetLocalSequenceNameArray)
        .addProperty("LocalS1SeqDescArray", &GCSequenceGroupData::GetLocalS1SeqDescArray, &GCSequenceGroupData::SetLocalS1SeqDescArray)
        .addProperty("LocalMultiSeqDescArray", &GCSequenceGroupData::GetLocalMultiSeqDescArray, &GCSequenceGroupData::SetLocalMultiSeqDescArray)
        .addProperty("LocalSynthAnimDescArray", &GCSequenceGroupData::GetLocalSynthAnimDescArray, &GCSequenceGroupData::SetLocalSynthAnimDescArray)
        .addProperty("LocalCmdSeqDescArray", &GCSequenceGroupData::GetLocalCmdSeqDescArray, &GCSequenceGroupData::SetLocalCmdSeqDescArray)
        .addProperty("LocalBoneMaskArray", &GCSequenceGroupData::GetLocalBoneMaskArray, &GCSequenceGroupData::SetLocalBoneMaskArray)
        .addProperty("LocalScaleSetArray", &GCSequenceGroupData::GetLocalScaleSetArray, &GCSequenceGroupData::SetLocalScaleSetArray)
        .addProperty("LocalBoneNameArray", &GCSequenceGroupData::GetLocalBoneNameArray, &GCSequenceGroupData::SetLocalBoneNameArray)
        .addProperty("LocalNodeName", &GCSequenceGroupData::GetLocalNodeName, &GCSequenceGroupData::SetLocalNodeName)
        .addProperty("LocalPoseParamArray", &GCSequenceGroupData::GetLocalPoseParamArray, &GCSequenceGroupData::SetLocalPoseParamArray)
        .addProperty("LocalIKAutoplayLockArray", &GCSequenceGroupData::GetLocalIKAutoplayLockArray, &GCSequenceGroupData::SetLocalIKAutoplayLockArray)
        .endClass();
}