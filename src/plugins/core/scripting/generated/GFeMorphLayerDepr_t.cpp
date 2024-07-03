#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeMorphLayerDepr_t::GFeMorphLayerDepr_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeMorphLayerDepr_t::GFeMorphLayerDepr_t(void *ptr) {
    m_ptr = ptr;
}
std::string GFeMorphLayerDepr_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "FeMorphLayerDepr_t", "m_Name").Get();
}
void GFeMorphLayerDepr_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "FeMorphLayerDepr_t", "m_Name", true, CUtlString(value.c_str()));
}
uint32_t GFeMorphLayerDepr_t::GetNameHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeMorphLayerDepr_t", "m_nNameHash");
}
void GFeMorphLayerDepr_t::SetNameHash(uint32_t value) {
    SetSchemaValue(m_ptr, "FeMorphLayerDepr_t", "m_nNameHash", true, value);
}
std::vector<uint16> GFeMorphLayerDepr_t::GetNodes() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "FeMorphLayerDepr_t", "m_Nodes"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GFeMorphLayerDepr_t::SetNodes(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "FeMorphLayerDepr_t", "m_Nodes", true, value);
}
std::vector<Vector> GFeMorphLayerDepr_t::GetInitPos() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "FeMorphLayerDepr_t", "m_InitPos"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GFeMorphLayerDepr_t::SetInitPos(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "FeMorphLayerDepr_t", "m_InitPos", true, value);
}
std::vector<float32> GFeMorphLayerDepr_t::GetGravity() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "FeMorphLayerDepr_t", "m_Gravity"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GFeMorphLayerDepr_t::SetGravity(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "FeMorphLayerDepr_t", "m_Gravity", true, value);
}
std::vector<float32> GFeMorphLayerDepr_t::GetGoalStrength() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "FeMorphLayerDepr_t", "m_GoalStrength"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GFeMorphLayerDepr_t::SetGoalStrength(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "FeMorphLayerDepr_t", "m_GoalStrength", true, value);
}
std::vector<float32> GFeMorphLayerDepr_t::GetGoalDamping() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "FeMorphLayerDepr_t", "m_GoalDamping"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GFeMorphLayerDepr_t::SetGoalDamping(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "FeMorphLayerDepr_t", "m_GoalDamping", true, value);
}
uint32_t GFeMorphLayerDepr_t::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeMorphLayerDepr_t", "m_nFlags");
}
void GFeMorphLayerDepr_t::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "FeMorphLayerDepr_t", "m_nFlags", true, value);
}
std::string GFeMorphLayerDepr_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeMorphLayerDepr_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeMorphLayerDepr_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeMorphLayerDepr_t>("FeMorphLayerDepr_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GFeMorphLayerDepr_t::GetName, &GFeMorphLayerDepr_t::SetName)
        .addProperty("NameHash", &GFeMorphLayerDepr_t::GetNameHash, &GFeMorphLayerDepr_t::SetNameHash)
        .addProperty("Nodes", &GFeMorphLayerDepr_t::GetNodes, &GFeMorphLayerDepr_t::SetNodes)
        .addProperty("InitPos", &GFeMorphLayerDepr_t::GetInitPos, &GFeMorphLayerDepr_t::SetInitPos)
        .addProperty("Gravity", &GFeMorphLayerDepr_t::GetGravity, &GFeMorphLayerDepr_t::SetGravity)
        .addProperty("GoalStrength", &GFeMorphLayerDepr_t::GetGoalStrength, &GFeMorphLayerDepr_t::SetGoalStrength)
        .addProperty("GoalDamping", &GFeMorphLayerDepr_t::GetGoalDamping, &GFeMorphLayerDepr_t::SetGoalDamping)
        .addProperty("Flags", &GFeMorphLayerDepr_t::GetFlags, &GFeMorphLayerDepr_t::SetFlags)
        .addFunction("ToPtr", &GFeMorphLayerDepr_t::ToPtr)
        .addFunction("IsValid", &GFeMorphLayerDepr_t::IsValid)
        .endClass();
}