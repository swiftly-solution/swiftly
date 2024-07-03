#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCompositeMaterialEditorPoint_t::GCompositeMaterialEditorPoint_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCompositeMaterialEditorPoint_t::GCompositeMaterialEditorPoint_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GCompositeMaterialEditorPoint_t::GetSequenceIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CompositeMaterialEditorPoint_t", "m_nSequenceIndex");
}
void GCompositeMaterialEditorPoint_t::SetSequenceIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CompositeMaterialEditorPoint_t", "m_nSequenceIndex", true, value);
}
float GCompositeMaterialEditorPoint_t::GetCycle() const {
    return GetSchemaValue<float>(m_ptr, "CompositeMaterialEditorPoint_t", "m_flCycle");
}
void GCompositeMaterialEditorPoint_t::SetCycle(float value) {
    SetSchemaValue(m_ptr, "CompositeMaterialEditorPoint_t", "m_flCycle", true, value);
}
bool GCompositeMaterialEditorPoint_t::GetEnableChildModel() const {
    return GetSchemaValue<bool>(m_ptr, "CompositeMaterialEditorPoint_t", "m_bEnableChildModel");
}
void GCompositeMaterialEditorPoint_t::SetEnableChildModel(bool value) {
    SetSchemaValue(m_ptr, "CompositeMaterialEditorPoint_t", "m_bEnableChildModel", true, value);
}
std::vector<GCompositeMaterialAssemblyProcedure_t> GCompositeMaterialEditorPoint_t::GetCompositeMaterialAssemblyProcedures() const {
    CUtlVector<GCompositeMaterialAssemblyProcedure_t>* vec = GetSchemaValue<CUtlVector<GCompositeMaterialAssemblyProcedure_t>*>(m_ptr, "CompositeMaterialEditorPoint_t", "m_vecCompositeMaterialAssemblyProcedures"); std::vector<GCompositeMaterialAssemblyProcedure_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCompositeMaterialEditorPoint_t::SetCompositeMaterialAssemblyProcedures(std::vector<GCompositeMaterialAssemblyProcedure_t> value) {
    SetSchemaValueCUtlVector<GCompositeMaterialAssemblyProcedure_t>(m_ptr, "CompositeMaterialEditorPoint_t", "m_vecCompositeMaterialAssemblyProcedures", true, value);
}
std::vector<GCompositeMaterial_t> GCompositeMaterialEditorPoint_t::GetCompositeMaterials() const {
    CUtlVector<GCompositeMaterial_t>* vec = GetSchemaValue<CUtlVector<GCompositeMaterial_t>*>(m_ptr, "CompositeMaterialEditorPoint_t", "m_vecCompositeMaterials"); std::vector<GCompositeMaterial_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCompositeMaterialEditorPoint_t::SetCompositeMaterials(std::vector<GCompositeMaterial_t> value) {
    SetSchemaValueCUtlVector<GCompositeMaterial_t>(m_ptr, "CompositeMaterialEditorPoint_t", "m_vecCompositeMaterials", true, value);
}
std::string GCompositeMaterialEditorPoint_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCompositeMaterialEditorPoint_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCompositeMaterialEditorPoint_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompositeMaterialEditorPoint_t>("CompositeMaterialEditorPoint_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SequenceIndex", &GCompositeMaterialEditorPoint_t::GetSequenceIndex, &GCompositeMaterialEditorPoint_t::SetSequenceIndex)
        .addProperty("Cycle", &GCompositeMaterialEditorPoint_t::GetCycle, &GCompositeMaterialEditorPoint_t::SetCycle)
        .addProperty("EnableChildModel", &GCompositeMaterialEditorPoint_t::GetEnableChildModel, &GCompositeMaterialEditorPoint_t::SetEnableChildModel)
        .addProperty("CompositeMaterialAssemblyProcedures", &GCompositeMaterialEditorPoint_t::GetCompositeMaterialAssemblyProcedures, &GCompositeMaterialEditorPoint_t::SetCompositeMaterialAssemblyProcedures)
        .addProperty("CompositeMaterials", &GCompositeMaterialEditorPoint_t::GetCompositeMaterials, &GCompositeMaterialEditorPoint_t::SetCompositeMaterials)
        .addFunction("ToPtr", &GCompositeMaterialEditorPoint_t::ToPtr)
        .addFunction("IsValid", &GCompositeMaterialEditorPoint_t::IsValid)
        .endClass();
}