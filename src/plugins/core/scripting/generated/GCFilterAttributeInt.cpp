#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFilterAttributeInt::GCFilterAttributeInt(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFilterAttributeInt::GCFilterAttributeInt(void *ptr) {
    m_ptr = ptr;
}
CUtlStringToken GCFilterAttributeInt::GetAttributeName() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "CFilterAttributeInt", "m_sAttributeName");
}
void GCFilterAttributeInt::SetAttributeName(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "CFilterAttributeInt", "m_sAttributeName", false, value);
}
std::string GCFilterAttributeInt::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFilterAttributeInt::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFilter GCFilterAttributeInt::GetParent() const {
    GCBaseFilter value(m_ptr);
    return value;
}
void GCFilterAttributeInt::SetParent(GCBaseFilter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFilterAttributeInt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterAttributeInt>("CFilterAttributeInt")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AttributeName", &GCFilterAttributeInt::GetAttributeName, &GCFilterAttributeInt::SetAttributeName)
        .addProperty("Parent", &GCFilterAttributeInt::GetParent, &GCFilterAttributeInt::SetParent)
        .addFunction("ToPtr", &GCFilterAttributeInt::ToPtr)
        .addFunction("IsValid", &GCFilterAttributeInt::IsValid)
        .endClass();
}