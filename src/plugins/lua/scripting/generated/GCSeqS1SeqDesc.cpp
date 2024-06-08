#include "../../../core/scripting/generated/classes/GCSeqS1SeqDesc.h"
#include "../core.h"

void SetupLuaClassGCSeqS1SeqDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqS1SeqDesc>("CSeqS1SeqDesc")
        .addProperty("Name", &GCSeqS1SeqDesc::GetName, &GCSeqS1SeqDesc::SetName)
        .addProperty("Flags", &GCSeqS1SeqDesc::GetFlags, &GCSeqS1SeqDesc::SetFlags)
        .addProperty("Fetch", &GCSeqS1SeqDesc::GetFetch, &GCSeqS1SeqDesc::SetFetch)
        .addProperty("LocalWeightlist", &GCSeqS1SeqDesc::GetLocalWeightlist, &GCSeqS1SeqDesc::SetLocalWeightlist)
        .addProperty("AutoLayerArray", &GCSeqS1SeqDesc::GetAutoLayerArray, &GCSeqS1SeqDesc::SetAutoLayerArray)
        .addProperty("IKLockArray", &GCSeqS1SeqDesc::GetIKLockArray, &GCSeqS1SeqDesc::SetIKLockArray)
        .addProperty("Transition", &GCSeqS1SeqDesc::GetTransition, &GCSeqS1SeqDesc::SetTransition)
        .addProperty("LegacyKeyValueText", &GCSeqS1SeqDesc::GetLegacyKeyValueText, &GCSeqS1SeqDesc::SetLegacyKeyValueText)
        .addProperty("ActivityArray", &GCSeqS1SeqDesc::GetActivityArray, &GCSeqS1SeqDesc::SetActivityArray)
        .addProperty("FootMotion", &GCSeqS1SeqDesc::GetFootMotion, &GCSeqS1SeqDesc::SetFootMotion)
        .endClass();
}