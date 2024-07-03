#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GDynamicMeshDeformParams_t::GDynamicMeshDeformParams_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GDynamicMeshDeformParams_t::GDynamicMeshDeformParams_t(void *ptr) {
    m_ptr = ptr;
}
float GDynamicMeshDeformParams_t::GetTensionCompressScale() const {
    return GetSchemaValue<float>(m_ptr, "DynamicMeshDeformParams_t", "m_flTensionCompressScale");
}
void GDynamicMeshDeformParams_t::SetTensionCompressScale(float value) {
    SetSchemaValue(m_ptr, "DynamicMeshDeformParams_t", "m_flTensionCompressScale", true, value);
}
float GDynamicMeshDeformParams_t::GetTensionStretchScale() const {
    return GetSchemaValue<float>(m_ptr, "DynamicMeshDeformParams_t", "m_flTensionStretchScale");
}
void GDynamicMeshDeformParams_t::SetTensionStretchScale(float value) {
    SetSchemaValue(m_ptr, "DynamicMeshDeformParams_t", "m_flTensionStretchScale", true, value);
}
bool GDynamicMeshDeformParams_t::GetRecomputeSmoothNormalsAfterAnimation() const {
    return GetSchemaValue<bool>(m_ptr, "DynamicMeshDeformParams_t", "m_bRecomputeSmoothNormalsAfterAnimation");
}
void GDynamicMeshDeformParams_t::SetRecomputeSmoothNormalsAfterAnimation(bool value) {
    SetSchemaValue(m_ptr, "DynamicMeshDeformParams_t", "m_bRecomputeSmoothNormalsAfterAnimation", true, value);
}
bool GDynamicMeshDeformParams_t::GetComputeDynamicMeshTensionAfterAnimation() const {
    return GetSchemaValue<bool>(m_ptr, "DynamicMeshDeformParams_t", "m_bComputeDynamicMeshTensionAfterAnimation");
}
void GDynamicMeshDeformParams_t::SetComputeDynamicMeshTensionAfterAnimation(bool value) {
    SetSchemaValue(m_ptr, "DynamicMeshDeformParams_t", "m_bComputeDynamicMeshTensionAfterAnimation", true, value);
}
std::string GDynamicMeshDeformParams_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GDynamicMeshDeformParams_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassDynamicMeshDeformParams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GDynamicMeshDeformParams_t>("DynamicMeshDeformParams_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TensionCompressScale", &GDynamicMeshDeformParams_t::GetTensionCompressScale, &GDynamicMeshDeformParams_t::SetTensionCompressScale)
        .addProperty("TensionStretchScale", &GDynamicMeshDeformParams_t::GetTensionStretchScale, &GDynamicMeshDeformParams_t::SetTensionStretchScale)
        .addProperty("RecomputeSmoothNormalsAfterAnimation", &GDynamicMeshDeformParams_t::GetRecomputeSmoothNormalsAfterAnimation, &GDynamicMeshDeformParams_t::SetRecomputeSmoothNormalsAfterAnimation)
        .addProperty("ComputeDynamicMeshTensionAfterAnimation", &GDynamicMeshDeformParams_t::GetComputeDynamicMeshTensionAfterAnimation, &GDynamicMeshDeformParams_t::SetComputeDynamicMeshTensionAfterAnimation)
        .addFunction("ToPtr", &GDynamicMeshDeformParams_t::ToPtr)
        .addFunction("IsValid", &GDynamicMeshDeformParams_t::IsValid)
        .endClass();
}