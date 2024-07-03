#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAimConstraint::GCAimConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAimConstraint::GCAimConstraint(void *ptr) {
    m_ptr = ptr;
}
Quaternion GCAimConstraint::GetAimOffset() const {
    return GetSchemaValue<Quaternion>(m_ptr, "CAimConstraint", "m_qAimOffset");
}
void GCAimConstraint::SetAimOffset(Quaternion value) {
    SetSchemaValue(m_ptr, "CAimConstraint", "m_qAimOffset", false, value);
}
uint32_t GCAimConstraint::GetUpType() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CAimConstraint", "m_nUpType");
}
void GCAimConstraint::SetUpType(uint32_t value) {
    SetSchemaValue(m_ptr, "CAimConstraint", "m_nUpType", false, value);
}
std::string GCAimConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAimConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseConstraint GCAimConstraint::GetParent() const {
    GCBaseConstraint value(m_ptr);
    return value;
}
void GCAimConstraint::SetParent(GCBaseConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAimConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAimConstraint>("CAimConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AimOffset", &GCAimConstraint::GetAimOffset, &GCAimConstraint::SetAimOffset)
        .addProperty("UpType", &GCAimConstraint::GetUpType, &GCAimConstraint::SetUpType)
        .addProperty("Parent", &GCAimConstraint::GetParent, &GCAimConstraint::SetParent)
        .addFunction("ToPtr", &GCAimConstraint::ToPtr)
        .addFunction("IsValid", &GCAimConstraint::IsValid)
        .endClass();
}