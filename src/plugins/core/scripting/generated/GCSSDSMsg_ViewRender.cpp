#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSSDSMsg_ViewRender::GCSSDSMsg_ViewRender(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSSDSMsg_ViewRender::GCSSDSMsg_ViewRender(void *ptr) {
    m_ptr = ptr;
}
GSceneViewId_t GCSSDSMsg_ViewRender::GetViewId() const {
    GSceneViewId_t value(GetSchemaPtr(m_ptr, "CSSDSMsg_ViewRender", "m_viewId"));
    return value;
}
void GCSSDSMsg_ViewRender::SetViewId(GSceneViewId_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewRender", "m_viewId", false, value);
}
std::string GCSSDSMsg_ViewRender::GetViewName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSSDSMsg_ViewRender", "m_ViewName").Get();
}
void GCSSDSMsg_ViewRender::SetViewName(std::string value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewRender", "m_ViewName", false, CUtlString(value.c_str()));
}
std::string GCSSDSMsg_ViewRender::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSSDSMsg_ViewRender::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSSDSMsg_ViewRender(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_ViewRender>("CSSDSMsg_ViewRender")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ViewId", &GCSSDSMsg_ViewRender::GetViewId, &GCSSDSMsg_ViewRender::SetViewId)
        .addProperty("ViewName", &GCSSDSMsg_ViewRender::GetViewName, &GCSSDSMsg_ViewRender::SetViewName)
        .addFunction("ToPtr", &GCSSDSMsg_ViewRender::ToPtr)
        .addFunction("IsValid", &GCSSDSMsg_ViewRender::IsValid)
        .endClass();
}