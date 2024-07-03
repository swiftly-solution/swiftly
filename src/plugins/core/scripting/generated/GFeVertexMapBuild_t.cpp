#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeVertexMapBuild_t::GFeVertexMapBuild_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeVertexMapBuild_t::GFeVertexMapBuild_t(void *ptr) {
    m_ptr = ptr;
}
std::string GFeVertexMapBuild_t::GetVertexMapName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "FeVertexMapBuild_t", "m_VertexMapName").Get();
}
void GFeVertexMapBuild_t::SetVertexMapName(std::string value) {
    SetSchemaValue(m_ptr, "FeVertexMapBuild_t", "m_VertexMapName", true, CUtlString(value.c_str()));
}
uint32_t GFeVertexMapBuild_t::GetNameHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeVertexMapBuild_t", "m_nNameHash");
}
void GFeVertexMapBuild_t::SetNameHash(uint32_t value) {
    SetSchemaValue(m_ptr, "FeVertexMapBuild_t", "m_nNameHash", true, value);
}
Color GFeVertexMapBuild_t::GetColor() const {
    return GetSchemaValue<Color>(m_ptr, "FeVertexMapBuild_t", "m_Color");
}
void GFeVertexMapBuild_t::SetColor(Color value) {
    SetSchemaValue(m_ptr, "FeVertexMapBuild_t", "m_Color", true, value);
}
float GFeVertexMapBuild_t::GetVolumetricSolveStrength() const {
    return GetSchemaValue<float>(m_ptr, "FeVertexMapBuild_t", "m_flVolumetricSolveStrength");
}
void GFeVertexMapBuild_t::SetVolumetricSolveStrength(float value) {
    SetSchemaValue(m_ptr, "FeVertexMapBuild_t", "m_flVolumetricSolveStrength", true, value);
}
int32_t GFeVertexMapBuild_t::GetScaleSourceNode() const {
    return GetSchemaValue<int32_t>(m_ptr, "FeVertexMapBuild_t", "m_nScaleSourceNode");
}
void GFeVertexMapBuild_t::SetScaleSourceNode(int32_t value) {
    SetSchemaValue(m_ptr, "FeVertexMapBuild_t", "m_nScaleSourceNode", true, value);
}
std::vector<float32> GFeVertexMapBuild_t::GetWeights() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "FeVertexMapBuild_t", "m_Weights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GFeVertexMapBuild_t::SetWeights(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "FeVertexMapBuild_t", "m_Weights", true, value);
}
std::string GFeVertexMapBuild_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeVertexMapBuild_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeVertexMapBuild_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeVertexMapBuild_t>("FeVertexMapBuild_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("VertexMapName", &GFeVertexMapBuild_t::GetVertexMapName, &GFeVertexMapBuild_t::SetVertexMapName)
        .addProperty("NameHash", &GFeVertexMapBuild_t::GetNameHash, &GFeVertexMapBuild_t::SetNameHash)
        .addProperty("Color", &GFeVertexMapBuild_t::GetColor, &GFeVertexMapBuild_t::SetColor)
        .addProperty("VolumetricSolveStrength", &GFeVertexMapBuild_t::GetVolumetricSolveStrength, &GFeVertexMapBuild_t::SetVolumetricSolveStrength)
        .addProperty("ScaleSourceNode", &GFeVertexMapBuild_t::GetScaleSourceNode, &GFeVertexMapBuild_t::SetScaleSourceNode)
        .addProperty("Weights", &GFeVertexMapBuild_t::GetWeights, &GFeVertexMapBuild_t::SetWeights)
        .addFunction("ToPtr", &GFeVertexMapBuild_t::ToPtr)
        .addFunction("IsValid", &GFeVertexMapBuild_t::IsValid)
        .endClass();
}