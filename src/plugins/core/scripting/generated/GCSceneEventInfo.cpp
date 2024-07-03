#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSceneEventInfo::GCSceneEventInfo(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSceneEventInfo::GCSceneEventInfo(void *ptr) {
    m_ptr = ptr;
}
int32_t GCSceneEventInfo::GetLayer() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSceneEventInfo", "m_iLayer");
}
void GCSceneEventInfo::SetLayer(int32_t value) {
    SetSchemaValue(m_ptr, "CSceneEventInfo", "m_iLayer", false, value);
}
int32_t GCSceneEventInfo::GetPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSceneEventInfo", "m_iPriority");
}
void GCSceneEventInfo::SetPriority(int32_t value) {
    SetSchemaValue(m_ptr, "CSceneEventInfo", "m_iPriority", false, value);
}
float GCSceneEventInfo::GetWeight() const {
    return GetSchemaValue<float>(m_ptr, "CSceneEventInfo", "m_flWeight");
}
void GCSceneEventInfo::SetWeight(float value) {
    SetSchemaValue(m_ptr, "CSceneEventInfo", "m_flWeight", false, value);
}
bool GCSceneEventInfo::GetHasArrived() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEventInfo", "m_bHasArrived");
}
void GCSceneEventInfo::SetHasArrived(bool value) {
    SetSchemaValue(m_ptr, "CSceneEventInfo", "m_bHasArrived", false, value);
}
int32_t GCSceneEventInfo::GetType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSceneEventInfo", "m_nType");
}
void GCSceneEventInfo::SetType(int32_t value) {
    SetSchemaValue(m_ptr, "CSceneEventInfo", "m_nType", false, value);
}
float GCSceneEventInfo::GetNext() const {
    return GetSchemaValue<float>(m_ptr, "CSceneEventInfo", "m_flNext");
}
void GCSceneEventInfo::SetNext(float value) {
    SetSchemaValue(m_ptr, "CSceneEventInfo", "m_flNext", false, value);
}
bool GCSceneEventInfo::GetIsGesture() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEventInfo", "m_bIsGesture");
}
void GCSceneEventInfo::SetIsGesture(bool value) {
    SetSchemaValue(m_ptr, "CSceneEventInfo", "m_bIsGesture", false, value);
}
bool GCSceneEventInfo::GetShouldRemove() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEventInfo", "m_bShouldRemove");
}
void GCSceneEventInfo::SetShouldRemove(bool value) {
    SetSchemaValue(m_ptr, "CSceneEventInfo", "m_bShouldRemove", false, value);
}
GCBaseEntity GCSceneEventInfo::GetTarget() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CSceneEventInfo", "m_hTarget"));
    return value;
}
void GCSceneEventInfo::SetTarget(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target' is not possible.\n");
}
GSceneEventId_t GCSceneEventInfo::GetSceneEventId() const {
    GSceneEventId_t value(GetSchemaPtr(m_ptr, "CSceneEventInfo", "m_nSceneEventId"));
    return value;
}
void GCSceneEventInfo::SetSceneEventId(GSceneEventId_t value) {
    SetSchemaValue(m_ptr, "CSceneEventInfo", "m_nSceneEventId", false, value);
}
bool GCSceneEventInfo::GetClientSide() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEventInfo", "m_bClientSide");
}
void GCSceneEventInfo::SetClientSide(bool value) {
    SetSchemaValue(m_ptr, "CSceneEventInfo", "m_bClientSide", false, value);
}
bool GCSceneEventInfo::GetStarted() const {
    return GetSchemaValue<bool>(m_ptr, "CSceneEventInfo", "m_bStarted");
}
void GCSceneEventInfo::SetStarted(bool value) {
    SetSchemaValue(m_ptr, "CSceneEventInfo", "m_bStarted", false, value);
}
std::string GCSceneEventInfo::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSceneEventInfo::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSceneEventInfo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSceneEventInfo>("CSceneEventInfo")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Layer", &GCSceneEventInfo::GetLayer, &GCSceneEventInfo::SetLayer)
        .addProperty("Priority", &GCSceneEventInfo::GetPriority, &GCSceneEventInfo::SetPriority)
        .addProperty("Weight", &GCSceneEventInfo::GetWeight, &GCSceneEventInfo::SetWeight)
        .addProperty("HasArrived", &GCSceneEventInfo::GetHasArrived, &GCSceneEventInfo::SetHasArrived)
        .addProperty("Type", &GCSceneEventInfo::GetType, &GCSceneEventInfo::SetType)
        .addProperty("Next", &GCSceneEventInfo::GetNext, &GCSceneEventInfo::SetNext)
        .addProperty("IsGesture", &GCSceneEventInfo::GetIsGesture, &GCSceneEventInfo::SetIsGesture)
        .addProperty("ShouldRemove", &GCSceneEventInfo::GetShouldRemove, &GCSceneEventInfo::SetShouldRemove)
        .addProperty("Target", &GCSceneEventInfo::GetTarget, &GCSceneEventInfo::SetTarget)
        .addProperty("SceneEventId", &GCSceneEventInfo::GetSceneEventId, &GCSceneEventInfo::SetSceneEventId)
        .addProperty("ClientSide", &GCSceneEventInfo::GetClientSide, &GCSceneEventInfo::SetClientSide)
        .addProperty("Started", &GCSceneEventInfo::GetStarted, &GCSceneEventInfo::SetStarted)
        .addFunction("ToPtr", &GCSceneEventInfo::ToPtr)
        .addFunction("IsValid", &GCSceneEventInfo::IsValid)
        .endClass();
}