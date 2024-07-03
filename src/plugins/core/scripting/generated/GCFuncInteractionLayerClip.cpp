#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncInteractionLayerClip::GCFuncInteractionLayerClip(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncInteractionLayerClip::GCFuncInteractionLayerClip(void *ptr) {
    m_ptr = ptr;
}
bool GCFuncInteractionLayerClip::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncInteractionLayerClip", "m_bDisabled");
}
void GCFuncInteractionLayerClip::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CFuncInteractionLayerClip", "m_bDisabled", false, value);
}
std::string GCFuncInteractionLayerClip::GetInteractsAs() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncInteractionLayerClip", "m_iszInteractsAs").String();
}
void GCFuncInteractionLayerClip::SetInteractsAs(std::string value) {
    SetSchemaValue(m_ptr, "CFuncInteractionLayerClip", "m_iszInteractsAs", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncInteractionLayerClip::GetInteractsWith() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncInteractionLayerClip", "m_iszInteractsWith").String();
}
void GCFuncInteractionLayerClip::SetInteractsWith(std::string value) {
    SetSchemaValue(m_ptr, "CFuncInteractionLayerClip", "m_iszInteractsWith", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncInteractionLayerClip::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncInteractionLayerClip::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncInteractionLayerClip::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncInteractionLayerClip::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncInteractionLayerClip(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncInteractionLayerClip>("CFuncInteractionLayerClip")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCFuncInteractionLayerClip::GetDisabled, &GCFuncInteractionLayerClip::SetDisabled)
        .addProperty("InteractsAs", &GCFuncInteractionLayerClip::GetInteractsAs, &GCFuncInteractionLayerClip::SetInteractsAs)
        .addProperty("InteractsWith", &GCFuncInteractionLayerClip::GetInteractsWith, &GCFuncInteractionLayerClip::SetInteractsWith)
        .addProperty("Parent", &GCFuncInteractionLayerClip::GetParent, &GCFuncInteractionLayerClip::SetParent)
        .addFunction("ToPtr", &GCFuncInteractionLayerClip::ToPtr)
        .addFunction("IsValid", &GCFuncInteractionLayerClip::IsValid)
        .endClass();
}