#include "../../../core/scripting/generated/classes/GCAudioSentence.h"
#include "../core.h"

void SetupLuaClassGCAudioSentence(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAudioSentence>("CAudioSentence")
        .addProperty("ShouldVoiceDuck", &GCAudioSentence::GetShouldVoiceDuck, &GCAudioSentence::SetShouldVoiceDuck)
        .addProperty("RunTimePhonemes", &GCAudioSentence::GetRunTimePhonemes, &GCAudioSentence::SetRunTimePhonemes)
        .addProperty("EmphasisSamples", &GCAudioSentence::GetEmphasisSamples, &GCAudioSentence::SetEmphasisSamples)
        .addProperty("MorphData", &GCAudioSentence::GetMorphData, &GCAudioSentence::SetMorphData)
        .endClass();
}