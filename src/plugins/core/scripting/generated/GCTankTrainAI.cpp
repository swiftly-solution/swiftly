#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTankTrainAI::GCTankTrainAI(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTankTrainAI::GCTankTrainAI(void *ptr) {
    m_ptr = ptr;
}
GCFuncTrackTrain GCTankTrainAI::GetTrain() const {
    GCFuncTrackTrain value(*GetSchemaValuePtr<void*>(m_ptr, "CTankTrainAI", "m_hTrain"));
    return value;
}
void GCTankTrainAI::SetTrain(GCFuncTrackTrain* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Train' is not possible.\n");
}
GCBaseEntity GCTankTrainAI::GetTargetEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CTankTrainAI", "m_hTargetEntity"));
    return value;
}
void GCTankTrainAI::SetTargetEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEntity' is not possible.\n");
}
int32_t GCTankTrainAI::GetSoundPlaying() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTankTrainAI", "m_soundPlaying");
}
void GCTankTrainAI::SetSoundPlaying(int32_t value) {
    SetSchemaValue(m_ptr, "CTankTrainAI", "m_soundPlaying", false, value);
}
std::string GCTankTrainAI::GetStartSoundName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTankTrainAI", "m_startSoundName").String();
}
void GCTankTrainAI::SetStartSoundName(std::string value) {
    SetSchemaValue(m_ptr, "CTankTrainAI", "m_startSoundName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCTankTrainAI::GetEngineSoundName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTankTrainAI", "m_engineSoundName").String();
}
void GCTankTrainAI::SetEngineSoundName(std::string value) {
    SetSchemaValue(m_ptr, "CTankTrainAI", "m_engineSoundName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCTankTrainAI::GetMovementSoundName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTankTrainAI", "m_movementSoundName").String();
}
void GCTankTrainAI::SetMovementSoundName(std::string value) {
    SetSchemaValue(m_ptr, "CTankTrainAI", "m_movementSoundName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCTankTrainAI::GetTargetEntityName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTankTrainAI", "m_targetEntityName").String();
}
void GCTankTrainAI::SetTargetEntityName(std::string value) {
    SetSchemaValue(m_ptr, "CTankTrainAI", "m_targetEntityName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCTankTrainAI::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTankTrainAI::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCTankTrainAI::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCTankTrainAI::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTankTrainAI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTankTrainAI>("CTankTrainAI")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Train", &GCTankTrainAI::GetTrain, &GCTankTrainAI::SetTrain)
        .addProperty("TargetEntity", &GCTankTrainAI::GetTargetEntity, &GCTankTrainAI::SetTargetEntity)
        .addProperty("SoundPlaying", &GCTankTrainAI::GetSoundPlaying, &GCTankTrainAI::SetSoundPlaying)
        .addProperty("StartSoundName", &GCTankTrainAI::GetStartSoundName, &GCTankTrainAI::SetStartSoundName)
        .addProperty("EngineSoundName", &GCTankTrainAI::GetEngineSoundName, &GCTankTrainAI::SetEngineSoundName)
        .addProperty("MovementSoundName", &GCTankTrainAI::GetMovementSoundName, &GCTankTrainAI::SetMovementSoundName)
        .addProperty("TargetEntityName", &GCTankTrainAI::GetTargetEntityName, &GCTankTrainAI::SetTargetEntityName)
        .addProperty("Parent", &GCTankTrainAI::GetParent, &GCTankTrainAI::SetParent)
        .addFunction("ToPtr", &GCTankTrainAI::ToPtr)
        .addFunction("IsValid", &GCTankTrainAI::IsValid)
        .endClass();
}