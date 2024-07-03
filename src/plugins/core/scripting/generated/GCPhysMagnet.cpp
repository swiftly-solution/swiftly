#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysMagnet::GCPhysMagnet(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysMagnet::GCPhysMagnet(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCPhysMagnet::GetOnMagnetAttach() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysMagnet", "m_OnMagnetAttach"));
    return value;
}
void GCPhysMagnet::SetOnMagnetAttach(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysMagnet", "m_OnMagnetAttach", false, value);
}
GCEntityIOOutput GCPhysMagnet::GetOnMagnetDetach() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysMagnet", "m_OnMagnetDetach"));
    return value;
}
void GCPhysMagnet::SetOnMagnetDetach(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysMagnet", "m_OnMagnetDetach", false, value);
}
float GCPhysMagnet::GetMassScale() const {
    return GetSchemaValue<float>(m_ptr, "CPhysMagnet", "m_massScale");
}
void GCPhysMagnet::SetMassScale(float value) {
    SetSchemaValue(m_ptr, "CPhysMagnet", "m_massScale", false, value);
}
float GCPhysMagnet::GetForceLimit() const {
    return GetSchemaValue<float>(m_ptr, "CPhysMagnet", "m_forceLimit");
}
void GCPhysMagnet::SetForceLimit(float value) {
    SetSchemaValue(m_ptr, "CPhysMagnet", "m_forceLimit", false, value);
}
float GCPhysMagnet::GetTorqueLimit() const {
    return GetSchemaValue<float>(m_ptr, "CPhysMagnet", "m_torqueLimit");
}
void GCPhysMagnet::SetTorqueLimit(float value) {
    SetSchemaValue(m_ptr, "CPhysMagnet", "m_torqueLimit", false, value);
}
std::vector<Gmagnetted_objects_t> GCPhysMagnet::GetMagnettedEntities() const {
    CUtlVector<Gmagnetted_objects_t>* vec = GetSchemaValue<CUtlVector<Gmagnetted_objects_t>*>(m_ptr, "CPhysMagnet", "m_MagnettedEntities"); std::vector<Gmagnetted_objects_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPhysMagnet::SetMagnettedEntities(std::vector<Gmagnetted_objects_t> value) {
    SetSchemaValueCUtlVector<Gmagnetted_objects_t>(m_ptr, "CPhysMagnet", "m_MagnettedEntities", false, value);
}
bool GCPhysMagnet::GetActive() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysMagnet", "m_bActive");
}
void GCPhysMagnet::SetActive(bool value) {
    SetSchemaValue(m_ptr, "CPhysMagnet", "m_bActive", false, value);
}
bool GCPhysMagnet::GetHasHitSomething() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysMagnet", "m_bHasHitSomething");
}
void GCPhysMagnet::SetHasHitSomething(bool value) {
    SetSchemaValue(m_ptr, "CPhysMagnet", "m_bHasHitSomething", false, value);
}
float GCPhysMagnet::GetTotalMass() const {
    return GetSchemaValue<float>(m_ptr, "CPhysMagnet", "m_flTotalMass");
}
void GCPhysMagnet::SetTotalMass(float value) {
    SetSchemaValue(m_ptr, "CPhysMagnet", "m_flTotalMass", false, value);
}
float GCPhysMagnet::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CPhysMagnet", "m_flRadius");
}
void GCPhysMagnet::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CPhysMagnet", "m_flRadius", false, value);
}
float GCPhysMagnet::GetNextSuckTime() const {
    return GetSchemaValue<float>(m_ptr, "CPhysMagnet", "m_flNextSuckTime");
}
void GCPhysMagnet::SetNextSuckTime(float value) {
    SetSchemaValue(m_ptr, "CPhysMagnet", "m_flNextSuckTime", false, value);
}
int32_t GCPhysMagnet::GetMaxObjectsAttached() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPhysMagnet", "m_iMaxObjectsAttached");
}
void GCPhysMagnet::SetMaxObjectsAttached(int32_t value) {
    SetSchemaValue(m_ptr, "CPhysMagnet", "m_iMaxObjectsAttached", false, value);
}
std::string GCPhysMagnet::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysMagnet::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseAnimGraph GCPhysMagnet::GetParent() const {
    GCBaseAnimGraph value(m_ptr);
    return value;
}
void GCPhysMagnet::SetParent(GCBaseAnimGraph value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysMagnet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysMagnet>("CPhysMagnet")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnMagnetAttach", &GCPhysMagnet::GetOnMagnetAttach, &GCPhysMagnet::SetOnMagnetAttach)
        .addProperty("OnMagnetDetach", &GCPhysMagnet::GetOnMagnetDetach, &GCPhysMagnet::SetOnMagnetDetach)
        .addProperty("MassScale", &GCPhysMagnet::GetMassScale, &GCPhysMagnet::SetMassScale)
        .addProperty("ForceLimit", &GCPhysMagnet::GetForceLimit, &GCPhysMagnet::SetForceLimit)
        .addProperty("TorqueLimit", &GCPhysMagnet::GetTorqueLimit, &GCPhysMagnet::SetTorqueLimit)
        .addProperty("MagnettedEntities", &GCPhysMagnet::GetMagnettedEntities, &GCPhysMagnet::SetMagnettedEntities)
        .addProperty("Active", &GCPhysMagnet::GetActive, &GCPhysMagnet::SetActive)
        .addProperty("HasHitSomething", &GCPhysMagnet::GetHasHitSomething, &GCPhysMagnet::SetHasHitSomething)
        .addProperty("TotalMass", &GCPhysMagnet::GetTotalMass, &GCPhysMagnet::SetTotalMass)
        .addProperty("Radius", &GCPhysMagnet::GetRadius, &GCPhysMagnet::SetRadius)
        .addProperty("NextSuckTime", &GCPhysMagnet::GetNextSuckTime, &GCPhysMagnet::SetNextSuckTime)
        .addProperty("MaxObjectsAttached", &GCPhysMagnet::GetMaxObjectsAttached, &GCPhysMagnet::SetMaxObjectsAttached)
        .addProperty("Parent", &GCPhysMagnet::GetParent, &GCPhysMagnet::SetParent)
        .addFunction("ToPtr", &GCPhysMagnet::ToPtr)
        .addFunction("IsValid", &GCPhysMagnet::IsValid)
        .endClass();
}