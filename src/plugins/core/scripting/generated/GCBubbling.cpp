#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBubbling::GCBubbling(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBubbling::GCBubbling(void *ptr) {
    m_ptr = ptr;
}
int32_t GCBubbling::GetDensity() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBubbling", "m_density");
}
void GCBubbling::SetDensity(int32_t value) {
    SetSchemaValue(m_ptr, "CBubbling", "m_density", false, value);
}
int32_t GCBubbling::GetFrequency() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBubbling", "m_frequency");
}
void GCBubbling::SetFrequency(int32_t value) {
    SetSchemaValue(m_ptr, "CBubbling", "m_frequency", false, value);
}
int32_t GCBubbling::GetState() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBubbling", "m_state");
}
void GCBubbling::SetState(int32_t value) {
    SetSchemaValue(m_ptr, "CBubbling", "m_state", false, value);
}
std::string GCBubbling::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBubbling::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCBubbling::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCBubbling::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBubbling(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBubbling>("CBubbling")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Density", &GCBubbling::GetDensity, &GCBubbling::SetDensity)
        .addProperty("Frequency", &GCBubbling::GetFrequency, &GCBubbling::SetFrequency)
        .addProperty("State", &GCBubbling::GetState, &GCBubbling::SetState)
        .addProperty("Parent", &GCBubbling::GetParent, &GCBubbling::SetParent)
        .addFunction("ToPtr", &GCBubbling::ToPtr)
        .addFunction("IsValid", &GCBubbling::IsValid)
        .endClass();
}