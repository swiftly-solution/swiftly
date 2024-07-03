#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPathSimple::GCPathSimple(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPathSimple::GCPathSimple(void *ptr) {
    m_ptr = ptr;
}
std::string GCPathSimple::GetPathString() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPathSimple", "m_pathString").Get();
}
void GCPathSimple::SetPathString(std::string value) {
    SetSchemaValue(m_ptr, "CPathSimple", "m_pathString", false, CUtlString(value.c_str()));
}
std::string GCPathSimple::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPathSimple::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCPathSimple::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCPathSimple::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPathSimple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathSimple>("CPathSimple")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PathString", &GCPathSimple::GetPathString, &GCPathSimple::SetPathString)
        .addProperty("Parent", &GCPathSimple::GetParent, &GCPathSimple::SetParent)
        .addFunction("ToPtr", &GCPathSimple::ToPtr)
        .addFunction("IsValid", &GCPathSimple::IsValid)
        .endClass();
}