#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSSDSMsg_LayerBase::GCSSDSMsg_LayerBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSSDSMsg_LayerBase::GCSSDSMsg_LayerBase(void *ptr) {
    m_ptr = ptr;
}
GSceneViewId_t GCSSDSMsg_LayerBase::GetViewId() const {
    GSceneViewId_t value(GetSchemaPtr(m_ptr, "CSSDSMsg_LayerBase", "m_viewId"));
    return value;
}
void GCSSDSMsg_LayerBase::SetViewId(GSceneViewId_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_LayerBase", "m_viewId", false, value);
}
std::string GCSSDSMsg_LayerBase::GetViewName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSSDSMsg_LayerBase", "m_ViewName").Get();
}
void GCSSDSMsg_LayerBase::SetViewName(std::string value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_LayerBase", "m_ViewName", false, CUtlString(value.c_str()));
}
int32_t GCSSDSMsg_LayerBase::GetLayerIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_LayerBase", "m_nLayerIndex");
}
void GCSSDSMsg_LayerBase::SetLayerIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_LayerBase", "m_nLayerIndex", false, value);
}
uint64_t GCSSDSMsg_LayerBase::GetLayerId() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CSSDSMsg_LayerBase", "m_nLayerId");
}
void GCSSDSMsg_LayerBase::SetLayerId(uint64_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_LayerBase", "m_nLayerId", false, value);
}
std::string GCSSDSMsg_LayerBase::GetLayerName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSSDSMsg_LayerBase", "m_LayerName").Get();
}
void GCSSDSMsg_LayerBase::SetLayerName(std::string value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_LayerBase", "m_LayerName", false, CUtlString(value.c_str()));
}
std::string GCSSDSMsg_LayerBase::GetDisplayText() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSSDSMsg_LayerBase", "m_displayText").Get();
}
void GCSSDSMsg_LayerBase::SetDisplayText(std::string value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_LayerBase", "m_displayText", false, CUtlString(value.c_str()));
}
std::string GCSSDSMsg_LayerBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSSDSMsg_LayerBase::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSSDSMsg_LayerBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_LayerBase>("CSSDSMsg_LayerBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ViewId", &GCSSDSMsg_LayerBase::GetViewId, &GCSSDSMsg_LayerBase::SetViewId)
        .addProperty("ViewName", &GCSSDSMsg_LayerBase::GetViewName, &GCSSDSMsg_LayerBase::SetViewName)
        .addProperty("LayerIndex", &GCSSDSMsg_LayerBase::GetLayerIndex, &GCSSDSMsg_LayerBase::SetLayerIndex)
        .addProperty("LayerId", &GCSSDSMsg_LayerBase::GetLayerId, &GCSSDSMsg_LayerBase::SetLayerId)
        .addProperty("LayerName", &GCSSDSMsg_LayerBase::GetLayerName, &GCSSDSMsg_LayerBase::SetLayerName)
        .addProperty("DisplayText", &GCSSDSMsg_LayerBase::GetDisplayText, &GCSSDSMsg_LayerBase::SetDisplayText)
        .addFunction("ToPtr", &GCSSDSMsg_LayerBase::ToPtr)
        .addFunction("IsValid", &GCSSDSMsg_LayerBase::IsValid)
        .endClass();
}