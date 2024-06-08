#include "../../../core/scripting/generated/classes/GCSeqPoseSetting.h"
#include "../core.h"

void SetupLuaClassGCSeqPoseSetting(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqPoseSetting>("CSeqPoseSetting")
        .addProperty("PoseParameter", &GCSeqPoseSetting::GetPoseParameter, &GCSeqPoseSetting::SetPoseParameter)
        .addProperty("Attachment", &GCSeqPoseSetting::GetAttachment, &GCSeqPoseSetting::SetAttachment)
        .addProperty("ReferenceSequence", &GCSeqPoseSetting::GetReferenceSequence, &GCSeqPoseSetting::SetReferenceSequence)
        .addProperty("Value", &GCSeqPoseSetting::GetValue, &GCSeqPoseSetting::SetValue)
        .addProperty("X", &GCSeqPoseSetting::GetX, &GCSeqPoseSetting::SetX)
        .addProperty("Y", &GCSeqPoseSetting::GetY, &GCSeqPoseSetting::SetY)
        .addProperty("Z", &GCSeqPoseSetting::GetZ, &GCSeqPoseSetting::SetZ)
        .addProperty("Type", &GCSeqPoseSetting::GetType, &GCSeqPoseSetting::SetType)
        .endClass();
}