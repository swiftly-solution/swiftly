#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNavHullVData::GCNavHullVData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNavHullVData::GCNavHullVData(void *ptr) {
    m_ptr = ptr;
}
bool GCNavHullVData::GetAgentEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CNavHullVData", "m_bAgentEnabled");
}
void GCNavHullVData::SetAgentEnabled(bool value) {
    SetSchemaValue(m_ptr, "CNavHullVData", "m_bAgentEnabled", false, value);
}
float GCNavHullVData::GetAgentRadius() const {
    return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentRadius");
}
void GCNavHullVData::SetAgentRadius(float value) {
    SetSchemaValue(m_ptr, "CNavHullVData", "m_agentRadius", false, value);
}
float GCNavHullVData::GetAgentHeight() const {
    return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentHeight");
}
void GCNavHullVData::SetAgentHeight(float value) {
    SetSchemaValue(m_ptr, "CNavHullVData", "m_agentHeight", false, value);
}
bool GCNavHullVData::GetAgentShortHeightEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CNavHullVData", "m_agentShortHeightEnabled");
}
void GCNavHullVData::SetAgentShortHeightEnabled(bool value) {
    SetSchemaValue(m_ptr, "CNavHullVData", "m_agentShortHeightEnabled", false, value);
}
float GCNavHullVData::GetAgentShortHeight() const {
    return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentShortHeight");
}
void GCNavHullVData::SetAgentShortHeight(float value) {
    SetSchemaValue(m_ptr, "CNavHullVData", "m_agentShortHeight", false, value);
}
float GCNavHullVData::GetAgentMaxClimb() const {
    return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentMaxClimb");
}
void GCNavHullVData::SetAgentMaxClimb(float value) {
    SetSchemaValue(m_ptr, "CNavHullVData", "m_agentMaxClimb", false, value);
}
int32_t GCNavHullVData::GetAgentMaxSlope() const {
    return GetSchemaValue<int32_t>(m_ptr, "CNavHullVData", "m_agentMaxSlope");
}
void GCNavHullVData::SetAgentMaxSlope(int32_t value) {
    SetSchemaValue(m_ptr, "CNavHullVData", "m_agentMaxSlope", false, value);
}
float GCNavHullVData::GetAgentMaxJumpDownDist() const {
    return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentMaxJumpDownDist");
}
void GCNavHullVData::SetAgentMaxJumpDownDist(float value) {
    SetSchemaValue(m_ptr, "CNavHullVData", "m_agentMaxJumpDownDist", false, value);
}
float GCNavHullVData::GetAgentMaxJumpHorizDistBase() const {
    return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentMaxJumpHorizDistBase");
}
void GCNavHullVData::SetAgentMaxJumpHorizDistBase(float value) {
    SetSchemaValue(m_ptr, "CNavHullVData", "m_agentMaxJumpHorizDistBase", false, value);
}
float GCNavHullVData::GetAgentMaxJumpUpDist() const {
    return GetSchemaValue<float>(m_ptr, "CNavHullVData", "m_agentMaxJumpUpDist");
}
void GCNavHullVData::SetAgentMaxJumpUpDist(float value) {
    SetSchemaValue(m_ptr, "CNavHullVData", "m_agentMaxJumpUpDist", false, value);
}
int32_t GCNavHullVData::GetAgentBorderErosion() const {
    return GetSchemaValue<int32_t>(m_ptr, "CNavHullVData", "m_agentBorderErosion");
}
void GCNavHullVData::SetAgentBorderErosion(int32_t value) {
    SetSchemaValue(m_ptr, "CNavHullVData", "m_agentBorderErosion", false, value);
}
std::string GCNavHullVData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNavHullVData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNavHullVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavHullVData>("CNavHullVData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AgentEnabled", &GCNavHullVData::GetAgentEnabled, &GCNavHullVData::SetAgentEnabled)
        .addProperty("AgentRadius", &GCNavHullVData::GetAgentRadius, &GCNavHullVData::SetAgentRadius)
        .addProperty("AgentHeight", &GCNavHullVData::GetAgentHeight, &GCNavHullVData::SetAgentHeight)
        .addProperty("AgentShortHeightEnabled", &GCNavHullVData::GetAgentShortHeightEnabled, &GCNavHullVData::SetAgentShortHeightEnabled)
        .addProperty("AgentShortHeight", &GCNavHullVData::GetAgentShortHeight, &GCNavHullVData::SetAgentShortHeight)
        .addProperty("AgentMaxClimb", &GCNavHullVData::GetAgentMaxClimb, &GCNavHullVData::SetAgentMaxClimb)
        .addProperty("AgentMaxSlope", &GCNavHullVData::GetAgentMaxSlope, &GCNavHullVData::SetAgentMaxSlope)
        .addProperty("AgentMaxJumpDownDist", &GCNavHullVData::GetAgentMaxJumpDownDist, &GCNavHullVData::SetAgentMaxJumpDownDist)
        .addProperty("AgentMaxJumpHorizDistBase", &GCNavHullVData::GetAgentMaxJumpHorizDistBase, &GCNavHullVData::SetAgentMaxJumpHorizDistBase)
        .addProperty("AgentMaxJumpUpDist", &GCNavHullVData::GetAgentMaxJumpUpDist, &GCNavHullVData::SetAgentMaxJumpUpDist)
        .addProperty("AgentBorderErosion", &GCNavHullVData::GetAgentBorderErosion, &GCNavHullVData::SetAgentBorderErosion)
        .addFunction("ToPtr", &GCNavHullVData::ToPtr)
        .addFunction("IsValid", &GCNavHullVData::IsValid)
        .endClass();
}