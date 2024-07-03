#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFootFixedData_t::GFootFixedData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFootFixedData_t::GFootFixedData_t(void *ptr) {
    m_ptr = ptr;
}
Vector GFootFixedData_t::GetToeOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "FootFixedData_t", "m_vToeOffset");
}
void GFootFixedData_t::SetToeOffset(Vector value) {
    SetSchemaValue(m_ptr, "FootFixedData_t", "m_vToeOffset", true, value);
}
Vector GFootFixedData_t::GetHeelOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "FootFixedData_t", "m_vHeelOffset");
}
void GFootFixedData_t::SetHeelOffset(Vector value) {
    SetSchemaValue(m_ptr, "FootFixedData_t", "m_vHeelOffset", true, value);
}
int32_t GFootFixedData_t::GetTargetBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FootFixedData_t", "m_nTargetBoneIndex");
}
void GFootFixedData_t::SetTargetBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FootFixedData_t", "m_nTargetBoneIndex", true, value);
}
int32_t GFootFixedData_t::GetAnkleBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FootFixedData_t", "m_nAnkleBoneIndex");
}
void GFootFixedData_t::SetAnkleBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FootFixedData_t", "m_nAnkleBoneIndex", true, value);
}
int32_t GFootFixedData_t::GetIKAnchorBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FootFixedData_t", "m_nIKAnchorBoneIndex");
}
void GFootFixedData_t::SetIKAnchorBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FootFixedData_t", "m_nIKAnchorBoneIndex", true, value);
}
int32_t GFootFixedData_t::GetIkChainIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FootFixedData_t", "m_ikChainIndex");
}
void GFootFixedData_t::SetIkChainIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FootFixedData_t", "m_ikChainIndex", true, value);
}
float GFootFixedData_t::GetMaxIKLength() const {
    return GetSchemaValue<float>(m_ptr, "FootFixedData_t", "m_flMaxIKLength");
}
void GFootFixedData_t::SetMaxIKLength(float value) {
    SetSchemaValue(m_ptr, "FootFixedData_t", "m_flMaxIKLength", true, value);
}
int32_t GFootFixedData_t::GetFootIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FootFixedData_t", "m_nFootIndex");
}
void GFootFixedData_t::SetFootIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FootFixedData_t", "m_nFootIndex", true, value);
}
int32_t GFootFixedData_t::GetTagIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FootFixedData_t", "m_nTagIndex");
}
void GFootFixedData_t::SetTagIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FootFixedData_t", "m_nTagIndex", true, value);
}
float GFootFixedData_t::GetMaxRotationLeft() const {
    return GetSchemaValue<float>(m_ptr, "FootFixedData_t", "m_flMaxRotationLeft");
}
void GFootFixedData_t::SetMaxRotationLeft(float value) {
    SetSchemaValue(m_ptr, "FootFixedData_t", "m_flMaxRotationLeft", true, value);
}
float GFootFixedData_t::GetMaxRotationRight() const {
    return GetSchemaValue<float>(m_ptr, "FootFixedData_t", "m_flMaxRotationRight");
}
void GFootFixedData_t::SetMaxRotationRight(float value) {
    SetSchemaValue(m_ptr, "FootFixedData_t", "m_flMaxRotationRight", true, value);
}
std::string GFootFixedData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFootFixedData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFootFixedData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFootFixedData_t>("FootFixedData_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ToeOffset", &GFootFixedData_t::GetToeOffset, &GFootFixedData_t::SetToeOffset)
        .addProperty("HeelOffset", &GFootFixedData_t::GetHeelOffset, &GFootFixedData_t::SetHeelOffset)
        .addProperty("TargetBoneIndex", &GFootFixedData_t::GetTargetBoneIndex, &GFootFixedData_t::SetTargetBoneIndex)
        .addProperty("AnkleBoneIndex", &GFootFixedData_t::GetAnkleBoneIndex, &GFootFixedData_t::SetAnkleBoneIndex)
        .addProperty("IKAnchorBoneIndex", &GFootFixedData_t::GetIKAnchorBoneIndex, &GFootFixedData_t::SetIKAnchorBoneIndex)
        .addProperty("IkChainIndex", &GFootFixedData_t::GetIkChainIndex, &GFootFixedData_t::SetIkChainIndex)
        .addProperty("MaxIKLength", &GFootFixedData_t::GetMaxIKLength, &GFootFixedData_t::SetMaxIKLength)
        .addProperty("FootIndex", &GFootFixedData_t::GetFootIndex, &GFootFixedData_t::SetFootIndex)
        .addProperty("TagIndex", &GFootFixedData_t::GetTagIndex, &GFootFixedData_t::SetTagIndex)
        .addProperty("MaxRotationLeft", &GFootFixedData_t::GetMaxRotationLeft, &GFootFixedData_t::SetMaxRotationLeft)
        .addProperty("MaxRotationRight", &GFootFixedData_t::GetMaxRotationRight, &GFootFixedData_t::SetMaxRotationRight)
        .addFunction("ToPtr", &GFootFixedData_t::ToPtr)
        .addFunction("IsValid", &GFootFixedData_t::IsValid)
        .endClass();
}