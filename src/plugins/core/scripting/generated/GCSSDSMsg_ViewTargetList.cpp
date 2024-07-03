#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSSDSMsg_ViewTargetList::GCSSDSMsg_ViewTargetList(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSSDSMsg_ViewTargetList::GCSSDSMsg_ViewTargetList(void *ptr) {
    m_ptr = ptr;
}
GSceneViewId_t GCSSDSMsg_ViewTargetList::GetViewId() const {
    GSceneViewId_t value(GetSchemaPtr(m_ptr, "CSSDSMsg_ViewTargetList", "m_viewId"));
    return value;
}
void GCSSDSMsg_ViewTargetList::SetViewId(GSceneViewId_t value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewTargetList", "m_viewId", false, value);
}
std::string GCSSDSMsg_ViewTargetList::GetViewName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSSDSMsg_ViewTargetList", "m_ViewName").Get();
}
void GCSSDSMsg_ViewTargetList::SetViewName(std::string value) {
    SetSchemaValue(m_ptr, "CSSDSMsg_ViewTargetList", "m_ViewName", false, CUtlString(value.c_str()));
}
std::vector<GCSSDSMsg_ViewTarget> GCSSDSMsg_ViewTargetList::GetTargets() const {
    CUtlVector<GCSSDSMsg_ViewTarget>* vec = GetSchemaValue<CUtlVector<GCSSDSMsg_ViewTarget>*>(m_ptr, "CSSDSMsg_ViewTargetList", "m_Targets"); std::vector<GCSSDSMsg_ViewTarget> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSSDSMsg_ViewTargetList::SetTargets(std::vector<GCSSDSMsg_ViewTarget> value) {
    SetSchemaValueCUtlVector<GCSSDSMsg_ViewTarget>(m_ptr, "CSSDSMsg_ViewTargetList", "m_Targets", false, value);
}
std::string GCSSDSMsg_ViewTargetList::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSSDSMsg_ViewTargetList::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSSDSMsg_ViewTargetList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_ViewTargetList>("CSSDSMsg_ViewTargetList")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ViewId", &GCSSDSMsg_ViewTargetList::GetViewId, &GCSSDSMsg_ViewTargetList::SetViewId)
        .addProperty("ViewName", &GCSSDSMsg_ViewTargetList::GetViewName, &GCSSDSMsg_ViewTargetList::SetViewName)
        .addProperty("Targets", &GCSSDSMsg_ViewTargetList::GetTargets, &GCSSDSMsg_ViewTargetList::SetTargets)
        .addFunction("ToPtr", &GCSSDSMsg_ViewTargetList::ToPtr)
        .addFunction("IsValid", &GCSSDSMsg_ViewTargetList::IsValid)
        .endClass();
}