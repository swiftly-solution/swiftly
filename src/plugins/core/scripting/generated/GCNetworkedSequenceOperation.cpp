#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNetworkedSequenceOperation::GCNetworkedSequenceOperation(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNetworkedSequenceOperation::GCNetworkedSequenceOperation(void *ptr) {
    m_ptr = ptr;
}
float GCNetworkedSequenceOperation::GetPrevCycle() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkedSequenceOperation", "m_flPrevCycle");
}
void GCNetworkedSequenceOperation::SetPrevCycle(float value) {
    SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_flPrevCycle", false, value);
}
float GCNetworkedSequenceOperation::GetCycle() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkedSequenceOperation", "m_flCycle");
}
void GCNetworkedSequenceOperation::SetCycle(float value) {
    SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_flCycle", false, value);
}
float GCNetworkedSequenceOperation::GetWeight() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkedSequenceOperation", "m_flWeight");
}
void GCNetworkedSequenceOperation::SetWeight(float value) {
    SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_flWeight", false, value);
}
bool GCNetworkedSequenceOperation::GetSequenceChangeNetworked() const {
    return GetSchemaValue<bool>(m_ptr, "CNetworkedSequenceOperation", "m_bSequenceChangeNetworked");
}
void GCNetworkedSequenceOperation::SetSequenceChangeNetworked(bool value) {
    SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_bSequenceChangeNetworked", false, value);
}
bool GCNetworkedSequenceOperation::GetDiscontinuity() const {
    return GetSchemaValue<bool>(m_ptr, "CNetworkedSequenceOperation", "m_bDiscontinuity");
}
void GCNetworkedSequenceOperation::SetDiscontinuity(bool value) {
    SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_bDiscontinuity", false, value);
}
float GCNetworkedSequenceOperation::GetPrevCycleFromDiscontinuity() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkedSequenceOperation", "m_flPrevCycleFromDiscontinuity");
}
void GCNetworkedSequenceOperation::SetPrevCycleFromDiscontinuity(float value) {
    SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_flPrevCycleFromDiscontinuity", false, value);
}
float GCNetworkedSequenceOperation::GetPrevCycleForAnimEventDetection() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkedSequenceOperation", "m_flPrevCycleForAnimEventDetection");
}
void GCNetworkedSequenceOperation::SetPrevCycleForAnimEventDetection(float value) {
    SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_flPrevCycleForAnimEventDetection", false, value);
}
std::string GCNetworkedSequenceOperation::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNetworkedSequenceOperation::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNetworkedSequenceOperation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkedSequenceOperation>("CNetworkedSequenceOperation")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PrevCycle", &GCNetworkedSequenceOperation::GetPrevCycle, &GCNetworkedSequenceOperation::SetPrevCycle)
        .addProperty("Cycle", &GCNetworkedSequenceOperation::GetCycle, &GCNetworkedSequenceOperation::SetCycle)
        .addProperty("Weight", &GCNetworkedSequenceOperation::GetWeight, &GCNetworkedSequenceOperation::SetWeight)
        .addProperty("SequenceChangeNetworked", &GCNetworkedSequenceOperation::GetSequenceChangeNetworked, &GCNetworkedSequenceOperation::SetSequenceChangeNetworked)
        .addProperty("Discontinuity", &GCNetworkedSequenceOperation::GetDiscontinuity, &GCNetworkedSequenceOperation::SetDiscontinuity)
        .addProperty("PrevCycleFromDiscontinuity", &GCNetworkedSequenceOperation::GetPrevCycleFromDiscontinuity, &GCNetworkedSequenceOperation::SetPrevCycleFromDiscontinuity)
        .addProperty("PrevCycleForAnimEventDetection", &GCNetworkedSequenceOperation::GetPrevCycleForAnimEventDetection, &GCNetworkedSequenceOperation::SetPrevCycleForAnimEventDetection)
        .addFunction("ToPtr", &GCNetworkedSequenceOperation::ToPtr)
        .addFunction("IsValid", &GCNetworkedSequenceOperation::IsValid)
        .endClass();
}