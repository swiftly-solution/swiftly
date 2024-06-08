#include "../../../core/scripting/generated/classes/GCAnimDesc_Flag.h"
#include "../core.h"

void SetupLuaClassGCAnimDesc_Flag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimDesc_Flag>("CAnimDesc_Flag")
        .addProperty("Looping", &GCAnimDesc_Flag::GetLooping, &GCAnimDesc_Flag::SetLooping)
        .addProperty("AllZeros", &GCAnimDesc_Flag::GetAllZeros, &GCAnimDesc_Flag::SetAllZeros)
        .addProperty("Hidden", &GCAnimDesc_Flag::GetHidden, &GCAnimDesc_Flag::SetHidden)
        .addProperty("Delta", &GCAnimDesc_Flag::GetDelta, &GCAnimDesc_Flag::SetDelta)
        .addProperty("LegacyWorldspace", &GCAnimDesc_Flag::GetLegacyWorldspace, &GCAnimDesc_Flag::SetLegacyWorldspace)
        .addProperty("ModelDoc", &GCAnimDesc_Flag::GetModelDoc, &GCAnimDesc_Flag::SetModelDoc)
        .addProperty("ImplicitSeqIgnoreDelta", &GCAnimDesc_Flag::GetImplicitSeqIgnoreDelta, &GCAnimDesc_Flag::SetImplicitSeqIgnoreDelta)
        .addProperty("AnimGraphAdditive", &GCAnimDesc_Flag::GetAnimGraphAdditive, &GCAnimDesc_Flag::SetAnimGraphAdditive)
        .endClass();
}