#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleFunctionPreEmission::GCParticleFunctionPreEmission(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleFunctionPreEmission::GCParticleFunctionPreEmission(void *ptr) {
    m_ptr = ptr;
}
bool GCParticleFunctionPreEmission::GetRunOnce() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleFunctionPreEmission", "m_bRunOnce");
}
void GCParticleFunctionPreEmission::SetRunOnce(bool value) {
    SetSchemaValue(m_ptr, "CParticleFunctionPreEmission", "m_bRunOnce", false, value);
}
std::string GCParticleFunctionPreEmission::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleFunctionPreEmission::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFunctionOperator GCParticleFunctionPreEmission::GetParent() const {
    GCParticleFunctionOperator value(m_ptr);
    return value;
}
void GCParticleFunctionPreEmission::SetParent(GCParticleFunctionOperator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleFunctionPreEmission(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionPreEmission>("CParticleFunctionPreEmission")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RunOnce", &GCParticleFunctionPreEmission::GetRunOnce, &GCParticleFunctionPreEmission::SetRunOnce)
        .addProperty("Parent", &GCParticleFunctionPreEmission::GetParent, &GCParticleFunctionPreEmission::SetParent)
        .addFunction("ToPtr", &GCParticleFunctionPreEmission::ToPtr)
        .addFunction("IsValid", &GCParticleFunctionPreEmission::IsValid)
        .endClass();
}