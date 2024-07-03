#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVPhysXConstraint2_t::GVPhysXConstraint2_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVPhysXConstraint2_t::GVPhysXConstraint2_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GVPhysXConstraint2_t::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "VPhysXConstraint2_t", "m_nFlags");
}
void GVPhysXConstraint2_t::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "VPhysXConstraint2_t", "m_nFlags", true, value);
}
uint16_t GVPhysXConstraint2_t::GetParent() const {
    return GetSchemaValue<uint16_t>(m_ptr, "VPhysXConstraint2_t", "m_nParent");
}
void GVPhysXConstraint2_t::SetParent(uint16_t value) {
    SetSchemaValue(m_ptr, "VPhysXConstraint2_t", "m_nParent", true, value);
}
uint16_t GVPhysXConstraint2_t::GetChild() const {
    return GetSchemaValue<uint16_t>(m_ptr, "VPhysXConstraint2_t", "m_nChild");
}
void GVPhysXConstraint2_t::SetChild(uint16_t value) {
    SetSchemaValue(m_ptr, "VPhysXConstraint2_t", "m_nChild", true, value);
}
GVPhysXConstraintParams_t GVPhysXConstraint2_t::GetParams() const {
    GVPhysXConstraintParams_t value(GetSchemaPtr(m_ptr, "VPhysXConstraint2_t", "m_params"));
    return value;
}
void GVPhysXConstraint2_t::SetParams(GVPhysXConstraintParams_t value) {
    SetSchemaValue(m_ptr, "VPhysXConstraint2_t", "m_params", true, value);
}
std::string GVPhysXConstraint2_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVPhysXConstraint2_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVPhysXConstraint2_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysXConstraint2_t>("VPhysXConstraint2_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Flags", &GVPhysXConstraint2_t::GetFlags, &GVPhysXConstraint2_t::SetFlags)
        .addProperty("Parent", &GVPhysXConstraint2_t::GetParent, &GVPhysXConstraint2_t::SetParent)
        .addProperty("Child", &GVPhysXConstraint2_t::GetChild, &GVPhysXConstraint2_t::SetChild)
        .addProperty("Params", &GVPhysXConstraint2_t::GetParams, &GVPhysXConstraint2_t::SetParams)
        .addFunction("ToPtr", &GVPhysXConstraint2_t::ToPtr)
        .addFunction("IsValid", &GVPhysXConstraint2_t::IsValid)
        .endClass();
}