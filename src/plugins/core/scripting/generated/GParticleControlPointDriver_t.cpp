#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GParticleControlPointDriver_t::GParticleControlPointDriver_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GParticleControlPointDriver_t::GParticleControlPointDriver_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GParticleControlPointDriver_t::GetControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "ParticleControlPointDriver_t", "m_iControlPoint");
}
void GParticleControlPointDriver_t::SetControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "ParticleControlPointDriver_t", "m_iControlPoint", true, value);
}
uint64_t GParticleControlPointDriver_t::GetAttachType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "ParticleControlPointDriver_t", "m_iAttachType");
}
void GParticleControlPointDriver_t::SetAttachType(uint64_t value) {
    SetSchemaValue(m_ptr, "ParticleControlPointDriver_t", "m_iAttachType", true, value);
}
std::string GParticleControlPointDriver_t::GetAttachmentName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ParticleControlPointDriver_t", "m_attachmentName").Get();
}
void GParticleControlPointDriver_t::SetAttachmentName(std::string value) {
    SetSchemaValue(m_ptr, "ParticleControlPointDriver_t", "m_attachmentName", true, CUtlString(value.c_str()));
}
Vector GParticleControlPointDriver_t::GetOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "ParticleControlPointDriver_t", "m_vecOffset");
}
void GParticleControlPointDriver_t::SetOffset(Vector value) {
    SetSchemaValue(m_ptr, "ParticleControlPointDriver_t", "m_vecOffset", true, value);
}
QAngle GParticleControlPointDriver_t::GetOffset1() const {
    return GetSchemaValue<QAngle>(m_ptr, "ParticleControlPointDriver_t", "m_angOffset");
}
void GParticleControlPointDriver_t::SetOffset1(QAngle value) {
    SetSchemaValue(m_ptr, "ParticleControlPointDriver_t", "m_angOffset", true, value);
}
std::string GParticleControlPointDriver_t::GetEntityName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ParticleControlPointDriver_t", "m_entityName").Get();
}
void GParticleControlPointDriver_t::SetEntityName(std::string value) {
    SetSchemaValue(m_ptr, "ParticleControlPointDriver_t", "m_entityName", true, CUtlString(value.c_str()));
}
std::string GParticleControlPointDriver_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GParticleControlPointDriver_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassParticleControlPointDriver_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleControlPointDriver_t>("ParticleControlPointDriver_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ControlPoint", &GParticleControlPointDriver_t::GetControlPoint, &GParticleControlPointDriver_t::SetControlPoint)
        .addProperty("AttachType", &GParticleControlPointDriver_t::GetAttachType, &GParticleControlPointDriver_t::SetAttachType)
        .addProperty("AttachmentName", &GParticleControlPointDriver_t::GetAttachmentName, &GParticleControlPointDriver_t::SetAttachmentName)
        .addProperty("Offset", &GParticleControlPointDriver_t::GetOffset, &GParticleControlPointDriver_t::SetOffset)
        .addProperty("Offset1", &GParticleControlPointDriver_t::GetOffset1, &GParticleControlPointDriver_t::SetOffset1)
        .addProperty("EntityName", &GParticleControlPointDriver_t::GetEntityName, &GParticleControlPointDriver_t::SetEntityName)
        .addFunction("ToPtr", &GParticleControlPointDriver_t::ToPtr)
        .addFunction("IsValid", &GParticleControlPointDriver_t::IsValid)
        .endClass();
}