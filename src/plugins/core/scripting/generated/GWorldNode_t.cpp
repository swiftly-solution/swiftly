#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GWorldNode_t::GWorldNode_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GWorldNode_t::GWorldNode_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GSceneObject_t> GWorldNode_t::GetSceneObjects() const {
    CUtlVector<GSceneObject_t>* vec = GetSchemaValue<CUtlVector<GSceneObject_t>*>(m_ptr, "WorldNode_t", "m_sceneObjects"); std::vector<GSceneObject_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorldNode_t::SetSceneObjects(std::vector<GSceneObject_t> value) {
    SetSchemaValueCUtlVector<GSceneObject_t>(m_ptr, "WorldNode_t", "m_sceneObjects", true, value);
}
std::vector<GInfoOverlayData_t> GWorldNode_t::GetInfoOverlays() const {
    CUtlVector<GInfoOverlayData_t>* vec = GetSchemaValue<CUtlVector<GInfoOverlayData_t>*>(m_ptr, "WorldNode_t", "m_infoOverlays"); std::vector<GInfoOverlayData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorldNode_t::SetInfoOverlays(std::vector<GInfoOverlayData_t> value) {
    SetSchemaValueCUtlVector<GInfoOverlayData_t>(m_ptr, "WorldNode_t", "m_infoOverlays", true, value);
}
std::vector<uint16> GWorldNode_t::GetVisClusterMembership() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "WorldNode_t", "m_visClusterMembership"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorldNode_t::SetVisClusterMembership(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "WorldNode_t", "m_visClusterMembership", true, value);
}
std::vector<GAggregateSceneObject_t> GWorldNode_t::GetAggregateSceneObjects() const {
    CUtlVector<GAggregateSceneObject_t>* vec = GetSchemaValue<CUtlVector<GAggregateSceneObject_t>*>(m_ptr, "WorldNode_t", "m_aggregateSceneObjects"); std::vector<GAggregateSceneObject_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorldNode_t::SetAggregateSceneObjects(std::vector<GAggregateSceneObject_t> value) {
    SetSchemaValueCUtlVector<GAggregateSceneObject_t>(m_ptr, "WorldNode_t", "m_aggregateSceneObjects", true, value);
}
std::vector<GClutterSceneObject_t> GWorldNode_t::GetClutterSceneObjects() const {
    CUtlVector<GClutterSceneObject_t>* vec = GetSchemaValue<CUtlVector<GClutterSceneObject_t>*>(m_ptr, "WorldNode_t", "m_clutterSceneObjects"); std::vector<GClutterSceneObject_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorldNode_t::SetClutterSceneObjects(std::vector<GClutterSceneObject_t> value) {
    SetSchemaValueCUtlVector<GClutterSceneObject_t>(m_ptr, "WorldNode_t", "m_clutterSceneObjects", true, value);
}
std::vector<GExtraVertexStreamOverride_t> GWorldNode_t::GetExtraVertexStreamOverrides() const {
    CUtlVector<GExtraVertexStreamOverride_t>* vec = GetSchemaValue<CUtlVector<GExtraVertexStreamOverride_t>*>(m_ptr, "WorldNode_t", "m_extraVertexStreamOverrides"); std::vector<GExtraVertexStreamOverride_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorldNode_t::SetExtraVertexStreamOverrides(std::vector<GExtraVertexStreamOverride_t> value) {
    SetSchemaValueCUtlVector<GExtraVertexStreamOverride_t>(m_ptr, "WorldNode_t", "m_extraVertexStreamOverrides", true, value);
}
std::vector<GMaterialOverride_t> GWorldNode_t::GetMaterialOverrides() const {
    CUtlVector<GMaterialOverride_t>* vec = GetSchemaValue<CUtlVector<GMaterialOverride_t>*>(m_ptr, "WorldNode_t", "m_materialOverrides"); std::vector<GMaterialOverride_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorldNode_t::SetMaterialOverrides(std::vector<GMaterialOverride_t> value) {
    SetSchemaValueCUtlVector<GMaterialOverride_t>(m_ptr, "WorldNode_t", "m_materialOverrides", true, value);
}
std::vector<GWorldNodeOnDiskBufferData_t> GWorldNode_t::GetExtraVertexStreams() const {
    CUtlVector<GWorldNodeOnDiskBufferData_t>* vec = GetSchemaValue<CUtlVector<GWorldNodeOnDiskBufferData_t>*>(m_ptr, "WorldNode_t", "m_extraVertexStreams"); std::vector<GWorldNodeOnDiskBufferData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorldNode_t::SetExtraVertexStreams(std::vector<GWorldNodeOnDiskBufferData_t> value) {
    SetSchemaValueCUtlVector<GWorldNodeOnDiskBufferData_t>(m_ptr, "WorldNode_t", "m_extraVertexStreams", true, value);
}
std::vector<CUtlString> GWorldNode_t::GetLayerNames() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "WorldNode_t", "m_layerNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorldNode_t::SetLayerNames(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "WorldNode_t", "m_layerNames", true, value);
}
std::vector<uint8> GWorldNode_t::GetSceneObjectLayerIndices() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "WorldNode_t", "m_sceneObjectLayerIndices"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorldNode_t::SetSceneObjectLayerIndices(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "WorldNode_t", "m_sceneObjectLayerIndices", true, value);
}
std::vector<uint8> GWorldNode_t::GetOverlayLayerIndices() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "WorldNode_t", "m_overlayLayerIndices"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorldNode_t::SetOverlayLayerIndices(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "WorldNode_t", "m_overlayLayerIndices", true, value);
}
std::string GWorldNode_t::GetGrassFileName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "WorldNode_t", "m_grassFileName").Get();
}
void GWorldNode_t::SetGrassFileName(std::string value) {
    SetSchemaValue(m_ptr, "WorldNode_t", "m_grassFileName", true, CUtlString(value.c_str()));
}
GBakedLightingInfo_t GWorldNode_t::GetNodeLightingInfo() const {
    GBakedLightingInfo_t value(GetSchemaPtr(m_ptr, "WorldNode_t", "m_nodeLightingInfo"));
    return value;
}
void GWorldNode_t::SetNodeLightingInfo(GBakedLightingInfo_t value) {
    SetSchemaValue(m_ptr, "WorldNode_t", "m_nodeLightingInfo", true, value);
}
std::string GWorldNode_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GWorldNode_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassWorldNode_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWorldNode_t>("WorldNode_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SceneObjects", &GWorldNode_t::GetSceneObjects, &GWorldNode_t::SetSceneObjects)
        .addProperty("InfoOverlays", &GWorldNode_t::GetInfoOverlays, &GWorldNode_t::SetInfoOverlays)
        .addProperty("VisClusterMembership", &GWorldNode_t::GetVisClusterMembership, &GWorldNode_t::SetVisClusterMembership)
        .addProperty("AggregateSceneObjects", &GWorldNode_t::GetAggregateSceneObjects, &GWorldNode_t::SetAggregateSceneObjects)
        .addProperty("ClutterSceneObjects", &GWorldNode_t::GetClutterSceneObjects, &GWorldNode_t::SetClutterSceneObjects)
        .addProperty("ExtraVertexStreamOverrides", &GWorldNode_t::GetExtraVertexStreamOverrides, &GWorldNode_t::SetExtraVertexStreamOverrides)
        .addProperty("MaterialOverrides", &GWorldNode_t::GetMaterialOverrides, &GWorldNode_t::SetMaterialOverrides)
        .addProperty("ExtraVertexStreams", &GWorldNode_t::GetExtraVertexStreams, &GWorldNode_t::SetExtraVertexStreams)
        .addProperty("LayerNames", &GWorldNode_t::GetLayerNames, &GWorldNode_t::SetLayerNames)
        .addProperty("SceneObjectLayerIndices", &GWorldNode_t::GetSceneObjectLayerIndices, &GWorldNode_t::SetSceneObjectLayerIndices)
        .addProperty("OverlayLayerIndices", &GWorldNode_t::GetOverlayLayerIndices, &GWorldNode_t::SetOverlayLayerIndices)
        .addProperty("GrassFileName", &GWorldNode_t::GetGrassFileName, &GWorldNode_t::SetGrassFileName)
        .addProperty("NodeLightingInfo", &GWorldNode_t::GetNodeLightingInfo, &GWorldNode_t::SetNodeLightingInfo)
        .addFunction("ToPtr", &GWorldNode_t::ToPtr)
        .addFunction("IsValid", &GWorldNode_t::IsValid)
        .endClass();
}