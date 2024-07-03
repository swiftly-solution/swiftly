#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBodyGroupSetting::GCBodyGroupSetting(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBodyGroupSetting::GCBodyGroupSetting(void *ptr) {
    m_ptr = ptr;
}
std::string GCBodyGroupSetting::GetBodyGroupName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBodyGroupSetting", "m_BodyGroupName").Get();
}
void GCBodyGroupSetting::SetBodyGroupName(std::string value) {
    SetSchemaValue(m_ptr, "CBodyGroupSetting", "m_BodyGroupName", false, CUtlString(value.c_str()));
}
int32_t GCBodyGroupSetting::GetBodyGroupOption() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBodyGroupSetting", "m_nBodyGroupOption");
}
void GCBodyGroupSetting::SetBodyGroupOption(int32_t value) {
    SetSchemaValue(m_ptr, "CBodyGroupSetting", "m_nBodyGroupOption", false, value);
}
std::string GCBodyGroupSetting::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBodyGroupSetting::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCBodyGroupSetting(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyGroupSetting>("CBodyGroupSetting")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BodyGroupName", &GCBodyGroupSetting::GetBodyGroupName, &GCBodyGroupSetting::SetBodyGroupName)
        .addProperty("BodyGroupOption", &GCBodyGroupSetting::GetBodyGroupOption, &GCBodyGroupSetting::SetBodyGroupOption)
        .addFunction("ToPtr", &GCBodyGroupSetting::ToPtr)
        .addFunction("IsValid", &GCBodyGroupSetting::IsValid)
        .endClass();
}