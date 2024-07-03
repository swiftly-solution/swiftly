#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimUpdateSharedData::GCAnimUpdateSharedData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimUpdateSharedData::GCAnimUpdateSharedData(void *ptr) {
    m_ptr = ptr;
}
GCAnimGraphSettingsManager GCAnimUpdateSharedData::GetSettings() const {
    GCAnimGraphSettingsManager value(GetSchemaPtr(m_ptr, "CAnimUpdateSharedData", "m_settings"));
    return value;
}
void GCAnimUpdateSharedData::SetSettings(GCAnimGraphSettingsManager value) {
    SetSchemaValue(m_ptr, "CAnimUpdateSharedData", "m_settings", false, value);
}
GCAnimNodePath GCAnimUpdateSharedData::GetRootNodePath() const {
    GCAnimNodePath value(GetSchemaPtr(m_ptr, "CAnimUpdateSharedData", "m_rootNodePath"));
    return value;
}
void GCAnimUpdateSharedData::SetRootNodePath(GCAnimNodePath value) {
    SetSchemaValue(m_ptr, "CAnimUpdateSharedData", "m_rootNodePath", false, value);
}
std::string GCAnimUpdateSharedData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimUpdateSharedData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimUpdateSharedData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimUpdateSharedData>("CAnimUpdateSharedData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Settings", &GCAnimUpdateSharedData::GetSettings, &GCAnimUpdateSharedData::SetSettings)
        .addProperty("RootNodePath", &GCAnimUpdateSharedData::GetRootNodePath, &GCAnimUpdateSharedData::SetRootNodePath)
        .addFunction("ToPtr", &GCAnimUpdateSharedData::ToPtr)
        .addFunction("IsValid", &GCAnimUpdateSharedData::IsValid)
        .endClass();
}