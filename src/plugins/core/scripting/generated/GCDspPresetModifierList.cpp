#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDspPresetModifierList::GCDspPresetModifierList(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDspPresetModifierList::GCDspPresetModifierList(void *ptr) {
    m_ptr = ptr;
}
std::string GCDspPresetModifierList::GetDspName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CDspPresetModifierList", "m_dspName").Get();
}
void GCDspPresetModifierList::SetDspName(std::string value) {
    SetSchemaValue(m_ptr, "CDspPresetModifierList", "m_dspName", false, CUtlString(value.c_str()));
}
std::vector<GCDSPMixgroupModifier> GCDspPresetModifierList::GetModifiers() const {
    CUtlVector<GCDSPMixgroupModifier>* vec = GetSchemaValue<CUtlVector<GCDSPMixgroupModifier>*>(m_ptr, "CDspPresetModifierList", "m_modifiers"); std::vector<GCDSPMixgroupModifier> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCDspPresetModifierList::SetModifiers(std::vector<GCDSPMixgroupModifier> value) {
    SetSchemaValueCUtlVector<GCDSPMixgroupModifier>(m_ptr, "CDspPresetModifierList", "m_modifiers", false, value);
}
std::string GCDspPresetModifierList::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDspPresetModifierList::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCDspPresetModifierList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDspPresetModifierList>("CDspPresetModifierList")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DspName", &GCDspPresetModifierList::GetDspName, &GCDspPresetModifierList::SetDspName)
        .addProperty("Modifiers", &GCDspPresetModifierList::GetModifiers, &GCDspPresetModifierList::SetModifiers)
        .addFunction("ToPtr", &GCDspPresetModifierList::ToPtr)
        .addFunction("IsValid", &GCDspPresetModifierList::IsValid)
        .endClass();
}