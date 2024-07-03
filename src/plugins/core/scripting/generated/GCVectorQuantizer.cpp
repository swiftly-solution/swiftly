#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVectorQuantizer::GCVectorQuantizer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVectorQuantizer::GCVectorQuantizer(void *ptr) {
    m_ptr = ptr;
}
std::vector<float32> GCVectorQuantizer::GetCentroidVectors() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CVectorQuantizer", "m_centroidVectors"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCVectorQuantizer::SetCentroidVectors(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CVectorQuantizer", "m_centroidVectors", false, value);
}
int32_t GCVectorQuantizer::GetCentroids() const {
    return GetSchemaValue<int32_t>(m_ptr, "CVectorQuantizer", "m_nCentroids");
}
void GCVectorQuantizer::SetCentroids(int32_t value) {
    SetSchemaValue(m_ptr, "CVectorQuantizer", "m_nCentroids", false, value);
}
int32_t GCVectorQuantizer::GetDimensions() const {
    return GetSchemaValue<int32_t>(m_ptr, "CVectorQuantizer", "m_nDimensions");
}
void GCVectorQuantizer::SetDimensions(int32_t value) {
    SetSchemaValue(m_ptr, "CVectorQuantizer", "m_nDimensions", false, value);
}
std::string GCVectorQuantizer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVectorQuantizer::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCVectorQuantizer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVectorQuantizer>("CVectorQuantizer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CentroidVectors", &GCVectorQuantizer::GetCentroidVectors, &GCVectorQuantizer::SetCentroidVectors)
        .addProperty("Centroids", &GCVectorQuantizer::GetCentroids, &GCVectorQuantizer::SetCentroids)
        .addProperty("Dimensions", &GCVectorQuantizer::GetDimensions, &GCVectorQuantizer::SetDimensions)
        .addFunction("ToPtr", &GCVectorQuantizer::ToPtr)
        .addFunction("IsValid", &GCVectorQuantizer::IsValid)
        .endClass();
}