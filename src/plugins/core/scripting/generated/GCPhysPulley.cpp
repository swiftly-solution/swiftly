#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysPulley::GCPhysPulley(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysPulley::GCPhysPulley(void *ptr) {
    m_ptr = ptr;
}
Vector GCPhysPulley::GetPosition2() const {
    return GetSchemaValue<Vector>(m_ptr, "CPhysPulley", "m_position2");
}
void GCPhysPulley::SetPosition2(Vector value) {
    SetSchemaValue(m_ptr, "CPhysPulley", "m_position2", false, value);
}
std::vector<Vector> GCPhysPulley::GetOffset() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CPhysPulley", "m_offset"); std::vector<Vector> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCPhysPulley::SetOffset(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "CPhysPulley", "m_offset"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPhysPulley", "m_offset", false, outValue);
}
float GCPhysPulley::GetAddLength() const {
    return GetSchemaValue<float>(m_ptr, "CPhysPulley", "m_addLength");
}
void GCPhysPulley::SetAddLength(float value) {
    SetSchemaValue(m_ptr, "CPhysPulley", "m_addLength", false, value);
}
float GCPhysPulley::GetGearRatio() const {
    return GetSchemaValue<float>(m_ptr, "CPhysPulley", "m_gearRatio");
}
void GCPhysPulley::SetGearRatio(float value) {
    SetSchemaValue(m_ptr, "CPhysPulley", "m_gearRatio", false, value);
}
std::string GCPhysPulley::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysPulley::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysConstraint GCPhysPulley::GetParent() const {
    GCPhysConstraint value(m_ptr);
    return value;
}
void GCPhysPulley::SetParent(GCPhysConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysPulley(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysPulley>("CPhysPulley")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Position2", &GCPhysPulley::GetPosition2, &GCPhysPulley::SetPosition2)
        .addProperty("Offset", &GCPhysPulley::GetOffset, &GCPhysPulley::SetOffset)
        .addProperty("AddLength", &GCPhysPulley::GetAddLength, &GCPhysPulley::SetAddLength)
        .addProperty("GearRatio", &GCPhysPulley::GetGearRatio, &GCPhysPulley::SetGearRatio)
        .addProperty("Parent", &GCPhysPulley::GetParent, &GCPhysPulley::SetParent)
        .addFunction("ToPtr", &GCPhysPulley::ToPtr)
        .addFunction("IsValid", &GCPhysPulley::IsValid)
        .endClass();
}