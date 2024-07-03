#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVPhysXAggregateData_t::GVPhysXAggregateData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVPhysXAggregateData_t::GVPhysXAggregateData_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GVPhysXAggregateData_t::GetFlags() const {
    return GetSchemaValue<uint16_t>(m_ptr, "VPhysXAggregateData_t", "m_nFlags");
}
void GVPhysXAggregateData_t::SetFlags(uint16_t value) {
    SetSchemaValue(m_ptr, "VPhysXAggregateData_t", "m_nFlags", true, value);
}
uint16_t GVPhysXAggregateData_t::GetRefCounter() const {
    return GetSchemaValue<uint16_t>(m_ptr, "VPhysXAggregateData_t", "m_nRefCounter");
}
void GVPhysXAggregateData_t::SetRefCounter(uint16_t value) {
    SetSchemaValue(m_ptr, "VPhysXAggregateData_t", "m_nRefCounter", true, value);
}
std::vector<uint32> GVPhysXAggregateData_t::GetBonesHash() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "VPhysXAggregateData_t", "m_bonesHash"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXAggregateData_t::SetBonesHash(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "VPhysXAggregateData_t", "m_bonesHash", true, value);
}
std::vector<CUtlString> GVPhysXAggregateData_t::GetBoneNames() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "VPhysXAggregateData_t", "m_boneNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXAggregateData_t::SetBoneNames(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "VPhysXAggregateData_t", "m_boneNames", true, value);
}
std::vector<uint16> GVPhysXAggregateData_t::GetIndexNames() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "VPhysXAggregateData_t", "m_indexNames"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXAggregateData_t::SetIndexNames(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "VPhysXAggregateData_t", "m_indexNames", true, value);
}
std::vector<uint16> GVPhysXAggregateData_t::GetIndexHash() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "VPhysXAggregateData_t", "m_indexHash"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXAggregateData_t::SetIndexHash(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "VPhysXAggregateData_t", "m_indexHash", true, value);
}
std::vector<matrix3x4a_t> GVPhysXAggregateData_t::GetBindPose() const {
    CUtlVector<matrix3x4a_t>* vec = GetSchemaValue<CUtlVector<matrix3x4a_t>*>(m_ptr, "VPhysXAggregateData_t", "m_bindPose"); std::vector<matrix3x4a_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXAggregateData_t::SetBindPose(std::vector<matrix3x4a_t> value) {
    SetSchemaValueCUtlVector<matrix3x4a_t>(m_ptr, "VPhysXAggregateData_t", "m_bindPose", true, value);
}
std::vector<GVPhysXBodyPart_t> GVPhysXAggregateData_t::GetParts() const {
    CUtlVector<GVPhysXBodyPart_t>* vec = GetSchemaValue<CUtlVector<GVPhysXBodyPart_t>*>(m_ptr, "VPhysXAggregateData_t", "m_parts"); std::vector<GVPhysXBodyPart_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXAggregateData_t::SetParts(std::vector<GVPhysXBodyPart_t> value) {
    SetSchemaValueCUtlVector<GVPhysXBodyPart_t>(m_ptr, "VPhysXAggregateData_t", "m_parts", true, value);
}
std::vector<GVPhysXConstraint2_t> GVPhysXAggregateData_t::GetConstraints2() const {
    CUtlVector<GVPhysXConstraint2_t>* vec = GetSchemaValue<CUtlVector<GVPhysXConstraint2_t>*>(m_ptr, "VPhysXAggregateData_t", "m_constraints2"); std::vector<GVPhysXConstraint2_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXAggregateData_t::SetConstraints2(std::vector<GVPhysXConstraint2_t> value) {
    SetSchemaValueCUtlVector<GVPhysXConstraint2_t>(m_ptr, "VPhysXAggregateData_t", "m_constraints2", true, value);
}
std::vector<GVPhysXJoint_t> GVPhysXAggregateData_t::GetJoints() const {
    CUtlVector<GVPhysXJoint_t>* vec = GetSchemaValue<CUtlVector<GVPhysXJoint_t>*>(m_ptr, "VPhysXAggregateData_t", "m_joints"); std::vector<GVPhysXJoint_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXAggregateData_t::SetJoints(std::vector<GVPhysXJoint_t> value) {
    SetSchemaValueCUtlVector<GVPhysXJoint_t>(m_ptr, "VPhysXAggregateData_t", "m_joints", true, value);
}
GPhysFeModelDesc_t GVPhysXAggregateData_t::GetFeModel() const {
    GPhysFeModelDesc_t value(*GetSchemaValuePtr<void*>(m_ptr, "VPhysXAggregateData_t", "m_pFeModel"));
    return value;
}
void GVPhysXAggregateData_t::SetFeModel(GPhysFeModelDesc_t* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'FeModel' is not possible.\n");
}
std::vector<uint16> GVPhysXAggregateData_t::GetBoneParents() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "VPhysXAggregateData_t", "m_boneParents"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXAggregateData_t::SetBoneParents(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "VPhysXAggregateData_t", "m_boneParents", true, value);
}
std::vector<uint32> GVPhysXAggregateData_t::GetSurfacePropertyHashes() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "VPhysXAggregateData_t", "m_surfacePropertyHashes"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXAggregateData_t::SetSurfacePropertyHashes(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "VPhysXAggregateData_t", "m_surfacePropertyHashes", true, value);
}
std::vector<GVPhysXCollisionAttributes_t> GVPhysXAggregateData_t::GetCollisionAttributes() const {
    CUtlVector<GVPhysXCollisionAttributes_t>* vec = GetSchemaValue<CUtlVector<GVPhysXCollisionAttributes_t>*>(m_ptr, "VPhysXAggregateData_t", "m_collisionAttributes"); std::vector<GVPhysXCollisionAttributes_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXAggregateData_t::SetCollisionAttributes(std::vector<GVPhysXCollisionAttributes_t> value) {
    SetSchemaValueCUtlVector<GVPhysXCollisionAttributes_t>(m_ptr, "VPhysXAggregateData_t", "m_collisionAttributes", true, value);
}
std::vector<CUtlString> GVPhysXAggregateData_t::GetDebugPartNames() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "VPhysXAggregateData_t", "m_debugPartNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXAggregateData_t::SetDebugPartNames(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "VPhysXAggregateData_t", "m_debugPartNames", true, value);
}
std::string GVPhysXAggregateData_t::GetEmbeddedKeyvalues() const {
    return GetSchemaValue<CUtlString>(m_ptr, "VPhysXAggregateData_t", "m_embeddedKeyvalues").Get();
}
void GVPhysXAggregateData_t::SetEmbeddedKeyvalues(std::string value) {
    SetSchemaValue(m_ptr, "VPhysXAggregateData_t", "m_embeddedKeyvalues", true, CUtlString(value.c_str()));
}
std::string GVPhysXAggregateData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVPhysXAggregateData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVPhysXAggregateData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysXAggregateData_t>("VPhysXAggregateData_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Flags", &GVPhysXAggregateData_t::GetFlags, &GVPhysXAggregateData_t::SetFlags)
        .addProperty("RefCounter", &GVPhysXAggregateData_t::GetRefCounter, &GVPhysXAggregateData_t::SetRefCounter)
        .addProperty("BonesHash", &GVPhysXAggregateData_t::GetBonesHash, &GVPhysXAggregateData_t::SetBonesHash)
        .addProperty("BoneNames", &GVPhysXAggregateData_t::GetBoneNames, &GVPhysXAggregateData_t::SetBoneNames)
        .addProperty("IndexNames", &GVPhysXAggregateData_t::GetIndexNames, &GVPhysXAggregateData_t::SetIndexNames)
        .addProperty("IndexHash", &GVPhysXAggregateData_t::GetIndexHash, &GVPhysXAggregateData_t::SetIndexHash)
        .addProperty("BindPose", &GVPhysXAggregateData_t::GetBindPose, &GVPhysXAggregateData_t::SetBindPose)
        .addProperty("Parts", &GVPhysXAggregateData_t::GetParts, &GVPhysXAggregateData_t::SetParts)
        .addProperty("Constraints2", &GVPhysXAggregateData_t::GetConstraints2, &GVPhysXAggregateData_t::SetConstraints2)
        .addProperty("Joints", &GVPhysXAggregateData_t::GetJoints, &GVPhysXAggregateData_t::SetJoints)
        .addProperty("FeModel", &GVPhysXAggregateData_t::GetFeModel, &GVPhysXAggregateData_t::SetFeModel)
        .addProperty("BoneParents", &GVPhysXAggregateData_t::GetBoneParents, &GVPhysXAggregateData_t::SetBoneParents)
        .addProperty("SurfacePropertyHashes", &GVPhysXAggregateData_t::GetSurfacePropertyHashes, &GVPhysXAggregateData_t::SetSurfacePropertyHashes)
        .addProperty("CollisionAttributes", &GVPhysXAggregateData_t::GetCollisionAttributes, &GVPhysXAggregateData_t::SetCollisionAttributes)
        .addProperty("DebugPartNames", &GVPhysXAggregateData_t::GetDebugPartNames, &GVPhysXAggregateData_t::SetDebugPartNames)
        .addProperty("EmbeddedKeyvalues", &GVPhysXAggregateData_t::GetEmbeddedKeyvalues, &GVPhysXAggregateData_t::SetEmbeddedKeyvalues)
        .addFunction("ToPtr", &GVPhysXAggregateData_t::ToPtr)
        .addFunction("IsValid", &GVPhysXAggregateData_t::IsValid)
        .endClass();
}