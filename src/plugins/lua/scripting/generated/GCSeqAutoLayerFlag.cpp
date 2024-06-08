#include "../../../core/scripting/generated/classes/GCSeqAutoLayerFlag.h"
#include "../core.h"

void SetupLuaClassGCSeqAutoLayerFlag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqAutoLayerFlag>("CSeqAutoLayerFlag")
        .addProperty("Post", &GCSeqAutoLayerFlag::GetPost, &GCSeqAutoLayerFlag::SetPost)
        .addProperty("Spline", &GCSeqAutoLayerFlag::GetSpline, &GCSeqAutoLayerFlag::SetSpline)
        .addProperty("XFade", &GCSeqAutoLayerFlag::GetXFade, &GCSeqAutoLayerFlag::SetXFade)
        .addProperty("NoBlend", &GCSeqAutoLayerFlag::GetNoBlend, &GCSeqAutoLayerFlag::SetNoBlend)
        .addProperty("Local", &GCSeqAutoLayerFlag::GetLocal, &GCSeqAutoLayerFlag::SetLocal)
        .addProperty("Pose", &GCSeqAutoLayerFlag::GetPose, &GCSeqAutoLayerFlag::SetPose)
        .addProperty("FetchFrame", &GCSeqAutoLayerFlag::GetFetchFrame, &GCSeqAutoLayerFlag::SetFetchFrame)
        .addProperty("Subtract", &GCSeqAutoLayerFlag::GetSubtract, &GCSeqAutoLayerFlag::SetSubtract)
        .endClass();
}