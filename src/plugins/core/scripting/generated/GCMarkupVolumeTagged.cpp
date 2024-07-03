#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMarkupVolumeTagged::GCMarkupVolumeTagged(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMarkupVolumeTagged::GCMarkupVolumeTagged(void *ptr) {
    m_ptr = ptr;
}
bool GCMarkupVolumeTagged::GetIsGroup() const {
    return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeTagged", "m_bIsGroup");
}
void GCMarkupVolumeTagged::SetIsGroup(bool value) {
    SetSchemaValue(m_ptr, "CMarkupVolumeTagged", "m_bIsGroup", false, value);
}
bool GCMarkupVolumeTagged::GetGroupByPrefab() const {
    return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeTagged", "m_bGroupByPrefab");
}
void GCMarkupVolumeTagged::SetGroupByPrefab(bool value) {
    SetSchemaValue(m_ptr, "CMarkupVolumeTagged", "m_bGroupByPrefab", false, value);
}
bool GCMarkupVolumeTagged::GetGroupByVolume() const {
    return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeTagged", "m_bGroupByVolume");
}
void GCMarkupVolumeTagged::SetGroupByVolume(bool value) {
    SetSchemaValue(m_ptr, "CMarkupVolumeTagged", "m_bGroupByVolume", false, value);
}
bool GCMarkupVolumeTagged::GetGroupOtherGroups() const {
    return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeTagged", "m_bGroupOtherGroups");
}
void GCMarkupVolumeTagged::SetGroupOtherGroups(bool value) {
    SetSchemaValue(m_ptr, "CMarkupVolumeTagged", "m_bGroupOtherGroups", false, value);
}
bool GCMarkupVolumeTagged::GetIsInGroup() const {
    return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeTagged", "m_bIsInGroup");
}
void GCMarkupVolumeTagged::SetIsInGroup(bool value) {
    SetSchemaValue(m_ptr, "CMarkupVolumeTagged", "m_bIsInGroup", false, value);
}
std::string GCMarkupVolumeTagged::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMarkupVolumeTagged::IsValid() {
    return (m_ptr != nullptr);
}
GCMarkupVolume GCMarkupVolumeTagged::GetParent() const {
    GCMarkupVolume value(m_ptr);
    return value;
}
void GCMarkupVolumeTagged::SetParent(GCMarkupVolume value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMarkupVolumeTagged(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMarkupVolumeTagged>("CMarkupVolumeTagged")
        .addConstructor<void (*)(std::string)>()
        .addProperty("IsGroup", &GCMarkupVolumeTagged::GetIsGroup, &GCMarkupVolumeTagged::SetIsGroup)
        .addProperty("GroupByPrefab", &GCMarkupVolumeTagged::GetGroupByPrefab, &GCMarkupVolumeTagged::SetGroupByPrefab)
        .addProperty("GroupByVolume", &GCMarkupVolumeTagged::GetGroupByVolume, &GCMarkupVolumeTagged::SetGroupByVolume)
        .addProperty("GroupOtherGroups", &GCMarkupVolumeTagged::GetGroupOtherGroups, &GCMarkupVolumeTagged::SetGroupOtherGroups)
        .addProperty("IsInGroup", &GCMarkupVolumeTagged::GetIsInGroup, &GCMarkupVolumeTagged::SetIsInGroup)
        .addProperty("Parent", &GCMarkupVolumeTagged::GetParent, &GCMarkupVolumeTagged::SetParent)
        .addFunction("ToPtr", &GCMarkupVolumeTagged::ToPtr)
        .addFunction("IsValid", &GCMarkupVolumeTagged::IsValid)
        .endClass();
}