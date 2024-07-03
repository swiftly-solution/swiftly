#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimParameterManagerUpdater::GCAnimParameterManagerUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimParameterManagerUpdater::GCAnimParameterManagerUpdater(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCAnimParamHandle> GCAnimParameterManagerUpdater::GetIndexToHandle() const {
    CUtlVector<GCAnimParamHandle>* vec = GetSchemaValue<CUtlVector<GCAnimParamHandle>*>(m_ptr, "CAnimParameterManagerUpdater", "m_indexToHandle"); std::vector<GCAnimParamHandle> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimParameterManagerUpdater::SetIndexToHandle(std::vector<GCAnimParamHandle> value) {
    SetSchemaValueCUtlVector<GCAnimParamHandle>(m_ptr, "CAnimParameterManagerUpdater", "m_indexToHandle", false, value);
}
std::string GCAnimParameterManagerUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimParameterManagerUpdater::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimParameterManagerUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimParameterManagerUpdater>("CAnimParameterManagerUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("IndexToHandle", &GCAnimParameterManagerUpdater::GetIndexToHandle, &GCAnimParameterManagerUpdater::SetIndexToHandle)
        .addFunction("ToPtr", &GCAnimParameterManagerUpdater::ToPtr)
        .addFunction("IsValid", &GCAnimParameterManagerUpdater::IsValid)
        .endClass();
}