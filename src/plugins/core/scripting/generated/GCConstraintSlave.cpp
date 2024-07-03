#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCConstraintSlave::GCConstraintSlave(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCConstraintSlave::GCConstraintSlave(void *ptr) {
    m_ptr = ptr;
}
Quaternion GCConstraintSlave::GetBaseOrientation() const {
    return GetSchemaValue<Quaternion>(m_ptr, "CConstraintSlave", "m_qBaseOrientation");
}
void GCConstraintSlave::SetBaseOrientation(Quaternion value) {
    SetSchemaValue(m_ptr, "CConstraintSlave", "m_qBaseOrientation", false, value);
}
Vector GCConstraintSlave::GetBasePosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CConstraintSlave", "m_vBasePosition");
}
void GCConstraintSlave::SetBasePosition(Vector value) {
    SetSchemaValue(m_ptr, "CConstraintSlave", "m_vBasePosition", false, value);
}
uint32_t GCConstraintSlave::GetBoneHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CConstraintSlave", "m_nBoneHash");
}
void GCConstraintSlave::SetBoneHash(uint32_t value) {
    SetSchemaValue(m_ptr, "CConstraintSlave", "m_nBoneHash", false, value);
}
float GCConstraintSlave::GetWeight() const {
    return GetSchemaValue<float>(m_ptr, "CConstraintSlave", "m_flWeight");
}
void GCConstraintSlave::SetWeight(float value) {
    SetSchemaValue(m_ptr, "CConstraintSlave", "m_flWeight", false, value);
}
std::string GCConstraintSlave::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CConstraintSlave", "m_sName").Get();
}
void GCConstraintSlave::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CConstraintSlave", "m_sName", false, CUtlString(value.c_str()));
}
std::string GCConstraintSlave::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCConstraintSlave::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCConstraintSlave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCConstraintSlave>("CConstraintSlave")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BaseOrientation", &GCConstraintSlave::GetBaseOrientation, &GCConstraintSlave::SetBaseOrientation)
        .addProperty("BasePosition", &GCConstraintSlave::GetBasePosition, &GCConstraintSlave::SetBasePosition)
        .addProperty("BoneHash", &GCConstraintSlave::GetBoneHash, &GCConstraintSlave::SetBoneHash)
        .addProperty("Weight", &GCConstraintSlave::GetWeight, &GCConstraintSlave::SetWeight)
        .addProperty("Name", &GCConstraintSlave::GetName, &GCConstraintSlave::SetName)
        .addFunction("ToPtr", &GCConstraintSlave::ToPtr)
        .addFunction("IsValid", &GCConstraintSlave::IsValid)
        .endClass();
}