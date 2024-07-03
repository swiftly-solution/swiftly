#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParamSpanUpdater::GCParamSpanUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParamSpanUpdater::GCParamSpanUpdater(void *ptr) {
    m_ptr = ptr;
}
std::vector<GParamSpan_t> GCParamSpanUpdater::GetSpans() const {
    CUtlVector<GParamSpan_t>* vec = GetSchemaValue<CUtlVector<GParamSpan_t>*>(m_ptr, "CParamSpanUpdater", "m_spans"); std::vector<GParamSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCParamSpanUpdater::SetSpans(std::vector<GParamSpan_t> value) {
    SetSchemaValueCUtlVector<GParamSpan_t>(m_ptr, "CParamSpanUpdater", "m_spans", false, value);
}
std::string GCParamSpanUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParamSpanUpdater::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCParamSpanUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParamSpanUpdater>("CParamSpanUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Spans", &GCParamSpanUpdater::GetSpans, &GCParamSpanUpdater::SetSpans)
        .addFunction("ToPtr", &GCParamSpanUpdater::ToPtr)
        .addFunction("IsValid", &GCParamSpanUpdater::IsValid)
        .endClass();
}