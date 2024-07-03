#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GJiggleBoneSettings_t::GJiggleBoneSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GJiggleBoneSettings_t::GJiggleBoneSettings_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GJiggleBoneSettings_t::GetBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "JiggleBoneSettings_t", "m_nBoneIndex");
}
void GJiggleBoneSettings_t::SetBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_nBoneIndex", true, value);
}
float GJiggleBoneSettings_t::GetSpringStrength() const {
    return GetSchemaValue<float>(m_ptr, "JiggleBoneSettings_t", "m_flSpringStrength");
}
void GJiggleBoneSettings_t::SetSpringStrength(float value) {
    SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_flSpringStrength", true, value);
}
float GJiggleBoneSettings_t::GetMaxTimeStep() const {
    return GetSchemaValue<float>(m_ptr, "JiggleBoneSettings_t", "m_flMaxTimeStep");
}
void GJiggleBoneSettings_t::SetMaxTimeStep(float value) {
    SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_flMaxTimeStep", true, value);
}
float GJiggleBoneSettings_t::GetDamping() const {
    return GetSchemaValue<float>(m_ptr, "JiggleBoneSettings_t", "m_flDamping");
}
void GJiggleBoneSettings_t::SetDamping(float value) {
    SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_flDamping", true, value);
}
Vector GJiggleBoneSettings_t::GetBoundsMaxLS() const {
    return GetSchemaValue<Vector>(m_ptr, "JiggleBoneSettings_t", "m_vBoundsMaxLS");
}
void GJiggleBoneSettings_t::SetBoundsMaxLS(Vector value) {
    SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_vBoundsMaxLS", true, value);
}
Vector GJiggleBoneSettings_t::GetBoundsMinLS() const {
    return GetSchemaValue<Vector>(m_ptr, "JiggleBoneSettings_t", "m_vBoundsMinLS");
}
void GJiggleBoneSettings_t::SetBoundsMinLS(Vector value) {
    SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_vBoundsMinLS", true, value);
}
uint64_t GJiggleBoneSettings_t::GetSimSpace() const {
    return GetSchemaValue<uint64_t>(m_ptr, "JiggleBoneSettings_t", "m_eSimSpace");
}
void GJiggleBoneSettings_t::SetSimSpace(uint64_t value) {
    SetSchemaValue(m_ptr, "JiggleBoneSettings_t", "m_eSimSpace", true, value);
}
std::string GJiggleBoneSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GJiggleBoneSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassJiggleBoneSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GJiggleBoneSettings_t>("JiggleBoneSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneIndex", &GJiggleBoneSettings_t::GetBoneIndex, &GJiggleBoneSettings_t::SetBoneIndex)
        .addProperty("SpringStrength", &GJiggleBoneSettings_t::GetSpringStrength, &GJiggleBoneSettings_t::SetSpringStrength)
        .addProperty("MaxTimeStep", &GJiggleBoneSettings_t::GetMaxTimeStep, &GJiggleBoneSettings_t::SetMaxTimeStep)
        .addProperty("Damping", &GJiggleBoneSettings_t::GetDamping, &GJiggleBoneSettings_t::SetDamping)
        .addProperty("BoundsMaxLS", &GJiggleBoneSettings_t::GetBoundsMaxLS, &GJiggleBoneSettings_t::SetBoundsMaxLS)
        .addProperty("BoundsMinLS", &GJiggleBoneSettings_t::GetBoundsMinLS, &GJiggleBoneSettings_t::SetBoundsMinLS)
        .addProperty("SimSpace", &GJiggleBoneSettings_t::GetSimSpace, &GJiggleBoneSettings_t::SetSimSpace)
        .addFunction("ToPtr", &GJiggleBoneSettings_t::ToPtr)
        .addFunction("IsValid", &GJiggleBoneSettings_t::IsValid)
        .endClass();
}