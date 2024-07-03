#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimComponentUpdater::GCAnimComponentUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimComponentUpdater::GCAnimComponentUpdater(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimComponentUpdater::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAnimComponentUpdater", "m_name").Get();
}
void GCAnimComponentUpdater::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CAnimComponentUpdater", "m_name", false, CUtlString(value.c_str()));
}
GAnimComponentID GCAnimComponentUpdater::GetId() const {
    GAnimComponentID value(GetSchemaPtr(m_ptr, "CAnimComponentUpdater", "m_id"));
    return value;
}
void GCAnimComponentUpdater::SetId(GAnimComponentID value) {
    SetSchemaValue(m_ptr, "CAnimComponentUpdater", "m_id", false, value);
}
uint64_t GCAnimComponentUpdater::GetNetworkMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CAnimComponentUpdater", "m_networkMode");
}
void GCAnimComponentUpdater::SetNetworkMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CAnimComponentUpdater", "m_networkMode", false, value);
}
bool GCAnimComponentUpdater::GetStartEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimComponentUpdater", "m_bStartEnabled");
}
void GCAnimComponentUpdater::SetStartEnabled(bool value) {
    SetSchemaValue(m_ptr, "CAnimComponentUpdater", "m_bStartEnabled", false, value);
}
std::string GCAnimComponentUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimComponentUpdater::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimComponentUpdater>("CAnimComponentUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAnimComponentUpdater::GetName, &GCAnimComponentUpdater::SetName)
        .addProperty("Id", &GCAnimComponentUpdater::GetId, &GCAnimComponentUpdater::SetId)
        .addProperty("NetworkMode", &GCAnimComponentUpdater::GetNetworkMode, &GCAnimComponentUpdater::SetNetworkMode)
        .addProperty("StartEnabled", &GCAnimComponentUpdater::GetStartEnabled, &GCAnimComponentUpdater::SetStartEnabled)
        .addFunction("ToPtr", &GCAnimComponentUpdater::ToPtr)
        .addFunction("IsValid", &GCAnimComponentUpdater::IsValid)
        .endClass();
}