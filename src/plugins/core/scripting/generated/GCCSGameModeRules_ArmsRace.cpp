#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGameModeRules_ArmsRace::GCCSGameModeRules_ArmsRace(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGameModeRules_ArmsRace::GCCSGameModeRules_ArmsRace(void *ptr) {
    m_ptr = ptr;
}
std::vector<CUtlString> GCCSGameModeRules_ArmsRace::GetWeaponSequence() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CCSGameModeRules_ArmsRace", "m_WeaponSequence"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCSGameModeRules_ArmsRace::SetWeaponSequence(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CCSGameModeRules_ArmsRace", "m_WeaponSequence", false, value);
}
std::string GCCSGameModeRules_ArmsRace::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGameModeRules_ArmsRace::IsValid() {
    return (m_ptr != nullptr);
}
GCCSGameModeRules GCCSGameModeRules_ArmsRace::GetParent() const {
    GCCSGameModeRules value(m_ptr);
    return value;
}
void GCCSGameModeRules_ArmsRace::SetParent(GCCSGameModeRules value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGameModeRules_ArmsRace(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGameModeRules_ArmsRace>("CCSGameModeRules_ArmsRace")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WeaponSequence", &GCCSGameModeRules_ArmsRace::GetWeaponSequence, &GCCSGameModeRules_ArmsRace::SetWeaponSequence)
        .addProperty("Parent", &GCCSGameModeRules_ArmsRace::GetParent, &GCCSGameModeRules_ArmsRace::SetParent)
        .addFunction("ToPtr", &GCCSGameModeRules_ArmsRace::ToPtr)
        .addFunction("IsValid", &GCCSGameModeRules_ArmsRace::IsValid)
        .endClass();
}