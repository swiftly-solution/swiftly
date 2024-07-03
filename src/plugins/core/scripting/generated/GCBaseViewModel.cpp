#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseViewModel::GCBaseViewModel(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseViewModel::GCBaseViewModel(void *ptr) {
    m_ptr = ptr;
}
Vector GCBaseViewModel::GetLastFacing() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseViewModel", "m_vecLastFacing");
}
void GCBaseViewModel::SetLastFacing(Vector value) {
    SetSchemaValue(m_ptr, "CBaseViewModel", "m_vecLastFacing", false, value);
}
uint32_t GCBaseViewModel::GetViewModelIndex() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBaseViewModel", "m_nViewModelIndex");
}
void GCBaseViewModel::SetViewModelIndex(uint32_t value) {
    SetSchemaValue(m_ptr, "CBaseViewModel", "m_nViewModelIndex", false, value);
}
uint32_t GCBaseViewModel::GetAnimationParity() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBaseViewModel", "m_nAnimationParity");
}
void GCBaseViewModel::SetAnimationParity(uint32_t value) {
    SetSchemaValue(m_ptr, "CBaseViewModel", "m_nAnimationParity", false, value);
}
float GCBaseViewModel::GetAnimationStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseViewModel", "m_flAnimationStartTime");
}
void GCBaseViewModel::SetAnimationStartTime(float value) {
    SetSchemaValue(m_ptr, "CBaseViewModel", "m_flAnimationStartTime", false, value);
}
GCBasePlayerWeapon GCBaseViewModel::GetWeapon() const {
    GCBasePlayerWeapon value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseViewModel", "m_hWeapon"));
    return value;
}
void GCBaseViewModel::SetWeapon(GCBasePlayerWeapon* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Weapon' is not possible.\n");
}
std::string GCBaseViewModel::GetVMName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseViewModel", "m_sVMName").String();
}
void GCBaseViewModel::SetVMName(std::string value) {
    SetSchemaValue(m_ptr, "CBaseViewModel", "m_sVMName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseViewModel::GetAnimationPrefix() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseViewModel", "m_sAnimationPrefix").String();
}
void GCBaseViewModel::SetAnimationPrefix(std::string value) {
    SetSchemaValue(m_ptr, "CBaseViewModel", "m_sAnimationPrefix", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCBaseViewModel::GetOldLayer() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseViewModel", "m_oldLayer");
}
void GCBaseViewModel::SetOldLayer(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseViewModel", "m_oldLayer", false, value);
}
float GCBaseViewModel::GetOldLayerStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseViewModel", "m_oldLayerStartTime");
}
void GCBaseViewModel::SetOldLayerStartTime(float value) {
    SetSchemaValue(m_ptr, "CBaseViewModel", "m_oldLayerStartTime", false, value);
}
GCBaseEntity GCBaseViewModel::GetControlPanel() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseViewModel", "m_hControlPanel"));
    return value;
}
void GCBaseViewModel::SetControlPanel(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ControlPanel' is not possible.\n");
}
std::string GCBaseViewModel::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseViewModel::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseAnimGraph GCBaseViewModel::GetParent() const {
    GCBaseAnimGraph value(m_ptr);
    return value;
}
void GCBaseViewModel::SetParent(GCBaseAnimGraph value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseViewModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseViewModel>("CBaseViewModel")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LastFacing", &GCBaseViewModel::GetLastFacing, &GCBaseViewModel::SetLastFacing)
        .addProperty("ViewModelIndex", &GCBaseViewModel::GetViewModelIndex, &GCBaseViewModel::SetViewModelIndex)
        .addProperty("AnimationParity", &GCBaseViewModel::GetAnimationParity, &GCBaseViewModel::SetAnimationParity)
        .addProperty("AnimationStartTime", &GCBaseViewModel::GetAnimationStartTime, &GCBaseViewModel::SetAnimationStartTime)
        .addProperty("Weapon", &GCBaseViewModel::GetWeapon, &GCBaseViewModel::SetWeapon)
        .addProperty("VMName", &GCBaseViewModel::GetVMName, &GCBaseViewModel::SetVMName)
        .addProperty("AnimationPrefix", &GCBaseViewModel::GetAnimationPrefix, &GCBaseViewModel::SetAnimationPrefix)
        .addProperty("OldLayer", &GCBaseViewModel::GetOldLayer, &GCBaseViewModel::SetOldLayer)
        .addProperty("OldLayerStartTime", &GCBaseViewModel::GetOldLayerStartTime, &GCBaseViewModel::SetOldLayerStartTime)
        .addProperty("ControlPanel", &GCBaseViewModel::GetControlPanel, &GCBaseViewModel::SetControlPanel)
        .addProperty("Parent", &GCBaseViewModel::GetParent, &GCBaseViewModel::SetParent)
        .addFunction("ToPtr", &GCBaseViewModel::ToPtr)
        .addFunction("IsValid", &GCBaseViewModel::IsValid)
        .endClass();
}