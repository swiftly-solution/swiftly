#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmSkeleton::GCNmSkeleton(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmSkeleton::GCNmSkeleton(void *ptr) {
    m_ptr = ptr;
}
std::vector<int32> GCNmSkeleton::GetParentIndices() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CNmSkeleton", "m_parentIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCNmSkeleton::SetParentIndices(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CNmSkeleton", "m_parentIndices", false, value);
}
int32_t GCNmSkeleton::GetNumBonesToSampleAtLowLOD() const {
    return GetSchemaValue<int32_t>(m_ptr, "CNmSkeleton", "m_numBonesToSampleAtLowLOD");
}
void GCNmSkeleton::SetNumBonesToSampleAtLowLOD(int32_t value) {
    SetSchemaValue(m_ptr, "CNmSkeleton", "m_numBonesToSampleAtLowLOD", false, value);
}
std::string GCNmSkeleton::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmSkeleton::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmSkeleton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmSkeleton>("CNmSkeleton")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ParentIndices", &GCNmSkeleton::GetParentIndices, &GCNmSkeleton::SetParentIndices)
        .addProperty("NumBonesToSampleAtLowLOD", &GCNmSkeleton::GetNumBonesToSampleAtLowLOD, &GCNmSkeleton::SetNumBonesToSampleAtLowLOD)
        .addFunction("ToPtr", &GCNmSkeleton::ToPtr)
        .addFunction("IsValid", &GCNmSkeleton::IsValid)
        .endClass();
}