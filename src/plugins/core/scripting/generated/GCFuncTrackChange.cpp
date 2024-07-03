#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFuncTrackChange::GCFuncTrackChange(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFuncTrackChange::GCFuncTrackChange(void *ptr) {
    m_ptr = ptr;
}
GCPathTrack GCFuncTrackChange::GetTrackTop() const {
    GCPathTrack value(*GetSchemaValuePtr<void*>(m_ptr, "CFuncTrackChange", "m_trackTop"));
    return value;
}
void GCFuncTrackChange::SetTrackTop(GCPathTrack* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TrackTop' is not possible.\n");
}
GCPathTrack GCFuncTrackChange::GetTrackBottom() const {
    GCPathTrack value(*GetSchemaValuePtr<void*>(m_ptr, "CFuncTrackChange", "m_trackBottom"));
    return value;
}
void GCFuncTrackChange::SetTrackBottom(GCPathTrack* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TrackBottom' is not possible.\n");
}
GCFuncTrackTrain GCFuncTrackChange::GetTrain() const {
    GCFuncTrackTrain value(*GetSchemaValuePtr<void*>(m_ptr, "CFuncTrackChange", "m_train"));
    return value;
}
void GCFuncTrackChange::SetTrain(GCFuncTrackTrain* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Train' is not possible.\n");
}
std::string GCFuncTrackChange::GetTrackTopName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackChange", "m_trackTopName").String();
}
void GCFuncTrackChange::SetTrackTopName(std::string value) {
    SetSchemaValue(m_ptr, "CFuncTrackChange", "m_trackTopName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncTrackChange::GetTrackBottomName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackChange", "m_trackBottomName").String();
}
void GCFuncTrackChange::SetTrackBottomName(std::string value) {
    SetSchemaValue(m_ptr, "CFuncTrackChange", "m_trackBottomName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFuncTrackChange::GetTrainName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFuncTrackChange", "m_trainName").String();
}
void GCFuncTrackChange::SetTrainName(std::string value) {
    SetSchemaValue(m_ptr, "CFuncTrackChange", "m_trainName", false, CUtlSymbolLarge(value.c_str()));
}
uint64_t GCFuncTrackChange::GetCode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFuncTrackChange", "m_code");
}
void GCFuncTrackChange::SetCode(uint64_t value) {
    SetSchemaValue(m_ptr, "CFuncTrackChange", "m_code", false, value);
}
int32_t GCFuncTrackChange::GetTargetState() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFuncTrackChange", "m_targetState");
}
void GCFuncTrackChange::SetTargetState(int32_t value) {
    SetSchemaValue(m_ptr, "CFuncTrackChange", "m_targetState", false, value);
}
int32_t GCFuncTrackChange::GetUse() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFuncTrackChange", "m_use");
}
void GCFuncTrackChange::SetUse(int32_t value) {
    SetSchemaValue(m_ptr, "CFuncTrackChange", "m_use", false, value);
}
std::string GCFuncTrackChange::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFuncTrackChange::IsValid() {
    return (m_ptr != nullptr);
}
GCFuncPlatRot GCFuncTrackChange::GetParent() const {
    GCFuncPlatRot value(m_ptr);
    return value;
}
void GCFuncTrackChange::SetParent(GCFuncPlatRot value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFuncTrackChange(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTrackChange>("CFuncTrackChange")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TrackTop", &GCFuncTrackChange::GetTrackTop, &GCFuncTrackChange::SetTrackTop)
        .addProperty("TrackBottom", &GCFuncTrackChange::GetTrackBottom, &GCFuncTrackChange::SetTrackBottom)
        .addProperty("Train", &GCFuncTrackChange::GetTrain, &GCFuncTrackChange::SetTrain)
        .addProperty("TrackTopName", &GCFuncTrackChange::GetTrackTopName, &GCFuncTrackChange::SetTrackTopName)
        .addProperty("TrackBottomName", &GCFuncTrackChange::GetTrackBottomName, &GCFuncTrackChange::SetTrackBottomName)
        .addProperty("TrainName", &GCFuncTrackChange::GetTrainName, &GCFuncTrackChange::SetTrainName)
        .addProperty("Code", &GCFuncTrackChange::GetCode, &GCFuncTrackChange::SetCode)
        .addProperty("TargetState", &GCFuncTrackChange::GetTargetState, &GCFuncTrackChange::SetTargetState)
        .addProperty("Use", &GCFuncTrackChange::GetUse, &GCFuncTrackChange::SetUse)
        .addProperty("Parent", &GCFuncTrackChange::GetParent, &GCFuncTrackChange::SetParent)
        .addFunction("ToPtr", &GCFuncTrackChange::ToPtr)
        .addFunction("IsValid", &GCFuncTrackChange::IsValid)
        .endClass();
}