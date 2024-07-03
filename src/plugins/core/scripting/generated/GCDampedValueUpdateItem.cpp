#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDampedValueUpdateItem::GCDampedValueUpdateItem(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDampedValueUpdateItem::GCDampedValueUpdateItem(void *ptr) {
    m_ptr = ptr;
}
GCAnimInputDamping GCDampedValueUpdateItem::GetDamping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "CDampedValueUpdateItem", "m_damping"));
    return value;
}
void GCDampedValueUpdateItem::SetDamping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "CDampedValueUpdateItem", "m_damping", false, value);
}
GCAnimParamHandle GCDampedValueUpdateItem::GetParamIn() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CDampedValueUpdateItem", "m_hParamIn"));
    return value;
}
void GCDampedValueUpdateItem::SetParamIn(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CDampedValueUpdateItem", "m_hParamIn", false, value);
}
GCAnimParamHandle GCDampedValueUpdateItem::GetParamOut() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CDampedValueUpdateItem", "m_hParamOut"));
    return value;
}
void GCDampedValueUpdateItem::SetParamOut(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CDampedValueUpdateItem", "m_hParamOut", false, value);
}
std::string GCDampedValueUpdateItem::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDampedValueUpdateItem::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCDampedValueUpdateItem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDampedValueUpdateItem>("CDampedValueUpdateItem")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Damping", &GCDampedValueUpdateItem::GetDamping, &GCDampedValueUpdateItem::SetDamping)
        .addProperty("ParamIn", &GCDampedValueUpdateItem::GetParamIn, &GCDampedValueUpdateItem::SetParamIn)
        .addProperty("ParamOut", &GCDampedValueUpdateItem::GetParamOut, &GCDampedValueUpdateItem::SetParamOut)
        .addFunction("ToPtr", &GCDampedValueUpdateItem::ToPtr)
        .addFunction("IsValid", &GCDampedValueUpdateItem::IsValid)
        .endClass();
}