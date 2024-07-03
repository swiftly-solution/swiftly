#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRenderHairStrandInfo_t::GRenderHairStrandInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRenderHairStrandInfo_t::GRenderHairStrandInfo_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint32_t> GRenderHairStrandInfo_t::GetGuideHairIndices_nSurfaceTriIndex() const {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "RenderHairStrandInfo_t", "m_nGuideHairIndices_nSurfaceTriIndex"); std::vector<uint32_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GRenderHairStrandInfo_t::SetGuideHairIndices_nSurfaceTriIndex(std::vector<uint32_t> value) {
    uint32_t* outValue = GetSchemaValue<uint32_t*>(m_ptr, "RenderHairStrandInfo_t", "m_nGuideHairIndices_nSurfaceTriIndex"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RenderHairStrandInfo_t", "m_nGuideHairIndices_nSurfaceTriIndex", true, outValue);
}
std::vector<uint16_t> GRenderHairStrandInfo_t::GetGuideBary_vBaseBary() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RenderHairStrandInfo_t", "m_vGuideBary_vBaseBary"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GRenderHairStrandInfo_t::SetGuideBary_vBaseBary(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RenderHairStrandInfo_t", "m_vGuideBary_vBaseBary"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RenderHairStrandInfo_t", "m_vGuideBary_vBaseBary", true, outValue);
}
std::vector<uint16_t> GRenderHairStrandInfo_t::GetRootOffset_flLengthScale() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RenderHairStrandInfo_t", "m_vRootOffset_flLengthScale"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GRenderHairStrandInfo_t::SetRootOffset_flLengthScale(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RenderHairStrandInfo_t", "m_vRootOffset_flLengthScale"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RenderHairStrandInfo_t", "m_vRootOffset_flLengthScale", true, outValue);
}
std::vector<uint16_t> GRenderHairStrandInfo_t::GetPackedBaseUv() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RenderHairStrandInfo_t", "m_nPackedBaseUv"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GRenderHairStrandInfo_t::SetPackedBaseUv(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "RenderHairStrandInfo_t", "m_nPackedBaseUv"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RenderHairStrandInfo_t", "m_nPackedBaseUv", true, outValue);
}
uint32_t GRenderHairStrandInfo_t::GetPackedSurfaceNormalOs() const {
    return GetSchemaValue<uint32_t>(m_ptr, "RenderHairStrandInfo_t", "m_nPackedSurfaceNormalOs");
}
void GRenderHairStrandInfo_t::SetPackedSurfaceNormalOs(uint32_t value) {
    SetSchemaValue(m_ptr, "RenderHairStrandInfo_t", "m_nPackedSurfaceNormalOs", true, value);
}
uint32_t GRenderHairStrandInfo_t::GetPackedSurfaceTangentOs() const {
    return GetSchemaValue<uint32_t>(m_ptr, "RenderHairStrandInfo_t", "m_nPackedSurfaceTangentOs");
}
void GRenderHairStrandInfo_t::SetPackedSurfaceTangentOs(uint32_t value) {
    SetSchemaValue(m_ptr, "RenderHairStrandInfo_t", "m_nPackedSurfaceTangentOs", true, value);
}
std::string GRenderHairStrandInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRenderHairStrandInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRenderHairStrandInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRenderHairStrandInfo_t>("RenderHairStrandInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("GuideHairIndices_nSurfaceTriIndex", &GRenderHairStrandInfo_t::GetGuideHairIndices_nSurfaceTriIndex, &GRenderHairStrandInfo_t::SetGuideHairIndices_nSurfaceTriIndex)
        .addProperty("GuideBary_vBaseBary", &GRenderHairStrandInfo_t::GetGuideBary_vBaseBary, &GRenderHairStrandInfo_t::SetGuideBary_vBaseBary)
        .addProperty("RootOffset_flLengthScale", &GRenderHairStrandInfo_t::GetRootOffset_flLengthScale, &GRenderHairStrandInfo_t::SetRootOffset_flLengthScale)
        .addProperty("PackedBaseUv", &GRenderHairStrandInfo_t::GetPackedBaseUv, &GRenderHairStrandInfo_t::SetPackedBaseUv)
        .addProperty("PackedSurfaceNormalOs", &GRenderHairStrandInfo_t::GetPackedSurfaceNormalOs, &GRenderHairStrandInfo_t::SetPackedSurfaceNormalOs)
        .addProperty("PackedSurfaceTangentOs", &GRenderHairStrandInfo_t::GetPackedSurfaceTangentOs, &GRenderHairStrandInfo_t::SetPackedSurfaceTangentOs)
        .addFunction("ToPtr", &GRenderHairStrandInfo_t::ToPtr)
        .addFunction("IsValid", &GRenderHairStrandInfo_t::IsValid)
        .endClass();
}