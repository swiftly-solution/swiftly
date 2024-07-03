#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSkeletonAnimCapture_t__Frame_t::GSkeletonAnimCapture_t__Frame_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSkeletonAnimCapture_t__Frame_t::GSkeletonAnimCapture_t__Frame_t(void *ptr) {
    m_ptr = ptr;
}
float GSkeletonAnimCapture_t__Frame_t::GetTime() const {
    return GetSchemaValue<float>(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_flTime");
}
void GSkeletonAnimCapture_t__Frame_t::SetTime(float value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_flTime", true, value);
}
GSkeletonAnimCapture_t GSkeletonAnimCapture_t__Frame_t::GetStamp() const {
    GSkeletonAnimCapture_t value(GetSchemaPtr(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_Stamp"));
    return value;
}
void GSkeletonAnimCapture_t__Frame_t::SetStamp(GSkeletonAnimCapture_t value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_Stamp", true, value);
}
bool GSkeletonAnimCapture_t__Frame_t::GetTeleport() const {
    return GetSchemaValue<bool>(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_bTeleport");
}
void GSkeletonAnimCapture_t__Frame_t::SetTeleport(bool value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_bTeleport", true, value);
}
std::vector<Vector> GSkeletonAnimCapture_t__Frame_t::GetFeModelPos() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_FeModelPos"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GSkeletonAnimCapture_t__Frame_t::SetFeModelPos(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_FeModelPos", true, value);
}
std::vector<float32> GSkeletonAnimCapture_t__Frame_t::GetFlexControllerWeights() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_FlexControllerWeights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GSkeletonAnimCapture_t__Frame_t::SetFlexControllerWeights(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "SkeletonAnimCapture_t__Frame_t", "m_FlexControllerWeights", true, value);
}
std::string GSkeletonAnimCapture_t__Frame_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSkeletonAnimCapture_t__Frame_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSkeletonAnimCapture_t__Frame_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonAnimCapture_t__Frame_t>("SkeletonAnimCapture_t__Frame_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Time", &GSkeletonAnimCapture_t__Frame_t::GetTime, &GSkeletonAnimCapture_t__Frame_t::SetTime)
        .addProperty("Stamp", &GSkeletonAnimCapture_t__Frame_t::GetStamp, &GSkeletonAnimCapture_t__Frame_t::SetStamp)
        .addProperty("Teleport", &GSkeletonAnimCapture_t__Frame_t::GetTeleport, &GSkeletonAnimCapture_t__Frame_t::SetTeleport)
        .addProperty("FeModelPos", &GSkeletonAnimCapture_t__Frame_t::GetFeModelPos, &GSkeletonAnimCapture_t__Frame_t::SetFeModelPos)
        .addProperty("FlexControllerWeights", &GSkeletonAnimCapture_t__Frame_t::GetFlexControllerWeights, &GSkeletonAnimCapture_t__Frame_t::SetFlexControllerWeights)
        .addFunction("ToPtr", &GSkeletonAnimCapture_t__Frame_t::ToPtr)
        .addFunction("IsValid", &GSkeletonAnimCapture_t__Frame_t::IsValid)
        .endClass();
}