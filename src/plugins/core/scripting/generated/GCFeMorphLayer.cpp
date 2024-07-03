#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFeMorphLayer::GCFeMorphLayer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFeMorphLayer::GCFeMorphLayer(void *ptr) {
    m_ptr = ptr;
}
std::string GCFeMorphLayer::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFeMorphLayer", "m_Name").Get();
}
void GCFeMorphLayer::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CFeMorphLayer", "m_Name", false, CUtlString(value.c_str()));
}
uint32_t GCFeMorphLayer::GetNameHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CFeMorphLayer", "m_nNameHash");
}
void GCFeMorphLayer::SetNameHash(uint32_t value) {
    SetSchemaValue(m_ptr, "CFeMorphLayer", "m_nNameHash", false, value);
}
std::vector<uint16> GCFeMorphLayer::GetNodes() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "CFeMorphLayer", "m_Nodes"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFeMorphLayer::SetNodes(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "CFeMorphLayer", "m_Nodes", false, value);
}
std::vector<Vector> GCFeMorphLayer::GetInitPos() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CFeMorphLayer", "m_InitPos"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFeMorphLayer::SetInitPos(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CFeMorphLayer", "m_InitPos", false, value);
}
std::vector<float32> GCFeMorphLayer::GetGravity() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CFeMorphLayer", "m_Gravity"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFeMorphLayer::SetGravity(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CFeMorphLayer", "m_Gravity", false, value);
}
std::vector<float32> GCFeMorphLayer::GetGoalStrength() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CFeMorphLayer", "m_GoalStrength"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFeMorphLayer::SetGoalStrength(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CFeMorphLayer", "m_GoalStrength", false, value);
}
std::vector<float32> GCFeMorphLayer::GetGoalDamping() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CFeMorphLayer", "m_GoalDamping"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFeMorphLayer::SetGoalDamping(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CFeMorphLayer", "m_GoalDamping", false, value);
}
std::string GCFeMorphLayer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFeMorphLayer::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFeMorphLayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFeMorphLayer>("CFeMorphLayer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCFeMorphLayer::GetName, &GCFeMorphLayer::SetName)
        .addProperty("NameHash", &GCFeMorphLayer::GetNameHash, &GCFeMorphLayer::SetNameHash)
        .addProperty("Nodes", &GCFeMorphLayer::GetNodes, &GCFeMorphLayer::SetNodes)
        .addProperty("InitPos", &GCFeMorphLayer::GetInitPos, &GCFeMorphLayer::SetInitPos)
        .addProperty("Gravity", &GCFeMorphLayer::GetGravity, &GCFeMorphLayer::SetGravity)
        .addProperty("GoalStrength", &GCFeMorphLayer::GetGoalStrength, &GCFeMorphLayer::SetGoalStrength)
        .addProperty("GoalDamping", &GCFeMorphLayer::GetGoalDamping, &GCFeMorphLayer::SetGoalDamping)
        .addFunction("ToPtr", &GCFeMorphLayer::ToPtr)
        .addFunction("IsValid", &GCFeMorphLayer::IsValid)
        .endClass();
}