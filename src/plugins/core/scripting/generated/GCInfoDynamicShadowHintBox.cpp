#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoDynamicShadowHintBox::GCInfoDynamicShadowHintBox(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoDynamicShadowHintBox::GCInfoDynamicShadowHintBox(void *ptr) {
    m_ptr = ptr;
}
Vector GCInfoDynamicShadowHintBox::GetBoxMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CInfoDynamicShadowHintBox", "m_vBoxMins");
}
void GCInfoDynamicShadowHintBox::SetBoxMins(Vector value) {
    SetSchemaValue(m_ptr, "CInfoDynamicShadowHintBox", "m_vBoxMins", false, value);
}
Vector GCInfoDynamicShadowHintBox::GetBoxMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CInfoDynamicShadowHintBox", "m_vBoxMaxs");
}
void GCInfoDynamicShadowHintBox::SetBoxMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CInfoDynamicShadowHintBox", "m_vBoxMaxs", false, value);
}
std::string GCInfoDynamicShadowHintBox::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoDynamicShadowHintBox::IsValid() {
    return (m_ptr != nullptr);
}
GCInfoDynamicShadowHint GCInfoDynamicShadowHintBox::GetParent() const {
    GCInfoDynamicShadowHint value(m_ptr);
    return value;
}
void GCInfoDynamicShadowHintBox::SetParent(GCInfoDynamicShadowHint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoDynamicShadowHintBox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoDynamicShadowHintBox>("CInfoDynamicShadowHintBox")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoxMins", &GCInfoDynamicShadowHintBox::GetBoxMins, &GCInfoDynamicShadowHintBox::SetBoxMins)
        .addProperty("BoxMaxs", &GCInfoDynamicShadowHintBox::GetBoxMaxs, &GCInfoDynamicShadowHintBox::SetBoxMaxs)
        .addProperty("Parent", &GCInfoDynamicShadowHintBox::GetParent, &GCInfoDynamicShadowHintBox::SetParent)
        .addFunction("ToPtr", &GCInfoDynamicShadowHintBox::ToPtr)
        .addFunction("IsValid", &GCInfoDynamicShadowHintBox::IsValid)
        .endClass();
}