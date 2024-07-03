#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCConstraintTarget::GCConstraintTarget(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCConstraintTarget::GCConstraintTarget(void *ptr) {
    m_ptr = ptr;
}
Quaternion GCConstraintTarget::GetOffset() const {
    return GetSchemaValue<Quaternion>(m_ptr, "CConstraintTarget", "m_qOffset");
}
void GCConstraintTarget::SetOffset(Quaternion value) {
    SetSchemaValue(m_ptr, "CConstraintTarget", "m_qOffset", false, value);
}
Vector GCConstraintTarget::GetOffset1() const {
    return GetSchemaValue<Vector>(m_ptr, "CConstraintTarget", "m_vOffset");
}
void GCConstraintTarget::SetOffset1(Vector value) {
    SetSchemaValue(m_ptr, "CConstraintTarget", "m_vOffset", false, value);
}
uint32_t GCConstraintTarget::GetBoneHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CConstraintTarget", "m_nBoneHash");
}
void GCConstraintTarget::SetBoneHash(uint32_t value) {
    SetSchemaValue(m_ptr, "CConstraintTarget", "m_nBoneHash", false, value);
}
std::string GCConstraintTarget::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CConstraintTarget", "m_sName").Get();
}
void GCConstraintTarget::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CConstraintTarget", "m_sName", false, CUtlString(value.c_str()));
}
float GCConstraintTarget::GetWeight() const {
    return GetSchemaValue<float>(m_ptr, "CConstraintTarget", "m_flWeight");
}
void GCConstraintTarget::SetWeight(float value) {
    SetSchemaValue(m_ptr, "CConstraintTarget", "m_flWeight", false, value);
}
bool GCConstraintTarget::GetIsAttachment() const {
    return GetSchemaValue<bool>(m_ptr, "CConstraintTarget", "m_bIsAttachment");
}
void GCConstraintTarget::SetIsAttachment(bool value) {
    SetSchemaValue(m_ptr, "CConstraintTarget", "m_bIsAttachment", false, value);
}
std::string GCConstraintTarget::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCConstraintTarget::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCConstraintTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCConstraintTarget>("CConstraintTarget")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Offset", &GCConstraintTarget::GetOffset, &GCConstraintTarget::SetOffset)
        .addProperty("Offset1", &GCConstraintTarget::GetOffset1, &GCConstraintTarget::SetOffset1)
        .addProperty("BoneHash", &GCConstraintTarget::GetBoneHash, &GCConstraintTarget::SetBoneHash)
        .addProperty("Name", &GCConstraintTarget::GetName, &GCConstraintTarget::SetName)
        .addProperty("Weight", &GCConstraintTarget::GetWeight, &GCConstraintTarget::SetWeight)
        .addProperty("IsAttachment", &GCConstraintTarget::GetIsAttachment, &GCConstraintTarget::SetIsAttachment)
        .addFunction("ToPtr", &GCConstraintTarget::ToPtr)
        .addFunction("IsValid", &GCConstraintTarget::IsValid)
        .endClass();
}