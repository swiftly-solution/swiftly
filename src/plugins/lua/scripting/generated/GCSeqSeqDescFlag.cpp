#include "../../../core/scripting/generated/classes/GCSeqSeqDescFlag.h"
#include "../core.h"

void SetupLuaClassGCSeqSeqDescFlag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqSeqDescFlag>("CSeqSeqDescFlag")
        .addProperty("Looping", &GCSeqSeqDescFlag::GetLooping, &GCSeqSeqDescFlag::SetLooping)
        .addProperty("Snap", &GCSeqSeqDescFlag::GetSnap, &GCSeqSeqDescFlag::SetSnap)
        .addProperty("Autoplay", &GCSeqSeqDescFlag::GetAutoplay, &GCSeqSeqDescFlag::SetAutoplay)
        .addProperty("Post", &GCSeqSeqDescFlag::GetPost, &GCSeqSeqDescFlag::SetPost)
        .addProperty("Hidden", &GCSeqSeqDescFlag::GetHidden, &GCSeqSeqDescFlag::SetHidden)
        .addProperty("Multi", &GCSeqSeqDescFlag::GetMulti, &GCSeqSeqDescFlag::SetMulti)
        .addProperty("LegacyDelta", &GCSeqSeqDescFlag::GetLegacyDelta, &GCSeqSeqDescFlag::SetLegacyDelta)
        .addProperty("LegacyWorldspace", &GCSeqSeqDescFlag::GetLegacyWorldspace, &GCSeqSeqDescFlag::SetLegacyWorldspace)
        .addProperty("LegacyCyclepose", &GCSeqSeqDescFlag::GetLegacyCyclepose, &GCSeqSeqDescFlag::SetLegacyCyclepose)
        .addProperty("LegacyRealtime", &GCSeqSeqDescFlag::GetLegacyRealtime, &GCSeqSeqDescFlag::SetLegacyRealtime)
        .addProperty("ModelDoc", &GCSeqSeqDescFlag::GetModelDoc, &GCSeqSeqDescFlag::SetModelDoc)
        .endClass();
}