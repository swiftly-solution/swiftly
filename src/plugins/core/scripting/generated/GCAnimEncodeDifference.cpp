#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimEncodeDifference::GCAnimEncodeDifference(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimEncodeDifference::GCAnimEncodeDifference(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCAnimBoneDifference> GCAnimEncodeDifference::GetBoneArray() const {
    CUtlVector<GCAnimBoneDifference>* vec = GetSchemaValue<CUtlVector<GCAnimBoneDifference>*>(m_ptr, "CAnimEncodeDifference", "m_boneArray"); std::vector<GCAnimBoneDifference> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimEncodeDifference::SetBoneArray(std::vector<GCAnimBoneDifference> value) {
    SetSchemaValueCUtlVector<GCAnimBoneDifference>(m_ptr, "CAnimEncodeDifference", "m_boneArray", false, value);
}
std::vector<GCAnimMorphDifference> GCAnimEncodeDifference::GetMorphArray() const {
    CUtlVector<GCAnimMorphDifference>* vec = GetSchemaValue<CUtlVector<GCAnimMorphDifference>*>(m_ptr, "CAnimEncodeDifference", "m_morphArray"); std::vector<GCAnimMorphDifference> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimEncodeDifference::SetMorphArray(std::vector<GCAnimMorphDifference> value) {
    SetSchemaValueCUtlVector<GCAnimMorphDifference>(m_ptr, "CAnimEncodeDifference", "m_morphArray", false, value);
}
std::vector<GCAnimUserDifference> GCAnimEncodeDifference::GetUserArray() const {
    CUtlVector<GCAnimUserDifference>* vec = GetSchemaValue<CUtlVector<GCAnimUserDifference>*>(m_ptr, "CAnimEncodeDifference", "m_userArray"); std::vector<GCAnimUserDifference> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimEncodeDifference::SetUserArray(std::vector<GCAnimUserDifference> value) {
    SetSchemaValueCUtlVector<GCAnimUserDifference>(m_ptr, "CAnimEncodeDifference", "m_userArray", false, value);
}
std::vector<uint8> GCAnimEncodeDifference::GetHasRotationBitArray() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CAnimEncodeDifference", "m_bHasRotationBitArray"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimEncodeDifference::SetHasRotationBitArray(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "CAnimEncodeDifference", "m_bHasRotationBitArray", false, value);
}
std::vector<uint8> GCAnimEncodeDifference::GetHasMovementBitArray() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CAnimEncodeDifference", "m_bHasMovementBitArray"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimEncodeDifference::SetHasMovementBitArray(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "CAnimEncodeDifference", "m_bHasMovementBitArray", false, value);
}
std::vector<uint8> GCAnimEncodeDifference::GetHasMorphBitArray() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CAnimEncodeDifference", "m_bHasMorphBitArray"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimEncodeDifference::SetHasMorphBitArray(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "CAnimEncodeDifference", "m_bHasMorphBitArray", false, value);
}
std::vector<uint8> GCAnimEncodeDifference::GetHasUserBitArray() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CAnimEncodeDifference", "m_bHasUserBitArray"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimEncodeDifference::SetHasUserBitArray(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "CAnimEncodeDifference", "m_bHasUserBitArray", false, value);
}
std::string GCAnimEncodeDifference::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimEncodeDifference::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimEncodeDifference(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEncodeDifference>("CAnimEncodeDifference")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneArray", &GCAnimEncodeDifference::GetBoneArray, &GCAnimEncodeDifference::SetBoneArray)
        .addProperty("MorphArray", &GCAnimEncodeDifference::GetMorphArray, &GCAnimEncodeDifference::SetMorphArray)
        .addProperty("UserArray", &GCAnimEncodeDifference::GetUserArray, &GCAnimEncodeDifference::SetUserArray)
        .addProperty("HasRotationBitArray", &GCAnimEncodeDifference::GetHasRotationBitArray, &GCAnimEncodeDifference::SetHasRotationBitArray)
        .addProperty("HasMovementBitArray", &GCAnimEncodeDifference::GetHasMovementBitArray, &GCAnimEncodeDifference::SetHasMovementBitArray)
        .addProperty("HasMorphBitArray", &GCAnimEncodeDifference::GetHasMorphBitArray, &GCAnimEncodeDifference::SetHasMorphBitArray)
        .addProperty("HasUserBitArray", &GCAnimEncodeDifference::GetHasUserBitArray, &GCAnimEncodeDifference::SetHasUserBitArray)
        .addFunction("ToPtr", &GCAnimEncodeDifference::ToPtr)
        .addFunction("IsValid", &GCAnimEncodeDifference::IsValid)
        .endClass();
}