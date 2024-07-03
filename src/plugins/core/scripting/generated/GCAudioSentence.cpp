#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAudioSentence::GCAudioSentence(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAudioSentence::GCAudioSentence(void *ptr) {
    m_ptr = ptr;
}
bool GCAudioSentence::GetShouldVoiceDuck() const {
    return GetSchemaValue<bool>(m_ptr, "CAudioSentence", "m_bShouldVoiceDuck");
}
void GCAudioSentence::SetShouldVoiceDuck(bool value) {
    SetSchemaValue(m_ptr, "CAudioSentence", "m_bShouldVoiceDuck", false, value);
}
std::vector<GCAudioPhonemeTag> GCAudioSentence::GetRunTimePhonemes() const {
    CUtlVector<GCAudioPhonemeTag>* vec = GetSchemaValue<CUtlVector<GCAudioPhonemeTag>*>(m_ptr, "CAudioSentence", "m_RunTimePhonemes"); std::vector<GCAudioPhonemeTag> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAudioSentence::SetRunTimePhonemes(std::vector<GCAudioPhonemeTag> value) {
    SetSchemaValueCUtlVector<GCAudioPhonemeTag>(m_ptr, "CAudioSentence", "m_RunTimePhonemes", false, value);
}
std::vector<GCAudioEmphasisSample> GCAudioSentence::GetEmphasisSamples() const {
    CUtlVector<GCAudioEmphasisSample>* vec = GetSchemaValue<CUtlVector<GCAudioEmphasisSample>*>(m_ptr, "CAudioSentence", "m_EmphasisSamples"); std::vector<GCAudioEmphasisSample> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAudioSentence::SetEmphasisSamples(std::vector<GCAudioEmphasisSample> value) {
    SetSchemaValueCUtlVector<GCAudioEmphasisSample>(m_ptr, "CAudioSentence", "m_EmphasisSamples", false, value);
}
GCAudioMorphData GCAudioSentence::GetMorphData() const {
    GCAudioMorphData value(GetSchemaPtr(m_ptr, "CAudioSentence", "m_morphData"));
    return value;
}
void GCAudioSentence::SetMorphData(GCAudioMorphData value) {
    SetSchemaValue(m_ptr, "CAudioSentence", "m_morphData", false, value);
}
std::string GCAudioSentence::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAudioSentence::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAudioSentence(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAudioSentence>("CAudioSentence")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ShouldVoiceDuck", &GCAudioSentence::GetShouldVoiceDuck, &GCAudioSentence::SetShouldVoiceDuck)
        .addProperty("RunTimePhonemes", &GCAudioSentence::GetRunTimePhonemes, &GCAudioSentence::SetRunTimePhonemes)
        .addProperty("EmphasisSamples", &GCAudioSentence::GetEmphasisSamples, &GCAudioSentence::SetEmphasisSamples)
        .addProperty("MorphData", &GCAudioSentence::GetMorphData, &GCAudioSentence::SetMorphData)
        .addFunction("ToPtr", &GCAudioSentence::ToPtr)
        .addFunction("IsValid", &GCAudioSentence::IsValid)
        .endClass();
}