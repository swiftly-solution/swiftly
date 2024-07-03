#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicBranch::GCLogicBranch(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicBranch::GCLogicBranch(void *ptr) {
    m_ptr = ptr;
}
bool GCLogicBranch::GetInValue() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicBranch", "m_bInValue");
}
void GCLogicBranch::SetInValue(bool value) {
    SetSchemaValue(m_ptr, "CLogicBranch", "m_bInValue", false, value);
}
GCEntityIOOutput GCLogicBranch::GetOnTrue() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicBranch", "m_OnTrue"));
    return value;
}
void GCLogicBranch::SetOnTrue(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicBranch", "m_OnTrue", false, value);
}
GCEntityIOOutput GCLogicBranch::GetOnFalse() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicBranch", "m_OnFalse"));
    return value;
}
void GCLogicBranch::SetOnFalse(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicBranch", "m_OnFalse", false, value);
}
std::string GCLogicBranch::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicBranch::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicBranch::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicBranch::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicBranch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicBranch>("CLogicBranch")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InValue", &GCLogicBranch::GetInValue, &GCLogicBranch::SetInValue)
        .addProperty("OnTrue", &GCLogicBranch::GetOnTrue, &GCLogicBranch::SetOnTrue)
        .addProperty("OnFalse", &GCLogicBranch::GetOnFalse, &GCLogicBranch::SetOnFalse)
        .addProperty("Parent", &GCLogicBranch::GetParent, &GCLogicBranch::SetParent)
        .addFunction("ToPtr", &GCLogicBranch::ToPtr)
        .addFunction("IsValid", &GCLogicBranch::IsValid)
        .endClass();
}