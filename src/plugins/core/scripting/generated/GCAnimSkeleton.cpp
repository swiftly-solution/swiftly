#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimSkeleton::GCAnimSkeleton(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimSkeleton::GCAnimSkeleton(void *ptr) {
    m_ptr = ptr;
}
std::vector<CUtlString> GCAnimSkeleton::GetBoneNames() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CAnimSkeleton", "m_boneNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimSkeleton::SetBoneNames(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CAnimSkeleton", "m_boneNames", false, value);
}
std::vector<int32> GCAnimSkeleton::GetParents() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CAnimSkeleton", "m_parents"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimSkeleton::SetParents(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CAnimSkeleton", "m_parents", false, value);
}
std::vector<GCAnimFoot> GCAnimSkeleton::GetFeet() const {
    CUtlVector<GCAnimFoot>* vec = GetSchemaValue<CUtlVector<GCAnimFoot>*>(m_ptr, "CAnimSkeleton", "m_feet"); std::vector<GCAnimFoot> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimSkeleton::SetFeet(std::vector<GCAnimFoot> value) {
    SetSchemaValueCUtlVector<GCAnimFoot>(m_ptr, "CAnimSkeleton", "m_feet", false, value);
}
std::vector<CUtlString> GCAnimSkeleton::GetMorphNames() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CAnimSkeleton", "m_morphNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimSkeleton::SetMorphNames(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CAnimSkeleton", "m_morphNames", false, value);
}
std::vector<int32> GCAnimSkeleton::GetLodBoneCounts() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CAnimSkeleton", "m_lodBoneCounts"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimSkeleton::SetLodBoneCounts(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CAnimSkeleton", "m_lodBoneCounts", false, value);
}
std::string GCAnimSkeleton::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimSkeleton::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimSkeleton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimSkeleton>("CAnimSkeleton")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneNames", &GCAnimSkeleton::GetBoneNames, &GCAnimSkeleton::SetBoneNames)
        .addProperty("Parents", &GCAnimSkeleton::GetParents, &GCAnimSkeleton::SetParents)
        .addProperty("Feet", &GCAnimSkeleton::GetFeet, &GCAnimSkeleton::SetFeet)
        .addProperty("MorphNames", &GCAnimSkeleton::GetMorphNames, &GCAnimSkeleton::SetMorphNames)
        .addProperty("LodBoneCounts", &GCAnimSkeleton::GetLodBoneCounts, &GCAnimSkeleton::SetLodBoneCounts)
        .addFunction("ToPtr", &GCAnimSkeleton::ToPtr)
        .addFunction("IsValid", &GCAnimSkeleton::IsValid)
        .endClass();
}