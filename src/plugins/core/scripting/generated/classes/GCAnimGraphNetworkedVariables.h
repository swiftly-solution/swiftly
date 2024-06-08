class GCAnimGraphNetworkedVariables;

#ifndef _gccanimgraphnetworkedvariables_h
#define _gccanimgraphnetworkedvariables_h

#include "../../../scripting.h"




class GCAnimGraphNetworkedVariables
{
private:
    void *m_ptr;

public:
    GCAnimGraphNetworkedVariables() {}
    GCAnimGraphNetworkedVariables(void *ptr) : m_ptr(ptr) {}

    std::vector<uint32> GetPredNetBoolVariables() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetBoolVariables"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPredNetBoolVariables(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetBoolVariables", false, value); }
    std::vector<uint8> GetPredNetByteVariables() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetByteVariables"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPredNetByteVariables(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetByteVariables", false, value); }
    std::vector<uint16> GetPredNetUInt16Variables() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetUInt16Variables"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPredNetUInt16Variables(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetUInt16Variables", false, value); }
    std::vector<int32> GetPredNetIntVariables() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetIntVariables"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPredNetIntVariables(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetIntVariables", false, value); }
    std::vector<uint32> GetPredNetUInt32Variables() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetUInt32Variables"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPredNetUInt32Variables(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetUInt32Variables", false, value); }
    std::vector<uint64> GetPredNetUInt64Variables() const { CUtlVector<uint64>* vec = GetSchemaValue<CUtlVector<uint64>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetUInt64Variables"); std::vector<uint64> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPredNetUInt64Variables(std::vector<uint64> value) { SetSchemaValueCUtlVector<uint64>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetUInt64Variables", false, value); }
    std::vector<float32> GetPredNetFloatVariables() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetFloatVariables"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPredNetFloatVariables(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetFloatVariables", false, value); }
    std::vector<Vector> GetPredNetVectorVariables() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetVectorVariables"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPredNetVectorVariables(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetVectorVariables", false, value); }
    std::vector<Quaternion> GetPredNetQuaternionVariables() const { CUtlVector<Quaternion>* vec = GetSchemaValue<CUtlVector<Quaternion>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetQuaternionVariables"); std::vector<Quaternion> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPredNetQuaternionVariables(std::vector<Quaternion> value) { SetSchemaValueCUtlVector<Quaternion>(m_ptr, "CAnimGraphNetworkedVariables", "m_PredNetQuaternionVariables", false, value); }
    std::vector<uint32> GetOwnerOnlyPredNetBoolVariables() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetBoolVariables"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOwnerOnlyPredNetBoolVariables(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetBoolVariables", false, value); }
    std::vector<uint8> GetOwnerOnlyPredNetByteVariables() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetByteVariables"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOwnerOnlyPredNetByteVariables(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetByteVariables", false, value); }
    std::vector<uint16> GetOwnerOnlyPredNetUInt16Variables() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt16Variables"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOwnerOnlyPredNetUInt16Variables(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt16Variables", false, value); }
    std::vector<int32> GetOwnerOnlyPredNetIntVariables() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetIntVariables"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOwnerOnlyPredNetIntVariables(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetIntVariables", false, value); }
    std::vector<uint32> GetOwnerOnlyPredNetUInt32Variables() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt32Variables"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOwnerOnlyPredNetUInt32Variables(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt32Variables", false, value); }
    std::vector<uint64> GetOwnerOnlyPredNetUInt64Variables() const { CUtlVector<uint64>* vec = GetSchemaValue<CUtlVector<uint64>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt64Variables"); std::vector<uint64> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOwnerOnlyPredNetUInt64Variables(std::vector<uint64> value) { SetSchemaValueCUtlVector<uint64>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt64Variables", false, value); }
    std::vector<float32> GetOwnerOnlyPredNetFloatVariables() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetFloatVariables"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOwnerOnlyPredNetFloatVariables(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetFloatVariables", false, value); }
    std::vector<Vector> GetOwnerOnlyPredNetVectorVariables() const { CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetVectorVariables"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOwnerOnlyPredNetVectorVariables(std::vector<Vector> value) { SetSchemaValueCUtlVector<Vector>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetVectorVariables", false, value); }
    std::vector<Quaternion> GetOwnerOnlyPredNetQuaternionVariables() const { CUtlVector<Quaternion>* vec = GetSchemaValue<CUtlVector<Quaternion>*>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetQuaternionVariables"); std::vector<Quaternion> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOwnerOnlyPredNetQuaternionVariables(std::vector<Quaternion> value) { SetSchemaValueCUtlVector<Quaternion>(m_ptr, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetQuaternionVariables", false, value); }
    int32_t GetBoolVariablesCount() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimGraphNetworkedVariables", "m_nBoolVariablesCount"); }
    void SetBoolVariablesCount(int32_t value) { SetSchemaValue(m_ptr, "CAnimGraphNetworkedVariables", "m_nBoolVariablesCount", false, value); }
    int32_t GetOwnerOnlyBoolVariablesCount() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimGraphNetworkedVariables", "m_nOwnerOnlyBoolVariablesCount"); }
    void SetOwnerOnlyBoolVariablesCount(int32_t value) { SetSchemaValue(m_ptr, "CAnimGraphNetworkedVariables", "m_nOwnerOnlyBoolVariablesCount", false, value); }
    int32_t GetRandomSeedOffset() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimGraphNetworkedVariables", "m_nRandomSeedOffset"); }
    void SetRandomSeedOffset(int32_t value) { SetSchemaValue(m_ptr, "CAnimGraphNetworkedVariables", "m_nRandomSeedOffset", false, value); }
    float GetLastTeleportTime() const { return GetSchemaValue<float>(m_ptr, "CAnimGraphNetworkedVariables", "m_flLastTeleportTime"); }
    void SetLastTeleportTime(float value) { SetSchemaValue(m_ptr, "CAnimGraphNetworkedVariables", "m_flLastTeleportTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif