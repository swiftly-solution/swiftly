#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTakeDamageSummaryScopeGuard::GCTakeDamageSummaryScopeGuard(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTakeDamageSummaryScopeGuard::GCTakeDamageSummaryScopeGuard(void *ptr) {
    m_ptr = ptr;
}
std::vector<GSummaryTakeDamageInfo_t*> GCTakeDamageSummaryScopeGuard::GetSummaries() const {
    CUtlVector<GSummaryTakeDamageInfo_t*>* vec = GetSchemaValue<CUtlVector<GSummaryTakeDamageInfo_t*>*>(m_ptr, "CTakeDamageSummaryScopeGuard", "m_vecSummaries"); std::vector<GSummaryTakeDamageInfo_t*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCTakeDamageSummaryScopeGuard::SetSummaries(std::vector<GSummaryTakeDamageInfo_t*> value) {
    SetSchemaValueCUtlVector<GSummaryTakeDamageInfo_t*>(m_ptr, "CTakeDamageSummaryScopeGuard", "m_vecSummaries", false, value);
}
std::string GCTakeDamageSummaryScopeGuard::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTakeDamageSummaryScopeGuard::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCTakeDamageSummaryScopeGuard(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTakeDamageSummaryScopeGuard>("CTakeDamageSummaryScopeGuard")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Summaries", &GCTakeDamageSummaryScopeGuard::GetSummaries, &GCTakeDamageSummaryScopeGuard::SetSummaries)
        .addFunction("ToPtr", &GCTakeDamageSummaryScopeGuard::ToPtr)
        .addFunction("IsValid", &GCTakeDamageSummaryScopeGuard::IsValid)
        .endClass();
}