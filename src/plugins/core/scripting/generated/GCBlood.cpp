#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBlood::GCBlood(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBlood::GCBlood(void *ptr) {
    m_ptr = ptr;
}
QAngle GCBlood::GetSprayAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBlood", "m_vecSprayAngles");
}
void GCBlood::SetSprayAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CBlood", "m_vecSprayAngles", false, value);
}
Vector GCBlood::GetSprayDir() const {
    return GetSchemaValue<Vector>(m_ptr, "CBlood", "m_vecSprayDir");
}
void GCBlood::SetSprayDir(Vector value) {
    SetSchemaValue(m_ptr, "CBlood", "m_vecSprayDir", false, value);
}
float GCBlood::GetAmount() const {
    return GetSchemaValue<float>(m_ptr, "CBlood", "m_flAmount");
}
void GCBlood::SetAmount(float value) {
    SetSchemaValue(m_ptr, "CBlood", "m_flAmount", false, value);
}
uint64_t GCBlood::GetColor() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBlood", "m_Color");
}
void GCBlood::SetColor(uint64_t value) {
    SetSchemaValue(m_ptr, "CBlood", "m_Color", false, value);
}
std::string GCBlood::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBlood::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCBlood::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCBlood::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBlood(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBlood>("CBlood")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SprayAngles", &GCBlood::GetSprayAngles, &GCBlood::SetSprayAngles)
        .addProperty("SprayDir", &GCBlood::GetSprayDir, &GCBlood::SetSprayDir)
        .addProperty("Amount", &GCBlood::GetAmount, &GCBlood::SetAmount)
        .addProperty("Color", &GCBlood::GetColor, &GCBlood::SetColor)
        .addProperty("Parent", &GCBlood::GetParent, &GCBlood::SetParent)
        .addFunction("ToPtr", &GCBlood::ToPtr)
        .addFunction("IsValid", &GCBlood::IsValid)
        .endClass();
}