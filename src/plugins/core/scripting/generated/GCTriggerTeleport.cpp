#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerTeleport::GCTriggerTeleport(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerTeleport::GCTriggerTeleport(void *ptr) {
    m_ptr = ptr;
}
std::string GCTriggerTeleport::GetLandmark() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerTeleport", "m_iLandmark").String();
}
void GCTriggerTeleport::SetLandmark(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerTeleport", "m_iLandmark", false, CUtlSymbolLarge(value.c_str()));
}
bool GCTriggerTeleport::GetUseLandmarkAngles() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerTeleport", "m_bUseLandmarkAngles");
}
void GCTriggerTeleport::SetUseLandmarkAngles(bool value) {
    SetSchemaValue(m_ptr, "CTriggerTeleport", "m_bUseLandmarkAngles", false, value);
}
bool GCTriggerTeleport::GetMirrorPlayer() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerTeleport", "m_bMirrorPlayer");
}
void GCTriggerTeleport::SetMirrorPlayer(bool value) {
    SetSchemaValue(m_ptr, "CTriggerTeleport", "m_bMirrorPlayer", false, value);
}
std::string GCTriggerTeleport::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerTeleport::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerTeleport::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerTeleport::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerTeleport(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerTeleport>("CTriggerTeleport")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Landmark", &GCTriggerTeleport::GetLandmark, &GCTriggerTeleport::SetLandmark)
        .addProperty("UseLandmarkAngles", &GCTriggerTeleport::GetUseLandmarkAngles, &GCTriggerTeleport::SetUseLandmarkAngles)
        .addProperty("MirrorPlayer", &GCTriggerTeleport::GetMirrorPlayer, &GCTriggerTeleport::SetMirrorPlayer)
        .addProperty("Parent", &GCTriggerTeleport::GetParent, &GCTriggerTeleport::SetParent)
        .addFunction("ToPtr", &GCTriggerTeleport::ToPtr)
        .addFunction("IsValid", &GCTriggerTeleport::IsValid)
        .endClass();
}