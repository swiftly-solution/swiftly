#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerBrush::GCTriggerBrush(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerBrush::GCTriggerBrush(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCTriggerBrush::GetOnStartTouch() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerBrush", "m_OnStartTouch"));
    return value;
}
void GCTriggerBrush::SetOnStartTouch(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerBrush", "m_OnStartTouch", false, value);
}
GCEntityIOOutput GCTriggerBrush::GetOnEndTouch() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerBrush", "m_OnEndTouch"));
    return value;
}
void GCTriggerBrush::SetOnEndTouch(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerBrush", "m_OnEndTouch", false, value);
}
GCEntityIOOutput GCTriggerBrush::GetOnUse() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerBrush", "m_OnUse"));
    return value;
}
void GCTriggerBrush::SetOnUse(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerBrush", "m_OnUse", false, value);
}
int32_t GCTriggerBrush::GetInputFilter() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTriggerBrush", "m_iInputFilter");
}
void GCTriggerBrush::SetInputFilter(int32_t value) {
    SetSchemaValue(m_ptr, "CTriggerBrush", "m_iInputFilter", false, value);
}
int32_t GCTriggerBrush::GetDontMessageParent() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTriggerBrush", "m_iDontMessageParent");
}
void GCTriggerBrush::SetDontMessageParent(int32_t value) {
    SetSchemaValue(m_ptr, "CTriggerBrush", "m_iDontMessageParent", false, value);
}
std::string GCTriggerBrush::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerBrush::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCTriggerBrush::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCTriggerBrush::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerBrush(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerBrush>("CTriggerBrush")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnStartTouch", &GCTriggerBrush::GetOnStartTouch, &GCTriggerBrush::SetOnStartTouch)
        .addProperty("OnEndTouch", &GCTriggerBrush::GetOnEndTouch, &GCTriggerBrush::SetOnEndTouch)
        .addProperty("OnUse", &GCTriggerBrush::GetOnUse, &GCTriggerBrush::SetOnUse)
        .addProperty("InputFilter", &GCTriggerBrush::GetInputFilter, &GCTriggerBrush::SetInputFilter)
        .addProperty("DontMessageParent", &GCTriggerBrush::GetDontMessageParent, &GCTriggerBrush::SetDontMessageParent)
        .addProperty("Parent", &GCTriggerBrush::GetParent, &GCTriggerBrush::SetParent)
        .addFunction("ToPtr", &GCTriggerBrush::ToPtr)
        .addFunction("IsValid", &GCTriggerBrush::IsValid)
        .endClass();
}