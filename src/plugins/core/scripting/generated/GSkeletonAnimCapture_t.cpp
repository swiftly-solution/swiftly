#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSkeletonAnimCapture_t::GSkeletonAnimCapture_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSkeletonAnimCapture_t::GSkeletonAnimCapture_t(void *ptr) {
    m_ptr = ptr;
}
CEntityIndex GSkeletonAnimCapture_t::GetEntIndex() const {
    return GetSchemaValue<CEntityIndex>(m_ptr, "SkeletonAnimCapture_t", "m_nEntIndex");
}
void GSkeletonAnimCapture_t::SetEntIndex(CEntityIndex value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t", "m_nEntIndex", true, value);
}
CEntityIndex GSkeletonAnimCapture_t::GetEntParent() const {
    return GetSchemaValue<CEntityIndex>(m_ptr, "SkeletonAnimCapture_t", "m_nEntParent");
}
void GSkeletonAnimCapture_t::SetEntParent(CEntityIndex value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t", "m_nEntParent", true, value);
}
std::vector<CEntityIndex> GSkeletonAnimCapture_t::GetImportedCollision() const {
    CUtlVector<CEntityIndex>* vec = GetSchemaValue<CUtlVector<CEntityIndex>*>(m_ptr, "SkeletonAnimCapture_t", "m_ImportedCollision"); std::vector<CEntityIndex> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GSkeletonAnimCapture_t::SetImportedCollision(std::vector<CEntityIndex> value) {
    SetSchemaValueCUtlVector<CEntityIndex>(m_ptr, "SkeletonAnimCapture_t", "m_ImportedCollision", true, value);
}
std::string GSkeletonAnimCapture_t::GetModelName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "SkeletonAnimCapture_t", "m_ModelName").Get();
}
void GSkeletonAnimCapture_t::SetModelName(std::string value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t", "m_ModelName", true, CUtlString(value.c_str()));
}
std::string GSkeletonAnimCapture_t::GetCaptureName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "SkeletonAnimCapture_t", "m_CaptureName").Get();
}
void GSkeletonAnimCapture_t::SetCaptureName(std::string value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t", "m_CaptureName", true, CUtlString(value.c_str()));
}
std::vector<GSkeletonAnimCapture_t> GSkeletonAnimCapture_t::GetModelBindPose() const {
    CUtlVector<GSkeletonAnimCapture_t>* vec = GetSchemaValue<CUtlVector<GSkeletonAnimCapture_t>*>(m_ptr, "SkeletonAnimCapture_t", "m_ModelBindPose"); std::vector<GSkeletonAnimCapture_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GSkeletonAnimCapture_t::SetModelBindPose(std::vector<GSkeletonAnimCapture_t> value) {
    SetSchemaValueCUtlVector<GSkeletonAnimCapture_t>(m_ptr, "SkeletonAnimCapture_t", "m_ModelBindPose", true, value);
}
std::vector<GSkeletonAnimCapture_t> GSkeletonAnimCapture_t::GetFeModelInitPose() const {
    CUtlVector<GSkeletonAnimCapture_t>* vec = GetSchemaValue<CUtlVector<GSkeletonAnimCapture_t>*>(m_ptr, "SkeletonAnimCapture_t", "m_FeModelInitPose"); std::vector<GSkeletonAnimCapture_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GSkeletonAnimCapture_t::SetFeModelInitPose(std::vector<GSkeletonAnimCapture_t> value) {
    SetSchemaValueCUtlVector<GSkeletonAnimCapture_t>(m_ptr, "SkeletonAnimCapture_t", "m_FeModelInitPose", true, value);
}
int32_t GSkeletonAnimCapture_t::GetFlexControllers() const {
    return GetSchemaValue<int32_t>(m_ptr, "SkeletonAnimCapture_t", "m_nFlexControllers");
}
void GSkeletonAnimCapture_t::SetFlexControllers(int32_t value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t", "m_nFlexControllers", true, value);
}
bool GSkeletonAnimCapture_t::GetPredicted() const {
    return GetSchemaValue<bool>(m_ptr, "SkeletonAnimCapture_t", "m_bPredicted");
}
void GSkeletonAnimCapture_t::SetPredicted(bool value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t", "m_bPredicted", true, value);
}
std::vector<GSkeletonAnimCapture_t> GSkeletonAnimCapture_t::GetFrames() const {
    CUtlVector<GSkeletonAnimCapture_t>* vec = GetSchemaValue<CUtlVector<GSkeletonAnimCapture_t>*>(m_ptr, "SkeletonAnimCapture_t", "m_Frames"); std::vector<GSkeletonAnimCapture_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GSkeletonAnimCapture_t::SetFrames(std::vector<GSkeletonAnimCapture_t> value) {
    SetSchemaValueCUtlVector<GSkeletonAnimCapture_t>(m_ptr, "SkeletonAnimCapture_t", "m_Frames", true, value);
}
std::string GSkeletonAnimCapture_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSkeletonAnimCapture_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSkeletonAnimCapture_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonAnimCapture_t>("SkeletonAnimCapture_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EntIndex", &GSkeletonAnimCapture_t::GetEntIndex, &GSkeletonAnimCapture_t::SetEntIndex)
        .addProperty("EntParent", &GSkeletonAnimCapture_t::GetEntParent, &GSkeletonAnimCapture_t::SetEntParent)
        .addProperty("ImportedCollision", &GSkeletonAnimCapture_t::GetImportedCollision, &GSkeletonAnimCapture_t::SetImportedCollision)
        .addProperty("ModelName", &GSkeletonAnimCapture_t::GetModelName, &GSkeletonAnimCapture_t::SetModelName)
        .addProperty("CaptureName", &GSkeletonAnimCapture_t::GetCaptureName, &GSkeletonAnimCapture_t::SetCaptureName)
        .addProperty("ModelBindPose", &GSkeletonAnimCapture_t::GetModelBindPose, &GSkeletonAnimCapture_t::SetModelBindPose)
        .addProperty("FeModelInitPose", &GSkeletonAnimCapture_t::GetFeModelInitPose, &GSkeletonAnimCapture_t::SetFeModelInitPose)
        .addProperty("FlexControllers", &GSkeletonAnimCapture_t::GetFlexControllers, &GSkeletonAnimCapture_t::SetFlexControllers)
        .addProperty("Predicted", &GSkeletonAnimCapture_t::GetPredicted, &GSkeletonAnimCapture_t::SetPredicted)
        .addProperty("Frames", &GSkeletonAnimCapture_t::GetFrames, &GSkeletonAnimCapture_t::SetFrames)
        .addFunction("ToPtr", &GSkeletonAnimCapture_t::ToPtr)
        .addFunction("IsValid", &GSkeletonAnimCapture_t::IsValid)
        .endClass();
}