#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootCycleDefinition::GCFootCycleDefinition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootCycleDefinition::GCFootCycleDefinition(void *ptr) {
    m_ptr = ptr;
}
Vector GCFootCycleDefinition::GetStancePositionMS() const {
    return GetSchemaValue<Vector>(m_ptr, "CFootCycleDefinition", "m_vStancePositionMS");
}
void GCFootCycleDefinition::SetStancePositionMS(Vector value) {
    SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_vStancePositionMS", false, value);
}
Vector GCFootCycleDefinition::GetMidpointPositionMS() const {
    return GetSchemaValue<Vector>(m_ptr, "CFootCycleDefinition", "m_vMidpointPositionMS");
}
void GCFootCycleDefinition::SetMidpointPositionMS(Vector value) {
    SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_vMidpointPositionMS", false, value);
}
float GCFootCycleDefinition::GetStanceDirectionMS() const {
    return GetSchemaValue<float>(m_ptr, "CFootCycleDefinition", "m_flStanceDirectionMS");
}
void GCFootCycleDefinition::SetStanceDirectionMS(float value) {
    SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_flStanceDirectionMS", false, value);
}
Vector GCFootCycleDefinition::GetToStrideStartPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CFootCycleDefinition", "m_vToStrideStartPos");
}
void GCFootCycleDefinition::SetToStrideStartPos(Vector value) {
    SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_vToStrideStartPos", false, value);
}
GCAnimCycle GCFootCycleDefinition::GetStanceCycle() const {
    GCAnimCycle value(GetSchemaPtr(m_ptr, "CFootCycleDefinition", "m_stanceCycle"));
    return value;
}
void GCFootCycleDefinition::SetStanceCycle(GCAnimCycle value) {
    SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_stanceCycle", false, value);
}
GCFootCycle GCFootCycleDefinition::GetFootLiftCycle() const {
    GCFootCycle value(GetSchemaPtr(m_ptr, "CFootCycleDefinition", "m_footLiftCycle"));
    return value;
}
void GCFootCycleDefinition::SetFootLiftCycle(GCFootCycle value) {
    SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_footLiftCycle", false, value);
}
GCFootCycle GCFootCycleDefinition::GetFootOffCycle() const {
    GCFootCycle value(GetSchemaPtr(m_ptr, "CFootCycleDefinition", "m_footOffCycle"));
    return value;
}
void GCFootCycleDefinition::SetFootOffCycle(GCFootCycle value) {
    SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_footOffCycle", false, value);
}
GCFootCycle GCFootCycleDefinition::GetFootStrikeCycle() const {
    GCFootCycle value(GetSchemaPtr(m_ptr, "CFootCycleDefinition", "m_footStrikeCycle"));
    return value;
}
void GCFootCycleDefinition::SetFootStrikeCycle(GCFootCycle value) {
    SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_footStrikeCycle", false, value);
}
GCFootCycle GCFootCycleDefinition::GetFootLandCycle() const {
    GCFootCycle value(GetSchemaPtr(m_ptr, "CFootCycleDefinition", "m_footLandCycle"));
    return value;
}
void GCFootCycleDefinition::SetFootLandCycle(GCFootCycle value) {
    SetSchemaValue(m_ptr, "CFootCycleDefinition", "m_footLandCycle", false, value);
}
std::string GCFootCycleDefinition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootCycleDefinition::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFootCycleDefinition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootCycleDefinition>("CFootCycleDefinition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StancePositionMS", &GCFootCycleDefinition::GetStancePositionMS, &GCFootCycleDefinition::SetStancePositionMS)
        .addProperty("MidpointPositionMS", &GCFootCycleDefinition::GetMidpointPositionMS, &GCFootCycleDefinition::SetMidpointPositionMS)
        .addProperty("StanceDirectionMS", &GCFootCycleDefinition::GetStanceDirectionMS, &GCFootCycleDefinition::SetStanceDirectionMS)
        .addProperty("ToStrideStartPos", &GCFootCycleDefinition::GetToStrideStartPos, &GCFootCycleDefinition::SetToStrideStartPos)
        .addProperty("StanceCycle", &GCFootCycleDefinition::GetStanceCycle, &GCFootCycleDefinition::SetStanceCycle)
        .addProperty("FootLiftCycle", &GCFootCycleDefinition::GetFootLiftCycle, &GCFootCycleDefinition::SetFootLiftCycle)
        .addProperty("FootOffCycle", &GCFootCycleDefinition::GetFootOffCycle, &GCFootCycleDefinition::SetFootOffCycle)
        .addProperty("FootStrikeCycle", &GCFootCycleDefinition::GetFootStrikeCycle, &GCFootCycleDefinition::SetFootStrikeCycle)
        .addProperty("FootLandCycle", &GCFootCycleDefinition::GetFootLandCycle, &GCFootCycleDefinition::SetFootLandCycle)
        .addFunction("ToPtr", &GCFootCycleDefinition::ToPtr)
        .addFunction("IsValid", &GCFootCycleDefinition::IsValid)
        .endClass();
}