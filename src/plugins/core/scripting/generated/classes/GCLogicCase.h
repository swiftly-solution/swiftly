class GCLogicCase;

#ifndef _gcclogiccase_h
#define _gcclogiccase_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCLogicCase
{
private:
    void *m_ptr;

public:
    GCLogicCase() {}
    GCLogicCase(void *ptr) : m_ptr(ptr) {}

    std::vector<CUtlSymbolLarge> GetCase() const { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CLogicCase", "m_nCase"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetCase(std::vector<CUtlSymbolLarge> value) { CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CLogicCase", "m_nCase"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CLogicCase", "m_nCase", false, outValue); }
    int32_t GetShuffleCases() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicCase", "m_nShuffleCases"); }
    void SetShuffleCases(int32_t value) { SetSchemaValue(m_ptr, "CLogicCase", "m_nShuffleCases", false, value); }
    int32_t GetLastShuffleCase() const { return GetSchemaValue<int32_t>(m_ptr, "CLogicCase", "m_nLastShuffleCase"); }
    void SetLastShuffleCase(int32_t value) { SetSchemaValue(m_ptr, "CLogicCase", "m_nLastShuffleCase", false, value); }
    std::vector<uint8_t> GetUchShuffleCaseMap() const { uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "CLogicCase", "m_uchShuffleCaseMap"); std::vector<uint8_t> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetUchShuffleCaseMap(std::vector<uint8_t> value) { uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "CLogicCase", "m_uchShuffleCaseMap"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CLogicCase", "m_uchShuffleCaseMap", false, outValue); }
    std::vector<GCEntityIOOutput> GetOnCase() const { GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CLogicCase", "m_OnCase"); std::vector<GCEntityIOOutput> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetOnCase(std::vector<GCEntityIOOutput> value) { GCEntityIOOutput* outValue = GetSchemaValue<GCEntityIOOutput*>(m_ptr, "CLogicCase", "m_OnCase"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CLogicCase", "m_OnCase", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif