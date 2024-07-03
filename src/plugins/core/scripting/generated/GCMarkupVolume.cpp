#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMarkupVolume::GCMarkupVolume(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMarkupVolume::GCMarkupVolume(void *ptr) {
    m_ptr = ptr;
}
bool GCMarkupVolume::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CMarkupVolume", "m_bDisabled");
}
void GCMarkupVolume::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CMarkupVolume", "m_bDisabled", false, value);
}
std::string GCMarkupVolume::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMarkupVolume::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCMarkupVolume::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCMarkupVolume::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMarkupVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMarkupVolume>("CMarkupVolume")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCMarkupVolume::GetDisabled, &GCMarkupVolume::SetDisabled)
        .addProperty("Parent", &GCMarkupVolume::GetParent, &GCMarkupVolume::SetParent)
        .addFunction("ToPtr", &GCMarkupVolume::ToPtr)
        .addFunction("IsValid", &GCMarkupVolume::IsValid)
        .endClass();
}