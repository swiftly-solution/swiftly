#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoVisibilityBox::GCInfoVisibilityBox(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoVisibilityBox::GCInfoVisibilityBox(void *ptr) {
    m_ptr = ptr;
}
int32_t GCInfoVisibilityBox::GetMode() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInfoVisibilityBox", "m_nMode");
}
void GCInfoVisibilityBox::SetMode(int32_t value) {
    SetSchemaValue(m_ptr, "CInfoVisibilityBox", "m_nMode", false, value);
}
Vector GCInfoVisibilityBox::GetBoxSize() const {
    return GetSchemaValue<Vector>(m_ptr, "CInfoVisibilityBox", "m_vBoxSize");
}
void GCInfoVisibilityBox::SetBoxSize(Vector value) {
    SetSchemaValue(m_ptr, "CInfoVisibilityBox", "m_vBoxSize", false, value);
}
bool GCInfoVisibilityBox::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CInfoVisibilityBox", "m_bEnabled");
}
void GCInfoVisibilityBox::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CInfoVisibilityBox", "m_bEnabled", false, value);
}
std::string GCInfoVisibilityBox::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoVisibilityBox::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCInfoVisibilityBox::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCInfoVisibilityBox::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoVisibilityBox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoVisibilityBox>("CInfoVisibilityBox")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Mode", &GCInfoVisibilityBox::GetMode, &GCInfoVisibilityBox::SetMode)
        .addProperty("BoxSize", &GCInfoVisibilityBox::GetBoxSize, &GCInfoVisibilityBox::SetBoxSize)
        .addProperty("Enabled", &GCInfoVisibilityBox::GetEnabled, &GCInfoVisibilityBox::SetEnabled)
        .addProperty("Parent", &GCInfoVisibilityBox::GetParent, &GCInfoVisibilityBox::SetParent)
        .addFunction("ToPtr", &GCInfoVisibilityBox::ToPtr)
        .addFunction("IsValid", &GCInfoVisibilityBox::IsValid)
        .endClass();
}