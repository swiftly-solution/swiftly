#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFists::GCFists(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFists::GCFists(void *ptr) {
    m_ptr = ptr;
}
bool GCFists::GetPlayingUninterruptableAct() const {
    return GetSchemaValue<bool>(m_ptr, "CFists", "m_bPlayingUninterruptableAct");
}
void GCFists::SetPlayingUninterruptableAct(bool value) {
    SetSchemaValue(m_ptr, "CFists", "m_bPlayingUninterruptableAct", false, value);
}
uint64_t GCFists::GetUninterruptableActivity() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFists", "m_nUninterruptableActivity");
}
void GCFists::SetUninterruptableActivity(uint64_t value) {
    SetSchemaValue(m_ptr, "CFists", "m_nUninterruptableActivity", false, value);
}
bool GCFists::GetRestorePrevWep() const {
    return GetSchemaValue<bool>(m_ptr, "CFists", "m_bRestorePrevWep");
}
void GCFists::SetRestorePrevWep(bool value) {
    SetSchemaValue(m_ptr, "CFists", "m_bRestorePrevWep", false, value);
}
GCBasePlayerWeapon GCFists::GetWeaponBeforePrevious() const {
    GCBasePlayerWeapon value(*GetSchemaValuePtr<void*>(m_ptr, "CFists", "m_hWeaponBeforePrevious"));
    return value;
}
void GCFists::SetWeaponBeforePrevious(GCBasePlayerWeapon* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'WeaponBeforePrevious' is not possible.\n");
}
GCBasePlayerWeapon GCFists::GetWeaponPrevious() const {
    GCBasePlayerWeapon value(*GetSchemaValuePtr<void*>(m_ptr, "CFists", "m_hWeaponPrevious"));
    return value;
}
void GCFists::SetWeaponPrevious(GCBasePlayerWeapon* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'WeaponPrevious' is not possible.\n");
}
bool GCFists::GetDelayedHardPunchIncoming() const {
    return GetSchemaValue<bool>(m_ptr, "CFists", "m_bDelayedHardPunchIncoming");
}
void GCFists::SetDelayedHardPunchIncoming(bool value) {
    SetSchemaValue(m_ptr, "CFists", "m_bDelayedHardPunchIncoming", false, value);
}
bool GCFists::GetDestroyAfterTaunt() const {
    return GetSchemaValue<bool>(m_ptr, "CFists", "m_bDestroyAfterTaunt");
}
void GCFists::SetDestroyAfterTaunt(bool value) {
    SetSchemaValue(m_ptr, "CFists", "m_bDestroyAfterTaunt", false, value);
}
std::string GCFists::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFists::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBase GCFists::GetParent() const {
    GCCSWeaponBase value(m_ptr);
    return value;
}
void GCFists::SetParent(GCCSWeaponBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFists(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFists>("CFists")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PlayingUninterruptableAct", &GCFists::GetPlayingUninterruptableAct, &GCFists::SetPlayingUninterruptableAct)
        .addProperty("UninterruptableActivity", &GCFists::GetUninterruptableActivity, &GCFists::SetUninterruptableActivity)
        .addProperty("RestorePrevWep", &GCFists::GetRestorePrevWep, &GCFists::SetRestorePrevWep)
        .addProperty("WeaponBeforePrevious", &GCFists::GetWeaponBeforePrevious, &GCFists::SetWeaponBeforePrevious)
        .addProperty("WeaponPrevious", &GCFists::GetWeaponPrevious, &GCFists::SetWeaponPrevious)
        .addProperty("DelayedHardPunchIncoming", &GCFists::GetDelayedHardPunchIncoming, &GCFists::SetDelayedHardPunchIncoming)
        .addProperty("DestroyAfterTaunt", &GCFists::GetDestroyAfterTaunt, &GCFists::SetDestroyAfterTaunt)
        .addProperty("Parent", &GCFists::GetParent, &GCFists::SetParent)
        .addFunction("ToPtr", &GCFists::ToPtr)
        .addFunction("IsValid", &GCFists::IsValid)
        .endClass();
}