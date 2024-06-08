#include "../../../core/scripting/generated/classes/GCSeqAutoLayer.h"
#include "../core.h"

void SetupLuaClassGCSeqAutoLayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqAutoLayer>("CSeqAutoLayer")
        .addProperty("LocalReference", &GCSeqAutoLayer::GetLocalReference, &GCSeqAutoLayer::SetLocalReference)
        .addProperty("LocalPose", &GCSeqAutoLayer::GetLocalPose, &GCSeqAutoLayer::SetLocalPose)
        .addProperty("Flags", &GCSeqAutoLayer::GetFlags, &GCSeqAutoLayer::SetFlags)
        .addProperty("Start", &GCSeqAutoLayer::GetStart, &GCSeqAutoLayer::SetStart)
        .addProperty("Peak", &GCSeqAutoLayer::GetPeak, &GCSeqAutoLayer::SetPeak)
        .addProperty("Tail", &GCSeqAutoLayer::GetTail, &GCSeqAutoLayer::SetTail)
        .addProperty("End", &GCSeqAutoLayer::GetEnd, &GCSeqAutoLayer::SetEnd)
        .endClass();
}