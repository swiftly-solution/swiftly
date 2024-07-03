#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSkillDamage::GCSkillDamage(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSkillDamage::GCSkillDamage(void *ptr) {
    m_ptr = ptr;
}
GCSkillFloat GCSkillDamage::GetDamage() const {
    GCSkillFloat value(GetSchemaPtr(m_ptr, "CSkillDamage", "m_flDamage"));
    return value;
}
void GCSkillDamage::SetDamage(GCSkillFloat value) {
    SetSchemaValue(m_ptr, "CSkillDamage", "m_flDamage", false, value);
}
float GCSkillDamage::GetNPCDamageScalarVsNPC() const {
    return GetSchemaValue<float>(m_ptr, "CSkillDamage", "m_flNPCDamageScalarVsNPC");
}
void GCSkillDamage::SetNPCDamageScalarVsNPC(float value) {
    SetSchemaValue(m_ptr, "CSkillDamage", "m_flNPCDamageScalarVsNPC", false, value);
}
float GCSkillDamage::GetPhysicsForceDamage() const {
    return GetSchemaValue<float>(m_ptr, "CSkillDamage", "m_flPhysicsForceDamage");
}
void GCSkillDamage::SetPhysicsForceDamage(float value) {
    SetSchemaValue(m_ptr, "CSkillDamage", "m_flPhysicsForceDamage", false, value);
}
std::string GCSkillDamage::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSkillDamage::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSkillDamage(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkillDamage>("CSkillDamage")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Damage", &GCSkillDamage::GetDamage, &GCSkillDamage::SetDamage)
        .addProperty("NPCDamageScalarVsNPC", &GCSkillDamage::GetNPCDamageScalarVsNPC, &GCSkillDamage::SetNPCDamageScalarVsNPC)
        .addProperty("PhysicsForceDamage", &GCSkillDamage::GetPhysicsForceDamage, &GCSkillDamage::SetPhysicsForceDamage)
        .addFunction("ToPtr", &GCSkillDamage::ToPtr)
        .addFunction("IsValid", &GCSkillDamage::IsValid)
        .endClass();
}