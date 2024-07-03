#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseFlex::GCBaseFlex(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseFlex::GCBaseFlex(void *ptr) {
    m_ptr = ptr;
}
std::vector<float32> GCBaseFlex::GetFlexWeight() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CBaseFlex", "m_flexWeight"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCBaseFlex::SetFlexWeight(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CBaseFlex", "m_flexWeight", false, value);
}
Vector GCBaseFlex::GetLookTargetPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseFlex", "m_vLookTargetPosition");
}
void GCBaseFlex::SetLookTargetPosition(Vector value) {
    SetSchemaValue(m_ptr, "CBaseFlex", "m_vLookTargetPosition", false, value);
}
bool GCBaseFlex::GetBlinktoggle() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseFlex", "m_blinktoggle");
}
void GCBaseFlex::SetBlinktoggle(bool value) {
    SetSchemaValue(m_ptr, "CBaseFlex", "m_blinktoggle", false, value);
}
float GCBaseFlex::GetAllowResponsesEndTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseFlex", "m_flAllowResponsesEndTime");
}
void GCBaseFlex::SetAllowResponsesEndTime(float value) {
    SetSchemaValue(m_ptr, "CBaseFlex", "m_flAllowResponsesEndTime", false, value);
}
float GCBaseFlex::GetLastFlexAnimationTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseFlex", "m_flLastFlexAnimationTime");
}
void GCBaseFlex::SetLastFlexAnimationTime(float value) {
    SetSchemaValue(m_ptr, "CBaseFlex", "m_flLastFlexAnimationTime", false, value);
}
GSceneEventId_t GCBaseFlex::GetNextSceneEventId() const {
    GSceneEventId_t value(GetSchemaPtr(m_ptr, "CBaseFlex", "m_nNextSceneEventId"));
    return value;
}
void GCBaseFlex::SetNextSceneEventId(GSceneEventId_t value) {
    SetSchemaValue(m_ptr, "CBaseFlex", "m_nNextSceneEventId", false, value);
}
bool GCBaseFlex::GetUpdateLayerPriorities() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseFlex", "m_bUpdateLayerPriorities");
}
void GCBaseFlex::SetUpdateLayerPriorities(bool value) {
    SetSchemaValue(m_ptr, "CBaseFlex", "m_bUpdateLayerPriorities", false, value);
}
std::string GCBaseFlex::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseFlex::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseAnimGraph GCBaseFlex::GetParent() const {
    GCBaseAnimGraph value(m_ptr);
    return value;
}
void GCBaseFlex::SetParent(GCBaseAnimGraph value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseFlex(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseFlex>("CBaseFlex")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FlexWeight", &GCBaseFlex::GetFlexWeight, &GCBaseFlex::SetFlexWeight)
        .addProperty("LookTargetPosition", &GCBaseFlex::GetLookTargetPosition, &GCBaseFlex::SetLookTargetPosition)
        .addProperty("Blinktoggle", &GCBaseFlex::GetBlinktoggle, &GCBaseFlex::SetBlinktoggle)
        .addProperty("AllowResponsesEndTime", &GCBaseFlex::GetAllowResponsesEndTime, &GCBaseFlex::SetAllowResponsesEndTime)
        .addProperty("LastFlexAnimationTime", &GCBaseFlex::GetLastFlexAnimationTime, &GCBaseFlex::SetLastFlexAnimationTime)
        .addProperty("NextSceneEventId", &GCBaseFlex::GetNextSceneEventId, &GCBaseFlex::SetNextSceneEventId)
        .addProperty("UpdateLayerPriorities", &GCBaseFlex::GetUpdateLayerPriorities, &GCBaseFlex::SetUpdateLayerPriorities)
        .addProperty("Parent", &GCBaseFlex::GetParent, &GCBaseFlex::SetParent)
        .addFunction("ToPtr", &GCBaseFlex::ToPtr)
        .addFunction("IsValid", &GCBaseFlex::IsValid)
        .endClass();
}