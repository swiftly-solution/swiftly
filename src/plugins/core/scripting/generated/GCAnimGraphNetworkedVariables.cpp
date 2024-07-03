#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimGraphNetworkedVariables::GCAnimGraphNetworkedVariables(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimGraphNetworkedVariables::GCAnimGraphNetworkedVariables(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint32> GCAnimGraphNetworkedVariables::GetPredNetBoolVariables() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetBoolVariables"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetPredNetBoolVariables(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetBoolVariables", false, value);
}
std::vector<uint8> GCAnimGraphNetworkedVariables::GetPredNetByteVariables() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetByteVariables"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetPredNetByteVariables(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetByteVariables", false, value);
}
std::vector<uint16> GCAnimGraphNetworkedVariables::GetPredNetUInt16Variables() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetUInt16Variables"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetPredNetUInt16Variables(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetUInt16Variables", false, value);
}
std::vector<int32> GCAnimGraphNetworkedVariables::GetPredNetIntVariables() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetIntVariables"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetPredNetIntVariables(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetIntVariables", false, value);
}
std::vector<uint32> GCAnimGraphNetworkedVariables::GetPredNetUInt32Variables() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetUInt32Variables"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetPredNetUInt32Variables(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetUInt32Variables", false, value);
}
std::vector<uint64> GCAnimGraphNetworkedVariables::GetPredNetUInt64Variables() const {
    CUtlVector<uint64>* vec = GetSchemaValue<CUtlVector<uint64>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetUInt64Variables"); std::vector<uint64> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetPredNetUInt64Variables(std::vector<uint64> value) {
    SetSchemaValueCUtlVector<uint64>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetUInt64Variables", false, value);
}
std::vector<float32> GCAnimGraphNetworkedVariables::GetPredNetFloatVariables() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetFloatVariables"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetPredNetFloatVariables(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetFloatVariables", false, value);
}
std::vector<Vector> GCAnimGraphNetworkedVariables::GetPredNetVectorVariables() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetVectorVariables"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetPredNetVectorVariables(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetVectorVariables", false, value);
}
std::vector<Quaternion> GCAnimGraphNetworkedVariables::GetPredNetQuaternionVariables() const {
    CUtlVector<Quaternion>* vec = GetSchemaValue<CUtlVector<Quaternion>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetQuaternionVariables"); std::vector<Quaternion> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetPredNetQuaternionVariables(std::vector<Quaternion> value) {
    SetSchemaValueCUtlVector<Quaternion>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetQuaternionVariables", false, value);
}
std::vector<uint32> GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetBoolVariables() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetBoolVariables"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetBoolVariables(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetBoolVariables", false, value);
}
std::vector<uint8> GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetByteVariables() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetByteVariables"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetByteVariables(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetByteVariables", false, value);
}
std::vector<uint16> GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetUInt16Variables() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt16Variables"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetUInt16Variables(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt16Variables", false, value);
}
std::vector<int32> GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetIntVariables() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetIntVariables"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetIntVariables(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetIntVariables", false, value);
}
std::vector<uint32> GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetUInt32Variables() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt32Variables"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetUInt32Variables(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt32Variables", false, value);
}
std::vector<uint64> GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetUInt64Variables() const {
    CUtlVector<uint64>* vec = GetSchemaValue<CUtlVector<uint64>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt64Variables"); std::vector<uint64> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetUInt64Variables(std::vector<uint64> value) {
    SetSchemaValueCUtlVector<uint64>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt64Variables", false, value);
}
std::vector<float32> GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetFloatVariables() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetFloatVariables"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetFloatVariables(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetFloatVariables", false, value);
}
std::vector<Vector> GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetVectorVariables() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetVectorVariables"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetVectorVariables(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetVectorVariables", false, value);
}
std::vector<Quaternion> GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetQuaternionVariables() const {
    CUtlVector<Quaternion>* vec = GetSchemaValue<CUtlVector<Quaternion>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetQuaternionVariables"); std::vector<Quaternion> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetQuaternionVariables(std::vector<Quaternion> value) {
    SetSchemaValueCUtlVector<Quaternion>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetQuaternionVariables", false, value);
}
int32_t GCAnimGraphNetworkedVariables::GetBoolVariablesCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimGraphNetworkedVariables", "m_nBoolVariablesCount");
}
void GCAnimGraphNetworkedVariables::SetBoolVariablesCount(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimGraphNetworkedVariables", "m_nBoolVariablesCount", false, value);
}
int32_t GCAnimGraphNetworkedVariables::GetOwnerOnlyBoolVariablesCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimGraphNetworkedVariables", "m_nOwnerOnlyBoolVariablesCount");
}
void GCAnimGraphNetworkedVariables::SetOwnerOnlyBoolVariablesCount(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimGraphNetworkedVariables", "m_nOwnerOnlyBoolVariablesCount", false, value);
}
int32_t GCAnimGraphNetworkedVariables::GetRandomSeedOffset() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimGraphNetworkedVariables", "m_nRandomSeedOffset");
}
void GCAnimGraphNetworkedVariables::SetRandomSeedOffset(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimGraphNetworkedVariables", "m_nRandomSeedOffset", false, value);
}
float GCAnimGraphNetworkedVariables::GetLastTeleportTime() const {
    return GetSchemaValue<float>(m_ptr, "CAnimGraphNetworkedVariables", "m_flLastTeleportTime");
}
void GCAnimGraphNetworkedVariables::SetLastTeleportTime(float value) {
    SetSchemaValue(m_ptr, "CAnimGraphNetworkedVariables", "m_flLastTeleportTime", false, value);
}
std::string GCAnimGraphNetworkedVariables::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimGraphNetworkedVariables::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimGraphNetworkedVariables(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphNetworkedVariables>("CAnimGraphNetworkedVariables")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PredNetBoolVariables", &GCAnimGraphNetworkedVariables::GetPredNetBoolVariables, &GCAnimGraphNetworkedVariables::SetPredNetBoolVariables)
        .addProperty("PredNetByteVariables", &GCAnimGraphNetworkedVariables::GetPredNetByteVariables, &GCAnimGraphNetworkedVariables::SetPredNetByteVariables)
        .addProperty("PredNetUInt16Variables", &GCAnimGraphNetworkedVariables::GetPredNetUInt16Variables, &GCAnimGraphNetworkedVariables::SetPredNetUInt16Variables)
        .addProperty("PredNetIntVariables", &GCAnimGraphNetworkedVariables::GetPredNetIntVariables, &GCAnimGraphNetworkedVariables::SetPredNetIntVariables)
        .addProperty("PredNetUInt32Variables", &GCAnimGraphNetworkedVariables::GetPredNetUInt32Variables, &GCAnimGraphNetworkedVariables::SetPredNetUInt32Variables)
        .addProperty("PredNetUInt64Variables", &GCAnimGraphNetworkedVariables::GetPredNetUInt64Variables, &GCAnimGraphNetworkedVariables::SetPredNetUInt64Variables)
        .addProperty("PredNetFloatVariables", &GCAnimGraphNetworkedVariables::GetPredNetFloatVariables, &GCAnimGraphNetworkedVariables::SetPredNetFloatVariables)
        .addProperty("PredNetVectorVariables", &GCAnimGraphNetworkedVariables::GetPredNetVectorVariables, &GCAnimGraphNetworkedVariables::SetPredNetVectorVariables)
        .addProperty("PredNetQuaternionVariables", &GCAnimGraphNetworkedVariables::GetPredNetQuaternionVariables, &GCAnimGraphNetworkedVariables::SetPredNetQuaternionVariables)
        .addProperty("OwnerOnlyPredNetBoolVariables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetBoolVariables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetBoolVariables)
        .addProperty("OwnerOnlyPredNetByteVariables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetByteVariables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetByteVariables)
        .addProperty("OwnerOnlyPredNetUInt16Variables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetUInt16Variables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetUInt16Variables)
        .addProperty("OwnerOnlyPredNetIntVariables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetIntVariables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetIntVariables)
        .addProperty("OwnerOnlyPredNetUInt32Variables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetUInt32Variables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetUInt32Variables)
        .addProperty("OwnerOnlyPredNetUInt64Variables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetUInt64Variables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetUInt64Variables)
        .addProperty("OwnerOnlyPredNetFloatVariables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetFloatVariables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetFloatVariables)
        .addProperty("OwnerOnlyPredNetVectorVariables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetVectorVariables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetVectorVariables)
        .addProperty("OwnerOnlyPredNetQuaternionVariables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetQuaternionVariables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetQuaternionVariables)
        .addProperty("BoolVariablesCount", &GCAnimGraphNetworkedVariables::GetBoolVariablesCount, &GCAnimGraphNetworkedVariables::SetBoolVariablesCount)
        .addProperty("OwnerOnlyBoolVariablesCount", &GCAnimGraphNetworkedVariables::GetOwnerOnlyBoolVariablesCount, &GCAnimGraphNetworkedVariables::SetOwnerOnlyBoolVariablesCount)
        .addProperty("RandomSeedOffset", &GCAnimGraphNetworkedVariables::GetRandomSeedOffset, &GCAnimGraphNetworkedVariables::SetRandomSeedOffset)
        .addProperty("LastTeleportTime", &GCAnimGraphNetworkedVariables::GetLastTeleportTime, &GCAnimGraphNetworkedVariables::SetLastTeleportTime)
        .addFunction("ToPtr", &GCAnimGraphNetworkedVariables::ToPtr)
        .addFunction("IsValid", &GCAnimGraphNetworkedVariables::IsValid)
        .endClass();
}