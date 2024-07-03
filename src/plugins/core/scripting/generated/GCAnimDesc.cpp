#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimDesc::GCAnimDesc(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimDesc::GCAnimDesc(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCAnimDesc::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimDesc", "m_name");
}
void GCAnimDesc::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimDesc", "m_name", false, value);
}
GCAnimDesc_Flag GCAnimDesc::GetFlags() const {
    GCAnimDesc_Flag value(GetSchemaPtr(m_ptr, "CAnimDesc", "m_flags"));
    return value;
}
void GCAnimDesc::SetFlags(GCAnimDesc_Flag value) {
    SetSchemaValue(m_ptr, "CAnimDesc", "m_flags", false, value);
}
float GCAnimDesc::GetFps() const {
    return GetSchemaValue<float>(m_ptr, "CAnimDesc", "fps");
}
void GCAnimDesc::SetFps(float value) {
    SetSchemaValue(m_ptr, "CAnimDesc", "fps", false, value);
}
GCAnimEncodedFrames GCAnimDesc::GetData() const {
    GCAnimEncodedFrames value(GetSchemaPtr(m_ptr, "CAnimDesc", "m_Data"));
    return value;
}
void GCAnimDesc::SetData(GCAnimEncodedFrames value) {
    SetSchemaValue(m_ptr, "CAnimDesc", "m_Data", false, value);
}
std::vector<GCAnimMovement> GCAnimDesc::GetMovementArray() const {
    CUtlVector<GCAnimMovement>* vec = GetSchemaValue<CUtlVector<GCAnimMovement>*>(m_ptr, "CAnimDesc", "m_movementArray"); std::vector<GCAnimMovement> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimDesc::SetMovementArray(std::vector<GCAnimMovement> value) {
    SetSchemaValueCUtlVector<GCAnimMovement>(m_ptr, "CAnimDesc", "m_movementArray", false, value);
}
std::vector<GCAnimEventDefinition> GCAnimDesc::GetEventArray() const {
    CUtlVector<GCAnimEventDefinition>* vec = GetSchemaValue<CUtlVector<GCAnimEventDefinition>*>(m_ptr, "CAnimDesc", "m_eventArray"); std::vector<GCAnimEventDefinition> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimDesc::SetEventArray(std::vector<GCAnimEventDefinition> value) {
    SetSchemaValueCUtlVector<GCAnimEventDefinition>(m_ptr, "CAnimDesc", "m_eventArray", false, value);
}
std::vector<GCAnimActivity> GCAnimDesc::GetActivityArray() const {
    CUtlVector<GCAnimActivity>* vec = GetSchemaValue<CUtlVector<GCAnimActivity>*>(m_ptr, "CAnimDesc", "m_activityArray"); std::vector<GCAnimActivity> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimDesc::SetActivityArray(std::vector<GCAnimActivity> value) {
    SetSchemaValueCUtlVector<GCAnimActivity>(m_ptr, "CAnimDesc", "m_activityArray", false, value);
}
std::vector<GCAnimLocalHierarchy> GCAnimDesc::GetHierarchyArray() const {
    CUtlVector<GCAnimLocalHierarchy>* vec = GetSchemaValue<CUtlVector<GCAnimLocalHierarchy>*>(m_ptr, "CAnimDesc", "m_hierarchyArray"); std::vector<GCAnimLocalHierarchy> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimDesc::SetHierarchyArray(std::vector<GCAnimLocalHierarchy> value) {
    SetSchemaValueCUtlVector<GCAnimLocalHierarchy>(m_ptr, "CAnimDesc", "m_hierarchyArray", false, value);
}
float GCAnimDesc::GetFramestalltime() const {
    return GetSchemaValue<float>(m_ptr, "CAnimDesc", "framestalltime");
}
void GCAnimDesc::SetFramestalltime(float value) {
    SetSchemaValue(m_ptr, "CAnimDesc", "framestalltime", false, value);
}
Vector GCAnimDesc::GetRootMin() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimDesc", "m_vecRootMin");
}
void GCAnimDesc::SetRootMin(Vector value) {
    SetSchemaValue(m_ptr, "CAnimDesc", "m_vecRootMin", false, value);
}
Vector GCAnimDesc::GetRootMax() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimDesc", "m_vecRootMax");
}
void GCAnimDesc::SetRootMax(Vector value) {
    SetSchemaValue(m_ptr, "CAnimDesc", "m_vecRootMax", false, value);
}
std::vector<Vector> GCAnimDesc::GetBoneWorldMin() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CAnimDesc", "m_vecBoneWorldMin"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimDesc::SetBoneWorldMin(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CAnimDesc", "m_vecBoneWorldMin", false, value);
}
std::vector<Vector> GCAnimDesc::GetBoneWorldMax() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CAnimDesc", "m_vecBoneWorldMax"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimDesc::SetBoneWorldMax(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CAnimDesc", "m_vecBoneWorldMax", false, value);
}
GCAnimSequenceParams GCAnimDesc::GetSequenceParams() const {
    GCAnimSequenceParams value(GetSchemaPtr(m_ptr, "CAnimDesc", "m_sequenceParams"));
    return value;
}
void GCAnimDesc::SetSequenceParams(GCAnimSequenceParams value) {
    SetSchemaValue(m_ptr, "CAnimDesc", "m_sequenceParams", false, value);
}
std::string GCAnimDesc::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimDesc::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimDesc>("CAnimDesc")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAnimDesc::GetName, &GCAnimDesc::SetName)
        .addProperty("Flags", &GCAnimDesc::GetFlags, &GCAnimDesc::SetFlags)
        .addProperty("Fps", &GCAnimDesc::GetFps, &GCAnimDesc::SetFps)
        .addProperty("Data", &GCAnimDesc::GetData, &GCAnimDesc::SetData)
        .addProperty("MovementArray", &GCAnimDesc::GetMovementArray, &GCAnimDesc::SetMovementArray)
        .addProperty("EventArray", &GCAnimDesc::GetEventArray, &GCAnimDesc::SetEventArray)
        .addProperty("ActivityArray", &GCAnimDesc::GetActivityArray, &GCAnimDesc::SetActivityArray)
        .addProperty("HierarchyArray", &GCAnimDesc::GetHierarchyArray, &GCAnimDesc::SetHierarchyArray)
        .addProperty("Framestalltime", &GCAnimDesc::GetFramestalltime, &GCAnimDesc::SetFramestalltime)
        .addProperty("RootMin", &GCAnimDesc::GetRootMin, &GCAnimDesc::SetRootMin)
        .addProperty("RootMax", &GCAnimDesc::GetRootMax, &GCAnimDesc::SetRootMax)
        .addProperty("BoneWorldMin", &GCAnimDesc::GetBoneWorldMin, &GCAnimDesc::SetBoneWorldMin)
        .addProperty("BoneWorldMax", &GCAnimDesc::GetBoneWorldMax, &GCAnimDesc::SetBoneWorldMax)
        .addProperty("SequenceParams", &GCAnimDesc::GetSequenceParams, &GCAnimDesc::SetSequenceParams)
        .addFunction("ToPtr", &GCAnimDesc::ToPtr)
        .addFunction("IsValid", &GCAnimDesc::IsValid)
        .endClass();
}