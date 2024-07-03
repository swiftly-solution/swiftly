#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimInputDamping::GCAnimInputDamping(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimInputDamping::GCAnimInputDamping(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCAnimInputDamping::GetSpeedFunction() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CAnimInputDamping", "m_speedFunction");
}
void GCAnimInputDamping::SetSpeedFunction(uint64_t value) {
    SetSchemaValue(m_ptr, "CAnimInputDamping", "m_speedFunction", false, value);
}
float GCAnimInputDamping::GetSpeedScale() const {
    return GetSchemaValue<float>(m_ptr, "CAnimInputDamping", "m_fSpeedScale");
}
void GCAnimInputDamping::SetSpeedScale(float value) {
    SetSchemaValue(m_ptr, "CAnimInputDamping", "m_fSpeedScale", false, value);
}
std::string GCAnimInputDamping::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimInputDamping::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimInputDamping(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimInputDamping>("CAnimInputDamping")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SpeedFunction", &GCAnimInputDamping::GetSpeedFunction, &GCAnimInputDamping::SetSpeedFunction)
        .addProperty("SpeedScale", &GCAnimInputDamping::GetSpeedScale, &GCAnimInputDamping::SetSpeedScale)
        .addFunction("ToPtr", &GCAnimInputDamping::ToPtr)
        .addFunction("IsValid", &GCAnimInputDamping::IsValid)
        .endClass();
}