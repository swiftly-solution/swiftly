#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseFilter::GCBaseFilter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseFilter::GCBaseFilter(void *ptr) {
    m_ptr = ptr;
}
bool GCBaseFilter::GetNegated() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseFilter", "m_bNegated");
}
void GCBaseFilter::SetNegated(bool value) {
    SetSchemaValue(m_ptr, "CBaseFilter", "m_bNegated", false, value);
}
GCEntityIOOutput GCBaseFilter::GetOnPass() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseFilter", "m_OnPass"));
    return value;
}
void GCBaseFilter::SetOnPass(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseFilter", "m_OnPass", false, value);
}
GCEntityIOOutput GCBaseFilter::GetOnFail() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CBaseFilter", "m_OnFail"));
    return value;
}
void GCBaseFilter::SetOnFail(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CBaseFilter", "m_OnFail", false, value);
}
std::string GCBaseFilter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseFilter::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCBaseFilter::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCBaseFilter::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseFilter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseFilter>("CBaseFilter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Negated", &GCBaseFilter::GetNegated, &GCBaseFilter::SetNegated)
        .addProperty("OnPass", &GCBaseFilter::GetOnPass, &GCBaseFilter::SetOnPass)
        .addProperty("OnFail", &GCBaseFilter::GetOnFail, &GCBaseFilter::SetOnFail)
        .addProperty("Parent", &GCBaseFilter::GetParent, &GCBaseFilter::SetParent)
        .addFunction("ToPtr", &GCBaseFilter::ToPtr)
        .addFunction("IsValid", &GCBaseFilter::IsValid)
        .endClass();
}