#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEconWearable::GCEconWearable(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEconWearable::GCEconWearable(void *ptr) {
    m_ptr = ptr;
}
int32_t GCEconWearable::GetForceSkin() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEconWearable", "m_nForceSkin");
}
void GCEconWearable::SetForceSkin(int32_t value) {
    SetSchemaValue(m_ptr, "CEconWearable", "m_nForceSkin", false, value);
}
bool GCEconWearable::GetAlwaysAllow() const {
    return GetSchemaValue<bool>(m_ptr, "CEconWearable", "m_bAlwaysAllow");
}
void GCEconWearable::SetAlwaysAllow(bool value) {
    SetSchemaValue(m_ptr, "CEconWearable", "m_bAlwaysAllow", false, value);
}
std::string GCEconWearable::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEconWearable::IsValid() {
    return (m_ptr != nullptr);
}
GCEconEntity GCEconWearable::GetParent() const {
    GCEconEntity value(m_ptr);
    return value;
}
void GCEconWearable::SetParent(GCEconEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEconWearable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEconWearable>("CEconWearable")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ForceSkin", &GCEconWearable::GetForceSkin, &GCEconWearable::SetForceSkin)
        .addProperty("AlwaysAllow", &GCEconWearable::GetAlwaysAllow, &GCEconWearable::SetAlwaysAllow)
        .addProperty("Parent", &GCEconWearable::GetParent, &GCEconWearable::SetParent)
        .addFunction("ToPtr", &GCEconWearable::ToPtr)
        .addFunction("IsValid", &GCEconWearable::IsValid)
        .endClass();
}