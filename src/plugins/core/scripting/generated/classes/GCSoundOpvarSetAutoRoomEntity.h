class GCSoundOpvarSetAutoRoomEntity;

#ifndef _gccsoundopvarsetautoroomentity_h
#define _gccsoundopvarsetautoroomentity_h

#include "../../../scripting.h"


#include "GSoundOpvarTraceResult_t.h"

class GCSoundOpvarSetAutoRoomEntity
{
private:
    void *m_ptr;

public:
    GCSoundOpvarSetAutoRoomEntity() {}
    GCSoundOpvarSetAutoRoomEntity(void *ptr) : m_ptr(ptr) {}

    std::vector<GSoundOpvarTraceResult_t> GetTraceResults() const { CUtlVector<GSoundOpvarTraceResult_t>* vec = GetSchemaValue<CUtlVector<GSoundOpvarTraceResult_t>*>(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_traceResults"); std::vector<GSoundOpvarTraceResult_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTraceResults(std::vector<GSoundOpvarTraceResult_t> value) { SetSchemaValueCUtlVector<GSoundOpvarTraceResult_t>(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_traceResults", false, value); }
    float GetSize() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_flSize"); }
    void SetSize(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_flSize", false, value); }
    float GetHeightTolerance() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_flHeightTolerance"); }
    void SetHeightTolerance(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_flHeightTolerance", false, value); }
    float GetSizeSqr() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_flSizeSqr"); }
    void SetSizeSqr(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetAutoRoomEntity", "m_flSizeSqr", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif