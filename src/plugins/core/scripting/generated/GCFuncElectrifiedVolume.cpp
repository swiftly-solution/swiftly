#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncElectrifiedVolume::GCFuncElectrifiedVolume(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncElectrifiedVolume::GCFuncElectrifiedVolume(void *ptr) {
    m_ptr = ptr;
}
std::string GCFuncElectrifiedVolume::GetEffectName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncElectrifiedVolume", "m_EffectName").String();
}
void GCFuncElectrifiedVolume::SetEffectName(std::string value) {
    SetSchemaValue(m_ptr, "CFuncElectrifiedVolume", "m_EffectName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncElectrifiedVolume::GetEffectInterpenetrateName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncElectrifiedVolume", "m_EffectInterpenetrateName").String();
}
void GCFuncElectrifiedVolume::SetEffectInterpenetrateName(std::string value) {
    SetSchemaValue(m_ptr, "CFuncElectrifiedVolume", "m_EffectInterpenetrateName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncElectrifiedVolume::GetEffectZapName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncElectrifiedVolume", "m_EffectZapName").String();
}
void GCFuncElectrifiedVolume::SetEffectZapName(std::string value) {
    SetSchemaValue(m_ptr, "CFuncElectrifiedVolume", "m_EffectZapName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncElectrifiedVolume::GetEffectSource() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncElectrifiedVolume", "m_iszEffectSource").String();
}
void GCFuncElectrifiedVolume::SetEffectSource(std::string value) {
    SetSchemaValue(m_ptr, "CFuncElectrifiedVolume", "m_iszEffectSource", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncElectrifiedVolume::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncElectrifiedVolume::IsValid() {
    return (m_ptr != nullptr);
}
GCFuncBrush GCFuncElectrifiedVolume::GetParent() const {
    GCFuncBrush value(m_ptr);
    return value;
}
void GCFuncElectrifiedVolume::SetParent(GCFuncBrush value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncElectrifiedVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncElectrifiedVolume>("CFuncElectrifiedVolume")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EffectName", &GCFuncElectrifiedVolume::GetEffectName, &GCFuncElectrifiedVolume::SetEffectName)
        .addProperty("EffectInterpenetrateName", &GCFuncElectrifiedVolume::GetEffectInterpenetrateName, &GCFuncElectrifiedVolume::SetEffectInterpenetrateName)
        .addProperty("EffectZapName", &GCFuncElectrifiedVolume::GetEffectZapName, &GCFuncElectrifiedVolume::SetEffectZapName)
        .addProperty("EffectSource", &GCFuncElectrifiedVolume::GetEffectSource, &GCFuncElectrifiedVolume::SetEffectSource)
        .addProperty("Parent", &GCFuncElectrifiedVolume::GetParent, &GCFuncElectrifiedVolume::SetParent)
        .addFunction("ToPtr", &GCFuncElectrifiedVolume::ToPtr)
        .addFunction("IsValid", &GCFuncElectrifiedVolume::IsValid)
        .endClass();
}