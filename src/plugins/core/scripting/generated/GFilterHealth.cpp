#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFilterHealth::GFilterHealth(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFilterHealth::GFilterHealth(void *ptr) {
    m_ptr = ptr;
}
bool GFilterHealth::GetAdrenalineActive() const {
    return GetSchemaValue<bool>(m_ptr, "FilterHealth", "m_bAdrenalineActive");
}
void GFilterHealth::SetAdrenalineActive(bool value) {
    SetSchemaValue(m_ptr, "FilterHealth", "m_bAdrenalineActive", false, value);
}
int32_t GFilterHealth::GetHealthMin() const {
    return GetSchemaValue<int32_t>(m_ptr, "FilterHealth", "m_iHealthMin");
}
void GFilterHealth::SetHealthMin(int32_t value) {
    SetSchemaValue(m_ptr, "FilterHealth", "m_iHealthMin", false, value);
}
int32_t GFilterHealth::GetHealthMax() const {
    return GetSchemaValue<int32_t>(m_ptr, "FilterHealth", "m_iHealthMax");
}
void GFilterHealth::SetHealthMax(int32_t value) {
    SetSchemaValue(m_ptr, "FilterHealth", "m_iHealthMax", false, value);
}
std::string GFilterHealth::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFilterHealth::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFilter GFilterHealth::GetParent() const {
    GCBaseFilter value(m_ptr);
    return value;
}
void GFilterHealth::SetParent(GCBaseFilter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassFilterHealth(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFilterHealth>("FilterHealth")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AdrenalineActive", &GFilterHealth::GetAdrenalineActive, &GFilterHealth::SetAdrenalineActive)
        .addProperty("HealthMin", &GFilterHealth::GetHealthMin, &GFilterHealth::SetHealthMin)
        .addProperty("HealthMax", &GFilterHealth::GetHealthMax, &GFilterHealth::SetHealthMax)
        .addProperty("Parent", &GFilterHealth::GetParent, &GFilterHealth::SetParent)
        .addFunction("ToPtr", &GFilterHealth::ToPtr)
        .addFunction("IsValid", &GFilterHealth::IsValid)
        .endClass();
}