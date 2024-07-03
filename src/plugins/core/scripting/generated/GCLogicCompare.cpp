#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicCompare::GCLogicCompare(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicCompare::GCLogicCompare(void *ptr) {
    m_ptr = ptr;
}
float GCLogicCompare::GetInValue() const {
    return GetSchemaValue<float>(m_ptr, "CLogicCompare", "m_flInValue");
}
void GCLogicCompare::SetInValue(float value) {
    SetSchemaValue(m_ptr, "CLogicCompare", "m_flInValue", false, value);
}
float GCLogicCompare::GetCompareValue() const {
    return GetSchemaValue<float>(m_ptr, "CLogicCompare", "m_flCompareValue");
}
void GCLogicCompare::SetCompareValue(float value) {
    SetSchemaValue(m_ptr, "CLogicCompare", "m_flCompareValue", false, value);
}
std::string GCLogicCompare::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicCompare::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicCompare::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicCompare::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicCompare(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicCompare>("CLogicCompare")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InValue", &GCLogicCompare::GetInValue, &GCLogicCompare::SetInValue)
        .addProperty("CompareValue", &GCLogicCompare::GetCompareValue, &GCLogicCompare::SetCompareValue)
        .addProperty("Parent", &GCLogicCompare::GetParent, &GCLogicCompare::SetParent)
        .addFunction("ToPtr", &GCLogicCompare::ToPtr)
        .addFunction("IsValid", &GCLogicCompare::IsValid)
        .endClass();
}