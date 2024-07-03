#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerBuoyancy::GCTriggerBuoyancy(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerBuoyancy::GCTriggerBuoyancy(void *ptr) {
    m_ptr = ptr;
}
GCBuoyancyHelper GCTriggerBuoyancy::GetBuoyancyHelper() const {
    GCBuoyancyHelper value(GetSchemaPtr(m_ptr, "CTriggerBuoyancy", "m_BuoyancyHelper"));
    return value;
}
void GCTriggerBuoyancy::SetBuoyancyHelper(GCBuoyancyHelper value) {
    SetSchemaValue(m_ptr, "CTriggerBuoyancy", "m_BuoyancyHelper", false, value);
}
float GCTriggerBuoyancy::GetFluidDensity() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerBuoyancy", "m_flFluidDensity");
}
void GCTriggerBuoyancy::SetFluidDensity(float value) {
    SetSchemaValue(m_ptr, "CTriggerBuoyancy", "m_flFluidDensity", false, value);
}
std::string GCTriggerBuoyancy::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerBuoyancy::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerBuoyancy::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerBuoyancy::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerBuoyancy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerBuoyancy>("CTriggerBuoyancy")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BuoyancyHelper", &GCTriggerBuoyancy::GetBuoyancyHelper, &GCTriggerBuoyancy::SetBuoyancyHelper)
        .addProperty("FluidDensity", &GCTriggerBuoyancy::GetFluidDensity, &GCTriggerBuoyancy::SetFluidDensity)
        .addProperty("Parent", &GCTriggerBuoyancy::GetParent, &GCTriggerBuoyancy::SetParent)
        .addFunction("ToPtr", &GCTriggerBuoyancy::ToPtr)
        .addFunction("IsValid", &GCTriggerBuoyancy::IsValid)
        .endClass();
}