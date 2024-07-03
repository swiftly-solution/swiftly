#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSSDSEndFrameViewInfo::GCSSDSEndFrameViewInfo(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSSDSEndFrameViewInfo::GCSSDSEndFrameViewInfo(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCSSDSEndFrameViewInfo::GetViewId() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CSSDSEndFrameViewInfo", "m_nViewId");
}
void GCSSDSEndFrameViewInfo::SetViewId(uint64_t value) {
    SetSchemaValue(m_ptr, "CSSDSEndFrameViewInfo", "m_nViewId", false, value);
}
std::string GCSSDSEndFrameViewInfo::GetViewName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSSDSEndFrameViewInfo", "m_ViewName").Get();
}
void GCSSDSEndFrameViewInfo::SetViewName(std::string value) {
    SetSchemaValue(m_ptr, "CSSDSEndFrameViewInfo", "m_ViewName", false, CUtlString(value.c_str()));
}
std::string GCSSDSEndFrameViewInfo::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSSDSEndFrameViewInfo::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSSDSEndFrameViewInfo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSEndFrameViewInfo>("CSSDSEndFrameViewInfo")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ViewId", &GCSSDSEndFrameViewInfo::GetViewId, &GCSSDSEndFrameViewInfo::SetViewId)
        .addProperty("ViewName", &GCSSDSEndFrameViewInfo::GetViewName, &GCSSDSEndFrameViewInfo::SetViewName)
        .addFunction("ToPtr", &GCSSDSEndFrameViewInfo::ToPtr)
        .addFunction("IsValid", &GCSSDSEndFrameViewInfo::IsValid)
        .endClass();
}