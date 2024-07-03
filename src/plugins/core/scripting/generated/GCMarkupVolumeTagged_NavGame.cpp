#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMarkupVolumeTagged_NavGame::GCMarkupVolumeTagged_NavGame(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMarkupVolumeTagged_NavGame::GCMarkupVolumeTagged_NavGame(void *ptr) {
    m_ptr = ptr;
}
bool GCMarkupVolumeTagged_NavGame::GetFloodFillAttribute() const {
    return GetSchemaValue<bool>(m_ptr, "CMarkupVolumeTagged_NavGame", "m_bFloodFillAttribute");
}
void GCMarkupVolumeTagged_NavGame::SetFloodFillAttribute(bool value) {
    SetSchemaValue(m_ptr, "CMarkupVolumeTagged_NavGame", "m_bFloodFillAttribute", false, value);
}
std::string GCMarkupVolumeTagged_NavGame::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMarkupVolumeTagged_NavGame::IsValid() {
    return (m_ptr != nullptr);
}
GCMarkupVolumeWithRef GCMarkupVolumeTagged_NavGame::GetParent() const {
    GCMarkupVolumeWithRef value(m_ptr);
    return value;
}
void GCMarkupVolumeTagged_NavGame::SetParent(GCMarkupVolumeWithRef value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMarkupVolumeTagged_NavGame(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMarkupVolumeTagged_NavGame>("CMarkupVolumeTagged_NavGame")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FloodFillAttribute", &GCMarkupVolumeTagged_NavGame::GetFloodFillAttribute, &GCMarkupVolumeTagged_NavGame::SetFloodFillAttribute)
        .addProperty("Parent", &GCMarkupVolumeTagged_NavGame::GetParent, &GCMarkupVolumeTagged_NavGame::SetParent)
        .addFunction("ToPtr", &GCMarkupVolumeTagged_NavGame::ToPtr)
        .addFunction("IsValid", &GCMarkupVolumeTagged_NavGame::IsValid)
        .endClass();
}