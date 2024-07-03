#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVPhysXRange_t::GVPhysXRange_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVPhysXRange_t::GVPhysXRange_t(void *ptr) {
    m_ptr = ptr;
}
float GVPhysXRange_t::GetMin() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXRange_t", "m_flMin");
}
void GVPhysXRange_t::SetMin(float value) {
    SetSchemaValue(m_ptr, "VPhysXRange_t", "m_flMin", true, value);
}
float GVPhysXRange_t::GetMax() const {
    return GetSchemaValue<float>(m_ptr, "VPhysXRange_t", "m_flMax");
}
void GVPhysXRange_t::SetMax(float value) {
    SetSchemaValue(m_ptr, "VPhysXRange_t", "m_flMax", true, value);
}
std::string GVPhysXRange_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVPhysXRange_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVPhysXRange_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysXRange_t>("VPhysXRange_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Min", &GVPhysXRange_t::GetMin, &GVPhysXRange_t::SetMin)
        .addProperty("Max", &GVPhysXRange_t::GetMax, &GVPhysXRange_t::SetMax)
        .addFunction("ToPtr", &GVPhysXRange_t::ToPtr)
        .addFunction("IsValid", &GVPhysXRange_t::IsValid)
        .endClass();
}