#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavLinkMovementVData::GCNavLinkMovementVData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavLinkMovementVData::GCNavLinkMovementVData(void *ptr) {
    m_ptr = ptr;
}
bool GCNavLinkMovementVData::GetIsInterpolated() const {
    return GetSchemaValue<bool>(m_ptr, "CNavLinkMovementVData", "m_bIsInterpolated");
}
void GCNavLinkMovementVData::SetIsInterpolated(bool value) {
    SetSchemaValue(m_ptr, "CNavLinkMovementVData", "m_bIsInterpolated", false, value);
}
uint32_t GCNavLinkMovementVData::GetRecommendedDistance() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CNavLinkMovementVData", "m_unRecommendedDistance");
}
void GCNavLinkMovementVData::SetRecommendedDistance(uint32_t value) {
    SetSchemaValue(m_ptr, "CNavLinkMovementVData", "m_unRecommendedDistance", false, value);
}
std::vector<GCNavLinkAnimgraphVar> GCNavLinkMovementVData::GetAnimgraphVars() const {
    CUtlVector<GCNavLinkAnimgraphVar>* vec = GetSchemaValue<CUtlVector<GCNavLinkAnimgraphVar>*>(m_ptr, "CNavLinkMovementVData", "m_vecAnimgraphVars"); std::vector<GCNavLinkAnimgraphVar> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCNavLinkMovementVData::SetAnimgraphVars(std::vector<GCNavLinkAnimgraphVar> value) {
    SetSchemaValueCUtlVector<GCNavLinkAnimgraphVar>(m_ptr, "CNavLinkMovementVData", "m_vecAnimgraphVars", false, value);
}
std::string GCNavLinkMovementVData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavLinkMovementVData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNavLinkMovementVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavLinkMovementVData>("CNavLinkMovementVData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("IsInterpolated", &GCNavLinkMovementVData::GetIsInterpolated, &GCNavLinkMovementVData::SetIsInterpolated)
        .addProperty("RecommendedDistance", &GCNavLinkMovementVData::GetRecommendedDistance, &GCNavLinkMovementVData::SetRecommendedDistance)
        .addProperty("AnimgraphVars", &GCNavLinkMovementVData::GetAnimgraphVars, &GCNavLinkMovementVData::SetAnimgraphVars)
        .addFunction("ToPtr", &GCNavLinkMovementVData::ToPtr)
        .addFunction("IsValid", &GCNavLinkMovementVData::IsValid)
        .endClass();
}