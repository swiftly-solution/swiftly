#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCompositeMaterialAssemblyProcedure_t::GCompositeMaterialAssemblyProcedure_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCompositeMaterialAssemblyProcedure_t::GCompositeMaterialAssemblyProcedure_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCompositeMaterialMatchFilter_t> GCompositeMaterialAssemblyProcedure_t::GetMatchFilters() const {
    CUtlVector<GCompositeMaterialMatchFilter_t>* vec = GetSchemaValue<CUtlVector<GCompositeMaterialMatchFilter_t>*>(m_ptr, "CompositeMaterialAssemblyProcedure_t", "m_vecMatchFilters"); std::vector<GCompositeMaterialMatchFilter_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCompositeMaterialAssemblyProcedure_t::SetMatchFilters(std::vector<GCompositeMaterialMatchFilter_t> value) {
    SetSchemaValueCUtlVector<GCompositeMaterialMatchFilter_t>(m_ptr, "CompositeMaterialAssemblyProcedure_t", "m_vecMatchFilters", true, value);
}
std::vector<GCompositeMaterialInputContainer_t> GCompositeMaterialAssemblyProcedure_t::GetCompositeInputContainers() const {
    CUtlVector<GCompositeMaterialInputContainer_t>* vec = GetSchemaValue<CUtlVector<GCompositeMaterialInputContainer_t>*>(m_ptr, "CompositeMaterialAssemblyProcedure_t", "m_vecCompositeInputContainers"); std::vector<GCompositeMaterialInputContainer_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCompositeMaterialAssemblyProcedure_t::SetCompositeInputContainers(std::vector<GCompositeMaterialInputContainer_t> value) {
    SetSchemaValueCUtlVector<GCompositeMaterialInputContainer_t>(m_ptr, "CompositeMaterialAssemblyProcedure_t", "m_vecCompositeInputContainers", true, value);
}
std::vector<GCompMatPropertyMutator_t> GCompositeMaterialAssemblyProcedure_t::GetPropertyMutators() const {
    CUtlVector<GCompMatPropertyMutator_t>* vec = GetSchemaValue<CUtlVector<GCompMatPropertyMutator_t>*>(m_ptr, "CompositeMaterialAssemblyProcedure_t", "m_vecPropertyMutators"); std::vector<GCompMatPropertyMutator_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCompositeMaterialAssemblyProcedure_t::SetPropertyMutators(std::vector<GCompMatPropertyMutator_t> value) {
    SetSchemaValueCUtlVector<GCompMatPropertyMutator_t>(m_ptr, "CompositeMaterialAssemblyProcedure_t", "m_vecPropertyMutators", true, value);
}
std::string GCompositeMaterialAssemblyProcedure_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCompositeMaterialAssemblyProcedure_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCompositeMaterialAssemblyProcedure_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompositeMaterialAssemblyProcedure_t>("CompositeMaterialAssemblyProcedure_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MatchFilters", &GCompositeMaterialAssemblyProcedure_t::GetMatchFilters, &GCompositeMaterialAssemblyProcedure_t::SetMatchFilters)
        .addProperty("CompositeInputContainers", &GCompositeMaterialAssemblyProcedure_t::GetCompositeInputContainers, &GCompositeMaterialAssemblyProcedure_t::SetCompositeInputContainers)
        .addProperty("PropertyMutators", &GCompositeMaterialAssemblyProcedure_t::GetPropertyMutators, &GCompositeMaterialAssemblyProcedure_t::SetPropertyMutators)
        .addFunction("ToPtr", &GCompositeMaterialAssemblyProcedure_t::ToPtr)
        .addFunction("IsValid", &GCompositeMaterialAssemblyProcedure_t::IsValid)
        .endClass();
}