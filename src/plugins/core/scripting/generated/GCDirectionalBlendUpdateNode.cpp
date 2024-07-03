#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDirectionalBlendUpdateNode::GCDirectionalBlendUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDirectionalBlendUpdateNode::GCDirectionalBlendUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GCAnimInputDamping GCDirectionalBlendUpdateNode::GetDamping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "CDirectionalBlendUpdateNode", "m_damping"));
    return value;
}
void GCDirectionalBlendUpdateNode::SetDamping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_damping", false, value);
}
uint64_t GCDirectionalBlendUpdateNode::GetBlendValueSource() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CDirectionalBlendUpdateNode", "m_blendValueSource");
}
void GCDirectionalBlendUpdateNode::SetBlendValueSource(uint64_t value) {
    SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_blendValueSource", false, value);
}
GCAnimParamHandle GCDirectionalBlendUpdateNode::GetParamIndex() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CDirectionalBlendUpdateNode", "m_paramIndex"));
    return value;
}
void GCDirectionalBlendUpdateNode::SetParamIndex(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_paramIndex", false, value);
}
float GCDirectionalBlendUpdateNode::GetPlaybackSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CDirectionalBlendUpdateNode", "m_playbackSpeed");
}
void GCDirectionalBlendUpdateNode::SetPlaybackSpeed(float value) {
    SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_playbackSpeed", false, value);
}
float GCDirectionalBlendUpdateNode::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CDirectionalBlendUpdateNode", "m_duration");
}
void GCDirectionalBlendUpdateNode::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_duration", false, value);
}
bool GCDirectionalBlendUpdateNode::GetLoop() const {
    return GetSchemaValue<bool>(m_ptr, "CDirectionalBlendUpdateNode", "m_bLoop");
}
void GCDirectionalBlendUpdateNode::SetLoop(bool value) {
    SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_bLoop", false, value);
}
bool GCDirectionalBlendUpdateNode::GetLockBlendOnReset() const {
    return GetSchemaValue<bool>(m_ptr, "CDirectionalBlendUpdateNode", "m_bLockBlendOnReset");
}
void GCDirectionalBlendUpdateNode::SetLockBlendOnReset(bool value) {
    SetSchemaValue(m_ptr, "CDirectionalBlendUpdateNode", "m_bLockBlendOnReset", false, value);
}
std::string GCDirectionalBlendUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDirectionalBlendUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCLeafUpdateNode GCDirectionalBlendUpdateNode::GetParent() const {
    GCLeafUpdateNode value(m_ptr);
    return value;
}
void GCDirectionalBlendUpdateNode::SetParent(GCLeafUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDirectionalBlendUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDirectionalBlendUpdateNode>("CDirectionalBlendUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Damping", &GCDirectionalBlendUpdateNode::GetDamping, &GCDirectionalBlendUpdateNode::SetDamping)
        .addProperty("BlendValueSource", &GCDirectionalBlendUpdateNode::GetBlendValueSource, &GCDirectionalBlendUpdateNode::SetBlendValueSource)
        .addProperty("ParamIndex", &GCDirectionalBlendUpdateNode::GetParamIndex, &GCDirectionalBlendUpdateNode::SetParamIndex)
        .addProperty("PlaybackSpeed", &GCDirectionalBlendUpdateNode::GetPlaybackSpeed, &GCDirectionalBlendUpdateNode::SetPlaybackSpeed)
        .addProperty("Duration", &GCDirectionalBlendUpdateNode::GetDuration, &GCDirectionalBlendUpdateNode::SetDuration)
        .addProperty("Loop", &GCDirectionalBlendUpdateNode::GetLoop, &GCDirectionalBlendUpdateNode::SetLoop)
        .addProperty("LockBlendOnReset", &GCDirectionalBlendUpdateNode::GetLockBlendOnReset, &GCDirectionalBlendUpdateNode::SetLockBlendOnReset)
        .addProperty("Parent", &GCDirectionalBlendUpdateNode::GetParent, &GCDirectionalBlendUpdateNode::SetParent)
        .addFunction("ToPtr", &GCDirectionalBlendUpdateNode::ToPtr)
        .addFunction("IsValid", &GCDirectionalBlendUpdateNode::IsValid)
        .endClass();
}