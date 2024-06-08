#include "../../../core/scripting/generated/classes/GCColorCorrection.h"
#include "../core.h"

void SetupLuaClassGCColorCorrection(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCColorCorrection>("CColorCorrection")
        .addProperty("FadeInDuration", &GCColorCorrection::GetFadeInDuration, &GCColorCorrection::SetFadeInDuration)
        .addProperty("FadeOutDuration", &GCColorCorrection::GetFadeOutDuration, &GCColorCorrection::SetFadeOutDuration)
        .addProperty("StartFadeInWeight", &GCColorCorrection::GetStartFadeInWeight, &GCColorCorrection::SetStartFadeInWeight)
        .addProperty("StartFadeOutWeight", &GCColorCorrection::GetStartFadeOutWeight, &GCColorCorrection::SetStartFadeOutWeight)
        .addProperty("MaxWeight", &GCColorCorrection::GetMaxWeight, &GCColorCorrection::SetMaxWeight)
        .addProperty("StartDisabled", &GCColorCorrection::GetStartDisabled, &GCColorCorrection::SetStartDisabled)
        .addProperty("Enabled", &GCColorCorrection::GetEnabled, &GCColorCorrection::SetEnabled)
        .addProperty("Master", &GCColorCorrection::GetMaster, &GCColorCorrection::SetMaster)
        .addProperty("ClientSide", &GCColorCorrection::GetClientSide, &GCColorCorrection::SetClientSide)
        .addProperty("Exclusive", &GCColorCorrection::GetExclusive, &GCColorCorrection::SetExclusive)
        .addProperty("MinFalloff", &GCColorCorrection::GetMinFalloff, &GCColorCorrection::SetMinFalloff)
        .addProperty("MaxFalloff", &GCColorCorrection::GetMaxFalloff, &GCColorCorrection::SetMaxFalloff)
        .addProperty("CurWeight", &GCColorCorrection::GetCurWeight, &GCColorCorrection::SetCurWeight)
        .addProperty("NetlookupFilename", &GCColorCorrection::GetNetlookupFilename, &GCColorCorrection::SetNetlookupFilename)
        .addProperty("LookupFilename", &GCColorCorrection::GetLookupFilename, &GCColorCorrection::SetLookupFilename)
        .endClass();
}