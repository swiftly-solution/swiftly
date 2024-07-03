#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysImpact::GCPhysImpact(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysImpact::GCPhysImpact(void *ptr) {
    m_ptr = ptr;
}
float GCPhysImpact::GetDamage() const {
    return GetSchemaValue<float>(m_ptr, "CPhysImpact", "m_damage");
}
void GCPhysImpact::SetDamage(float value) {
    SetSchemaValue(m_ptr, "CPhysImpact", "m_damage", false, value);
}
float GCPhysImpact::GetDistance() const {
    return GetSchemaValue<float>(m_ptr, "CPhysImpact", "m_distance");
}
void GCPhysImpact::SetDistance(float value) {
    SetSchemaValue(m_ptr, "CPhysImpact", "m_distance", false, value);
}
std::string GCPhysImpact::GetDirectionEntityName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysImpact", "m_directionEntityName").String();
}
void GCPhysImpact::SetDirectionEntityName(std::string value) {
    SetSchemaValue(m_ptr, "CPhysImpact", "m_directionEntityName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPhysImpact::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysImpact::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPhysImpact::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPhysImpact::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysImpact(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysImpact>("CPhysImpact")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Damage", &GCPhysImpact::GetDamage, &GCPhysImpact::SetDamage)
        .addProperty("Distance", &GCPhysImpact::GetDistance, &GCPhysImpact::SetDistance)
        .addProperty("DirectionEntityName", &GCPhysImpact::GetDirectionEntityName, &GCPhysImpact::SetDirectionEntityName)
        .addProperty("Parent", &GCPhysImpact::GetParent, &GCPhysImpact::SetParent)
        .addFunction("ToPtr", &GCPhysImpact::ToPtr)
        .addFunction("IsValid", &GCPhysImpact::IsValid)
        .endClass();
}