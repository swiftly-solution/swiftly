#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncBrush::GCFuncBrush(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncBrush::GCFuncBrush(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCFuncBrush::GetSolidity() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFuncBrush", "m_iSolidity");
}
void GCFuncBrush::SetSolidity(uint64_t value) {
    SetSchemaValue(m_ptr, "CFuncBrush", "m_iSolidity", false, value);
}
int32_t GCFuncBrush::GetDisabled() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFuncBrush", "m_iDisabled");
}
void GCFuncBrush::SetDisabled(int32_t value) {
    SetSchemaValue(m_ptr, "CFuncBrush", "m_iDisabled", false, value);
}
bool GCFuncBrush::GetSolidBsp() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncBrush", "m_bSolidBsp");
}
void GCFuncBrush::SetSolidBsp(bool value) {
    SetSchemaValue(m_ptr, "CFuncBrush", "m_bSolidBsp", false, value);
}
std::string GCFuncBrush::GetExcludedClass() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncBrush", "m_iszExcludedClass").String();
}
void GCFuncBrush::SetExcludedClass(std::string value) {
    SetSchemaValue(m_ptr, "CFuncBrush", "m_iszExcludedClass", false, CUtlSymbolLarge(value.c_str()));
}
bool GCFuncBrush::GetInvertExclusion() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncBrush", "m_bInvertExclusion");
}
void GCFuncBrush::SetInvertExclusion(bool value) {
    SetSchemaValue(m_ptr, "CFuncBrush", "m_bInvertExclusion", false, value);
}
bool GCFuncBrush::GetScriptedMovement() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncBrush", "m_bScriptedMovement");
}
void GCFuncBrush::SetScriptedMovement(bool value) {
    SetSchemaValue(m_ptr, "CFuncBrush", "m_bScriptedMovement", false, value);
}
std::string GCFuncBrush::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncBrush::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCFuncBrush::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCFuncBrush::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncBrush(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncBrush>("CFuncBrush")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Solidity", &GCFuncBrush::GetSolidity, &GCFuncBrush::SetSolidity)
        .addProperty("Disabled", &GCFuncBrush::GetDisabled, &GCFuncBrush::SetDisabled)
        .addProperty("SolidBsp", &GCFuncBrush::GetSolidBsp, &GCFuncBrush::SetSolidBsp)
        .addProperty("ExcludedClass", &GCFuncBrush::GetExcludedClass, &GCFuncBrush::SetExcludedClass)
        .addProperty("InvertExclusion", &GCFuncBrush::GetInvertExclusion, &GCFuncBrush::SetInvertExclusion)
        .addProperty("ScriptedMovement", &GCFuncBrush::GetScriptedMovement, &GCFuncBrush::SetScriptedMovement)
        .addProperty("Parent", &GCFuncBrush::GetParent, &GCFuncBrush::SetParent)
        .addFunction("ToPtr", &GCFuncBrush::ToPtr)
        .addFunction("IsValid", &GCFuncBrush::IsValid)
        .endClass();
}