#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavSpaceInfo::GCNavSpaceInfo(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavSpaceInfo::GCNavSpaceInfo(void *ptr) {
    m_ptr = ptr;
}
bool GCNavSpaceInfo::GetCreateFlightSpace() const {
    return GetSchemaValue<bool>(m_ptr, "CNavSpaceInfo", "m_bCreateFlightSpace");
}
void GCNavSpaceInfo::SetCreateFlightSpace(bool value) {
    SetSchemaValue(m_ptr, "CNavSpaceInfo", "m_bCreateFlightSpace", false, value);
}
std::string GCNavSpaceInfo::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavSpaceInfo::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCNavSpaceInfo::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCNavSpaceInfo::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNavSpaceInfo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavSpaceInfo>("CNavSpaceInfo")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CreateFlightSpace", &GCNavSpaceInfo::GetCreateFlightSpace, &GCNavSpaceInfo::SetCreateFlightSpace)
        .addProperty("Parent", &GCNavSpaceInfo::GetParent, &GCNavSpaceInfo::SetParent)
        .addFunction("ToPtr", &GCNavSpaceInfo::ToPtr)
        .addFunction("IsValid", &GCNavSpaceInfo::IsValid)
        .endClass();
}