#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseConstraint::GCBaseConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseConstraint::GCBaseConstraint(void *ptr) {
    m_ptr = ptr;
}
std::string GCBaseConstraint::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBaseConstraint", "m_name").Get();
}
void GCBaseConstraint::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CBaseConstraint", "m_name", false, CUtlString(value.c_str()));
}
Vector GCBaseConstraint::GetUpVector() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseConstraint", "m_vUpVector");
}
void GCBaseConstraint::SetUpVector(Vector value) {
    SetSchemaValue(m_ptr, "CBaseConstraint", "m_vUpVector", false, value);
}
std::vector<GCConstraintSlave> GCBaseConstraint::GetSlaves() const {
    CUtlVector<GCConstraintSlave>* vec = GetSchemaValue<CUtlVector<GCConstraintSlave>*>(m_ptr, "CBaseConstraint", "m_slaves"); std::vector<GCConstraintSlave> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBaseConstraint::SetSlaves(std::vector<GCConstraintSlave> value) {
    SetSchemaValueCUtlVector<GCConstraintSlave>(m_ptr, "CBaseConstraint", "m_slaves", false, value);
}
std::vector<GCConstraintTarget> GCBaseConstraint::GetTargets() const {
    CUtlVector<GCConstraintTarget>* vec = GetSchemaValue<CUtlVector<GCConstraintTarget>*>(m_ptr, "CBaseConstraint", "m_targets"); std::vector<GCConstraintTarget> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBaseConstraint::SetTargets(std::vector<GCConstraintTarget> value) {
    SetSchemaValueCUtlVector<GCConstraintTarget>(m_ptr, "CBaseConstraint", "m_targets", false, value);
}
std::string GCBaseConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCBoneConstraintBase GCBaseConstraint::GetParent() const {
    GCBoneConstraintBase value(m_ptr);
    return value;
}
void GCBaseConstraint::SetParent(GCBoneConstraintBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseConstraint>("CBaseConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCBaseConstraint::GetName, &GCBaseConstraint::SetName)
        .addProperty("UpVector", &GCBaseConstraint::GetUpVector, &GCBaseConstraint::SetUpVector)
        .addProperty("Slaves", &GCBaseConstraint::GetSlaves, &GCBaseConstraint::SetSlaves)
        .addProperty("Targets", &GCBaseConstraint::GetTargets, &GCBaseConstraint::SetTargets)
        .addProperty("Parent", &GCBaseConstraint::GetParent, &GCBaseConstraint::SetParent)
        .addFunction("ToPtr", &GCBaseConstraint::ToPtr)
        .addFunction("IsValid", &GCBaseConstraint::IsValid)
        .endClass();
}