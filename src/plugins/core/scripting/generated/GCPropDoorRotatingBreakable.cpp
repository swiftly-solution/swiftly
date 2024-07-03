#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPropDoorRotatingBreakable::GCPropDoorRotatingBreakable(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPropDoorRotatingBreakable::GCPropDoorRotatingBreakable(void *ptr) {
    m_ptr = ptr;
}
bool GCPropDoorRotatingBreakable::GetBreakable() const {
    return GetSchemaValue<bool>(m_ptr, "CPropDoorRotatingBreakable", "m_bBreakable");
}
void GCPropDoorRotatingBreakable::SetBreakable(bool value) {
    SetSchemaValue(m_ptr, "CPropDoorRotatingBreakable", "m_bBreakable", false, value);
}
bool GCPropDoorRotatingBreakable::GetIsAbleToCloseAreaPortals() const {
    return GetSchemaValue<bool>(m_ptr, "CPropDoorRotatingBreakable", "m_isAbleToCloseAreaPortals");
}
void GCPropDoorRotatingBreakable::SetIsAbleToCloseAreaPortals(bool value) {
    SetSchemaValue(m_ptr, "CPropDoorRotatingBreakable", "m_isAbleToCloseAreaPortals", false, value);
}
int32_t GCPropDoorRotatingBreakable::GetCurrentDamageState() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPropDoorRotatingBreakable", "m_currentDamageState");
}
void GCPropDoorRotatingBreakable::SetCurrentDamageState(int32_t value) {
    SetSchemaValue(m_ptr, "CPropDoorRotatingBreakable", "m_currentDamageState", false, value);
}
std::vector<CUtlSymbolLarge> GCPropDoorRotatingBreakable::GetDamageStates() const {
    CUtlVector<CUtlSymbolLarge>* vec = GetSchemaValue<CUtlVector<CUtlSymbolLarge>*>(m_ptr, "CPropDoorRotatingBreakable", "m_damageStates"); std::vector<CUtlSymbolLarge> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPropDoorRotatingBreakable::SetDamageStates(std::vector<CUtlSymbolLarge> value) {
    SetSchemaValueCUtlVector<CUtlSymbolLarge>(m_ptr, "CPropDoorRotatingBreakable", "m_damageStates", false, value);
}
std::string GCPropDoorRotatingBreakable::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPropDoorRotatingBreakable::IsValid() {
    return (m_ptr != nullptr);
}
GCPropDoorRotating GCPropDoorRotatingBreakable::GetParent() const {
    GCPropDoorRotating value(m_ptr);
    return value;
}
void GCPropDoorRotatingBreakable::SetParent(GCPropDoorRotating value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPropDoorRotatingBreakable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPropDoorRotatingBreakable>("CPropDoorRotatingBreakable")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Breakable", &GCPropDoorRotatingBreakable::GetBreakable, &GCPropDoorRotatingBreakable::SetBreakable)
        .addProperty("IsAbleToCloseAreaPortals", &GCPropDoorRotatingBreakable::GetIsAbleToCloseAreaPortals, &GCPropDoorRotatingBreakable::SetIsAbleToCloseAreaPortals)
        .addProperty("CurrentDamageState", &GCPropDoorRotatingBreakable::GetCurrentDamageState, &GCPropDoorRotatingBreakable::SetCurrentDamageState)
        .addProperty("DamageStates", &GCPropDoorRotatingBreakable::GetDamageStates, &GCPropDoorRotatingBreakable::SetDamageStates)
        .addProperty("Parent", &GCPropDoorRotatingBreakable::GetParent, &GCPropDoorRotatingBreakable::SetParent)
        .addFunction("ToPtr", &GCPropDoorRotatingBreakable::ToPtr)
        .addFunction("IsValid", &GCPropDoorRotatingBreakable::IsValid)
        .endClass();
}