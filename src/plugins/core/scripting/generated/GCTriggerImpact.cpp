#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerImpact::GCTriggerImpact(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerImpact::GCTriggerImpact(void *ptr) {
    m_ptr = ptr;
}
float GCTriggerImpact::GetMagnitude() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerImpact", "m_flMagnitude");
}
void GCTriggerImpact::SetMagnitude(float value) {
    SetSchemaValue(m_ptr, "CTriggerImpact", "m_flMagnitude", false, value);
}
float GCTriggerImpact::GetNoise() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerImpact", "m_flNoise");
}
void GCTriggerImpact::SetNoise(float value) {
    SetSchemaValue(m_ptr, "CTriggerImpact", "m_flNoise", false, value);
}
float GCTriggerImpact::GetViewkick() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerImpact", "m_flViewkick");
}
void GCTriggerImpact::SetViewkick(float value) {
    SetSchemaValue(m_ptr, "CTriggerImpact", "m_flViewkick", false, value);
}
std::string GCTriggerImpact::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerImpact::IsValid() {
    return (m_ptr != nullptr);
}
GCTriggerMultiple GCTriggerImpact::GetParent() const {
    GCTriggerMultiple value(m_ptr);
    return value;
}
void GCTriggerImpact::SetParent(GCTriggerMultiple value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerImpact(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerImpact>("CTriggerImpact")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Magnitude", &GCTriggerImpact::GetMagnitude, &GCTriggerImpact::SetMagnitude)
        .addProperty("Noise", &GCTriggerImpact::GetNoise, &GCTriggerImpact::SetNoise)
        .addProperty("Viewkick", &GCTriggerImpact::GetViewkick, &GCTriggerImpact::SetViewkick)
        .addProperty("Parent", &GCTriggerImpact::GetParent, &GCTriggerImpact::SetParent)
        .addFunction("ToPtr", &GCTriggerImpact::ToPtr)
        .addFunction("IsValid", &GCTriggerImpact::IsValid)
        .endClass();
}