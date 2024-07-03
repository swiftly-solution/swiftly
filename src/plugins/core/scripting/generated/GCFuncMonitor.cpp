#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncMonitor::GCFuncMonitor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncMonitor::GCFuncMonitor(void *ptr) {
    m_ptr = ptr;
}
std::string GCFuncMonitor::GetTargetCamera() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFuncMonitor", "m_targetCamera").Get();
}
void GCFuncMonitor::SetTargetCamera(std::string value) {
    SetSchemaValue(m_ptr, "CFuncMonitor", "m_targetCamera", false, CUtlString(value.c_str()));
}
int32_t GCFuncMonitor::GetResolutionEnum() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFuncMonitor", "m_nResolutionEnum");
}
void GCFuncMonitor::SetResolutionEnum(int32_t value) {
    SetSchemaValue(m_ptr, "CFuncMonitor", "m_nResolutionEnum", false, value);
}
bool GCFuncMonitor::GetRenderShadows() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncMonitor", "m_bRenderShadows");
}
void GCFuncMonitor::SetRenderShadows(bool value) {
    SetSchemaValue(m_ptr, "CFuncMonitor", "m_bRenderShadows", false, value);
}
bool GCFuncMonitor::GetUseUniqueColorTarget() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncMonitor", "m_bUseUniqueColorTarget");
}
void GCFuncMonitor::SetUseUniqueColorTarget(bool value) {
    SetSchemaValue(m_ptr, "CFuncMonitor", "m_bUseUniqueColorTarget", false, value);
}
std::string GCFuncMonitor::GetBrushModelName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFuncMonitor", "m_brushModelName").Get();
}
void GCFuncMonitor::SetBrushModelName(std::string value) {
    SetSchemaValue(m_ptr, "CFuncMonitor", "m_brushModelName", false, CUtlString(value.c_str()));
}
GCBaseEntity GCFuncMonitor::GetTargetCamera1() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CFuncMonitor", "m_hTargetCamera"));
    return value;
}
void GCFuncMonitor::SetTargetCamera1(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetCamera1' is not possible.\n");
}
bool GCFuncMonitor::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncMonitor", "m_bEnabled");
}
void GCFuncMonitor::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CFuncMonitor", "m_bEnabled", false, value);
}
bool GCFuncMonitor::GetDraw3DSkybox() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncMonitor", "m_bDraw3DSkybox");
}
void GCFuncMonitor::SetDraw3DSkybox(bool value) {
    SetSchemaValue(m_ptr, "CFuncMonitor", "m_bDraw3DSkybox", false, value);
}
bool GCFuncMonitor::GetStartEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CFuncMonitor", "m_bStartEnabled");
}
void GCFuncMonitor::SetStartEnabled(bool value) {
    SetSchemaValue(m_ptr, "CFuncMonitor", "m_bStartEnabled", false, value);
}
std::string GCFuncMonitor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncMonitor::IsValid() {
    return (m_ptr != nullptr);
}
GCFuncBrush GCFuncMonitor::GetParent() const {
    GCFuncBrush value(m_ptr);
    return value;
}
void GCFuncMonitor::SetParent(GCFuncBrush value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncMonitor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncMonitor>("CFuncMonitor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TargetCamera", &GCFuncMonitor::GetTargetCamera, &GCFuncMonitor::SetTargetCamera)
        .addProperty("ResolutionEnum", &GCFuncMonitor::GetResolutionEnum, &GCFuncMonitor::SetResolutionEnum)
        .addProperty("RenderShadows", &GCFuncMonitor::GetRenderShadows, &GCFuncMonitor::SetRenderShadows)
        .addProperty("UseUniqueColorTarget", &GCFuncMonitor::GetUseUniqueColorTarget, &GCFuncMonitor::SetUseUniqueColorTarget)
        .addProperty("BrushModelName", &GCFuncMonitor::GetBrushModelName, &GCFuncMonitor::SetBrushModelName)
        .addProperty("TargetCamera1", &GCFuncMonitor::GetTargetCamera1, &GCFuncMonitor::SetTargetCamera1)
        .addProperty("Enabled", &GCFuncMonitor::GetEnabled, &GCFuncMonitor::SetEnabled)
        .addProperty("Draw3DSkybox", &GCFuncMonitor::GetDraw3DSkybox, &GCFuncMonitor::SetDraw3DSkybox)
        .addProperty("StartEnabled", &GCFuncMonitor::GetStartEnabled, &GCFuncMonitor::SetStartEnabled)
        .addProperty("Parent", &GCFuncMonitor::GetParent, &GCFuncMonitor::SetParent)
        .addFunction("ToPtr", &GCFuncMonitor::ToPtr)
        .addFunction("IsValid", &GCFuncMonitor::IsValid)
        .endClass();
}