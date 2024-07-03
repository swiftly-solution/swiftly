#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAggregateSceneObject_t::GAggregateSceneObject_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAggregateSceneObject_t::GAggregateSceneObject_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GAggregateSceneObject_t::GetAllFlags() const {
    return GetSchemaValue<uint64_t>(m_ptr, "AggregateSceneObject_t", "m_allFlags");
}
void GAggregateSceneObject_t::SetAllFlags(uint64_t value) {
    SetSchemaValue(m_ptr, "AggregateSceneObject_t", "m_allFlags", true, value);
}
uint64_t GAggregateSceneObject_t::GetAnyFlags() const {
    return GetSchemaValue<uint64_t>(m_ptr, "AggregateSceneObject_t", "m_anyFlags");
}
void GAggregateSceneObject_t::SetAnyFlags(uint64_t value) {
    SetSchemaValue(m_ptr, "AggregateSceneObject_t", "m_anyFlags", true, value);
}
int16_t GAggregateSceneObject_t::GetLayer() const {
    return GetSchemaValue<int16_t>(m_ptr, "AggregateSceneObject_t", "m_nLayer");
}
void GAggregateSceneObject_t::SetLayer(int16_t value) {
    SetSchemaValue(m_ptr, "AggregateSceneObject_t", "m_nLayer", true, value);
}
std::vector<GAggregateMeshInfo_t> GAggregateSceneObject_t::GetAggregateMeshes() const {
    CUtlVector<GAggregateMeshInfo_t>* vec = GetSchemaValue<CUtlVector<GAggregateMeshInfo_t>*>(m_ptr, "AggregateSceneObject_t", "m_aggregateMeshes"); std::vector<GAggregateMeshInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAggregateSceneObject_t::SetAggregateMeshes(std::vector<GAggregateMeshInfo_t> value) {
    SetSchemaValueCUtlVector<GAggregateMeshInfo_t>(m_ptr, "AggregateSceneObject_t", "m_aggregateMeshes", true, value);
}
std::vector<GAggregateLODSetup_t> GAggregateSceneObject_t::GetLodSetups() const {
    CUtlVector<GAggregateLODSetup_t>* vec = GetSchemaValue<CUtlVector<GAggregateLODSetup_t>*>(m_ptr, "AggregateSceneObject_t", "m_lodSetups"); std::vector<GAggregateLODSetup_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAggregateSceneObject_t::SetLodSetups(std::vector<GAggregateLODSetup_t> value) {
    SetSchemaValueCUtlVector<GAggregateLODSetup_t>(m_ptr, "AggregateSceneObject_t", "m_lodSetups", true, value);
}
std::vector<uint16> GAggregateSceneObject_t::GetVisClusterMembership() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "AggregateSceneObject_t", "m_visClusterMembership"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAggregateSceneObject_t::SetVisClusterMembership(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "AggregateSceneObject_t", "m_visClusterMembership", true, value);
}
std::vector<matrix3x4_t> GAggregateSceneObject_t::GetFragmentTransforms() const {
    CUtlVector<matrix3x4_t>* vec = GetSchemaValue<CUtlVector<matrix3x4_t>*>(m_ptr, "AggregateSceneObject_t", "m_fragmentTransforms"); std::vector<matrix3x4_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAggregateSceneObject_t::SetFragmentTransforms(std::vector<matrix3x4_t> value) {
    SetSchemaValueCUtlVector<matrix3x4_t>(m_ptr, "AggregateSceneObject_t", "m_fragmentTransforms", true, value);
}
std::string GAggregateSceneObject_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAggregateSceneObject_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAggregateSceneObject_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAggregateSceneObject_t>("AggregateSceneObject_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AllFlags", &GAggregateSceneObject_t::GetAllFlags, &GAggregateSceneObject_t::SetAllFlags)
        .addProperty("AnyFlags", &GAggregateSceneObject_t::GetAnyFlags, &GAggregateSceneObject_t::SetAnyFlags)
        .addProperty("Layer", &GAggregateSceneObject_t::GetLayer, &GAggregateSceneObject_t::SetLayer)
        .addProperty("AggregateMeshes", &GAggregateSceneObject_t::GetAggregateMeshes, &GAggregateSceneObject_t::SetAggregateMeshes)
        .addProperty("LodSetups", &GAggregateSceneObject_t::GetLodSetups, &GAggregateSceneObject_t::SetLodSetups)
        .addProperty("VisClusterMembership", &GAggregateSceneObject_t::GetVisClusterMembership, &GAggregateSceneObject_t::SetVisClusterMembership)
        .addProperty("FragmentTransforms", &GAggregateSceneObject_t::GetFragmentTransforms, &GAggregateSceneObject_t::SetFragmentTransforms)
        .addFunction("ToPtr", &GAggregateSceneObject_t::ToPtr)
        .addFunction("IsValid", &GAggregateSceneObject_t::IsValid)
        .endClass();
}