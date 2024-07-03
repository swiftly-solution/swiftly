#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysLength::GCPhysLength(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysLength::GCPhysLength(void *ptr) {
    m_ptr = ptr;
}
std::vector<Vector> GCPhysLength::GetOffset() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CPhysLength", "m_offset"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCPhysLength::SetOffset(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CPhysLength", "m_offset"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPhysLength", "m_offset", false, outValue);
}
Vector GCPhysLength::GetAttach() const {
    return GetSchemaValue<Vector>(m_ptr, "CPhysLength", "m_vecAttach");
}
void GCPhysLength::SetAttach(Vector value) {
    SetSchemaValue(m_ptr, "CPhysLength", "m_vecAttach", false, value);
}
float GCPhysLength::GetAddLength() const {
    return GetSchemaValue<float>(m_ptr, "CPhysLength", "m_addLength");
}
void GCPhysLength::SetAddLength(float value) {
    SetSchemaValue(m_ptr, "CPhysLength", "m_addLength", false, value);
}
float GCPhysLength::GetMinLength() const {
    return GetSchemaValue<float>(m_ptr, "CPhysLength", "m_minLength");
}
void GCPhysLength::SetMinLength(float value) {
    SetSchemaValue(m_ptr, "CPhysLength", "m_minLength", false, value);
}
float GCPhysLength::GetTotalLength() const {
    return GetSchemaValue<float>(m_ptr, "CPhysLength", "m_totalLength");
}
void GCPhysLength::SetTotalLength(float value) {
    SetSchemaValue(m_ptr, "CPhysLength", "m_totalLength", false, value);
}
bool GCPhysLength::GetEnableCollision() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysLength", "m_bEnableCollision");
}
void GCPhysLength::SetEnableCollision(bool value) {
    SetSchemaValue(m_ptr, "CPhysLength", "m_bEnableCollision", false, value);
}
std::string GCPhysLength::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysLength::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysConstraint GCPhysLength::GetParent() const {
    GCPhysConstraint value(m_ptr);
    return value;
}
void GCPhysLength::SetParent(GCPhysConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysLength(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysLength>("CPhysLength")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Offset", &GCPhysLength::GetOffset, &GCPhysLength::SetOffset)
        .addProperty("Attach", &GCPhysLength::GetAttach, &GCPhysLength::SetAttach)
        .addProperty("AddLength", &GCPhysLength::GetAddLength, &GCPhysLength::SetAddLength)
        .addProperty("MinLength", &GCPhysLength::GetMinLength, &GCPhysLength::SetMinLength)
        .addProperty("TotalLength", &GCPhysLength::GetTotalLength, &GCPhysLength::SetTotalLength)
        .addProperty("EnableCollision", &GCPhysLength::GetEnableCollision, &GCPhysLength::SetEnableCollision)
        .addProperty("Parent", &GCPhysLength::GetParent, &GCPhysLength::SetParent)
        .addFunction("ToPtr", &GCPhysLength::ToPtr)
        .addFunction("IsValid", &GCPhysLength::IsValid)
        .endClass();
}