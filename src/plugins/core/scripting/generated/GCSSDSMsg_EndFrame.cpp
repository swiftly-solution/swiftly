#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSSDSMsg_EndFrame::GCSSDSMsg_EndFrame(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSSDSMsg_EndFrame::GCSSDSMsg_EndFrame(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCSSDSEndFrameViewInfo> GCSSDSMsg_EndFrame::GetViews() const {
    CUtlVector<GCSSDSEndFrameViewInfo>* vec = GetSchemaValue<CUtlVector<GCSSDSEndFrameViewInfo>*>(m_ptr, "CSSDSMsg_EndFrame", "m_Views"); std::vector<GCSSDSEndFrameViewInfo> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSSDSMsg_EndFrame::SetViews(std::vector<GCSSDSEndFrameViewInfo> value) {
    SetSchemaValueCUtlVector<GCSSDSEndFrameViewInfo>(m_ptr, "CSSDSMsg_EndFrame", "m_Views", false, value);
}
std::string GCSSDSMsg_EndFrame::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSSDSMsg_EndFrame::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSSDSMsg_EndFrame(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_EndFrame>("CSSDSMsg_EndFrame")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Views", &GCSSDSMsg_EndFrame::GetViews, &GCSSDSMsg_EndFrame::SetViews)
        .addFunction("ToPtr", &GCSSDSMsg_EndFrame::ToPtr)
        .addFunction("IsValid", &GCSSDSMsg_EndFrame::IsValid)
        .endClass();
}