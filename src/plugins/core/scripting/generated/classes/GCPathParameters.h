class GCPathParameters;

#ifndef _gccpathparameters_h
#define _gccpathparameters_h

#include "../../../scripting.h"




class GCPathParameters
{
private:
    void *m_ptr;

public:
    GCPathParameters() {}
    GCPathParameters(void *ptr) : m_ptr(ptr) {}

    int32_t GetStartControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "CPathParameters", "m_nStartControlPointNumber"); }
    void SetStartControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "CPathParameters", "m_nStartControlPointNumber", false, value); }
    int32_t GetEndControlPointNumber() const { return GetSchemaValue<int32_t>(m_ptr, "CPathParameters", "m_nEndControlPointNumber"); }
    void SetEndControlPointNumber(int32_t value) { SetSchemaValue(m_ptr, "CPathParameters", "m_nEndControlPointNumber", false, value); }
    int32_t GetBulgeControl() const { return GetSchemaValue<int32_t>(m_ptr, "CPathParameters", "m_nBulgeControl"); }
    void SetBulgeControl(int32_t value) { SetSchemaValue(m_ptr, "CPathParameters", "m_nBulgeControl", false, value); }
    float GetBulge() const { return GetSchemaValue<float>(m_ptr, "CPathParameters", "m_flBulge"); }
    void SetBulge(float value) { SetSchemaValue(m_ptr, "CPathParameters", "m_flBulge", false, value); }
    float GetMidPoint() const { return GetSchemaValue<float>(m_ptr, "CPathParameters", "m_flMidPoint"); }
    void SetMidPoint(float value) { SetSchemaValue(m_ptr, "CPathParameters", "m_flMidPoint", false, value); }
    Vector GetStartPointOffset() const { return GetSchemaValue<Vector>(m_ptr, "CPathParameters", "m_vStartPointOffset"); }
    void SetStartPointOffset(Vector value) { SetSchemaValue(m_ptr, "CPathParameters", "m_vStartPointOffset", false, value); }
    Vector GetMidPointOffset() const { return GetSchemaValue<Vector>(m_ptr, "CPathParameters", "m_vMidPointOffset"); }
    void SetMidPointOffset(Vector value) { SetSchemaValue(m_ptr, "CPathParameters", "m_vMidPointOffset", false, value); }
    Vector GetEndOffset() const { return GetSchemaValue<Vector>(m_ptr, "CPathParameters", "m_vEndOffset"); }
    void SetEndOffset(Vector value) { SetSchemaValue(m_ptr, "CPathParameters", "m_vEndOffset", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif