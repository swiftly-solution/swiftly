class GCNetworkedSequenceOperation;

#ifndef _gccnetworkedsequenceoperation_h
#define _gccnetworkedsequenceoperation_h

#include "../../../scripting.h"




class GCNetworkedSequenceOperation
{
private:
    void *m_ptr;

public:
    GCNetworkedSequenceOperation() {}
    GCNetworkedSequenceOperation(void *ptr) : m_ptr(ptr) {}

    float GetPrevCycle() const { return GetSchemaValue<float>(m_ptr, "CNetworkedSequenceOperation", "m_flPrevCycle"); }
    void SetPrevCycle(float value) { SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_flPrevCycle", false, value); }
    float GetCycle() const { return GetSchemaValue<float>(m_ptr, "CNetworkedSequenceOperation", "m_flCycle"); }
    void SetCycle(float value) { SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_flCycle", false, value); }
    float GetWeight() const { return GetSchemaValue<float>(m_ptr, "CNetworkedSequenceOperation", "m_flWeight"); }
    void SetWeight(float value) { SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_flWeight", false, value); }
    bool GetSequenceChangeNetworked() const { return GetSchemaValue<bool>(m_ptr, "CNetworkedSequenceOperation", "m_bSequenceChangeNetworked"); }
    void SetSequenceChangeNetworked(bool value) { SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_bSequenceChangeNetworked", false, value); }
    bool GetDiscontinuity() const { return GetSchemaValue<bool>(m_ptr, "CNetworkedSequenceOperation", "m_bDiscontinuity"); }
    void SetDiscontinuity(bool value) { SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_bDiscontinuity", false, value); }
    float GetPrevCycleFromDiscontinuity() const { return GetSchemaValue<float>(m_ptr, "CNetworkedSequenceOperation", "m_flPrevCycleFromDiscontinuity"); }
    void SetPrevCycleFromDiscontinuity(float value) { SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_flPrevCycleFromDiscontinuity", false, value); }
    float GetPrevCycleForAnimEventDetection() const { return GetSchemaValue<float>(m_ptr, "CNetworkedSequenceOperation", "m_flPrevCycleForAnimEventDetection"); }
    void SetPrevCycleForAnimEventDetection(float value) { SetSchemaValue(m_ptr, "CNetworkedSequenceOperation", "m_flPrevCycleForAnimEventDetection", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif