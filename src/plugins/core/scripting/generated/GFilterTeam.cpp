#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFilterTeam::GFilterTeam(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFilterTeam::GFilterTeam(void *ptr) {
    m_ptr = ptr;
}
int32_t GFilterTeam::GetFilterTeam() const {
    return GetSchemaValue<int32_t>(m_ptr, "FilterTeam", "m_iFilterTeam");
}
void GFilterTeam::SetFilterTeam(int32_t value) {
    SetSchemaValue(m_ptr, "FilterTeam", "m_iFilterTeam", false, value);
}
std::string GFilterTeam::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFilterTeam::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFilter GFilterTeam::GetParent() const {
    GCBaseFilter value(m_ptr);
    return value;
}
void GFilterTeam::SetParent(GCBaseFilter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassFilterTeam(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFilterTeam>("FilterTeam")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FilterTeam", &GFilterTeam::GetFilterTeam, &GFilterTeam::SetFilterTeam)
        .addProperty("Parent", &GFilterTeam::GetParent, &GFilterTeam::SetParent)
        .addFunction("ToPtr", &GFilterTeam::ToPtr)
        .addFunction("IsValid", &GFilterTeam::IsValid)
        .endClass();
}