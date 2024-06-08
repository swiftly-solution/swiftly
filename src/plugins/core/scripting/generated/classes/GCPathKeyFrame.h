class GCPathKeyFrame;

#ifndef _gccpathkeyframe_h
#define _gccpathkeyframe_h

#include "../../../scripting.h"


#include "GCPathKeyFrame.h"

class GCPathKeyFrame
{
private:
    void *m_ptr;

public:
    GCPathKeyFrame() {}
    GCPathKeyFrame(void *ptr) : m_ptr(ptr) {}

    Vector GetOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CPathKeyFrame", "m_Origin"); }
    void SetOrigin(Vector value) { SetSchemaValue(m_ptr, "CPathKeyFrame", "m_Origin", false, value); }
    QAngle GetAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CPathKeyFrame", "m_Angles"); }
    void SetAngles(QAngle value) { SetSchemaValue(m_ptr, "CPathKeyFrame", "m_Angles", false, value); }
    Quaternion GetAngle() const { return GetSchemaValue<Quaternion>(m_ptr, "CPathKeyFrame", "m_qAngle"); }
    void SetAngle(Quaternion value) { SetSchemaValue(m_ptr, "CPathKeyFrame", "m_qAngle", false, value); }
    CUtlSymbolLarge GetNextKey() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPathKeyFrame", "m_iNextKey"); }
    void SetNextKey(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPathKeyFrame", "m_iNextKey", false, value); }
    float GetNextTime() const { return GetSchemaValue<float>(m_ptr, "CPathKeyFrame", "m_flNextTime"); }
    void SetNextTime(float value) { SetSchemaValue(m_ptr, "CPathKeyFrame", "m_flNextTime", false, value); }
    GCPathKeyFrame* GetNextKey1() const { return GetSchemaValue<GCPathKeyFrame*>(m_ptr, "CPathKeyFrame", "m_pNextKey"); }
    void SetNextKey1(GCPathKeyFrame* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'NextKey1' is not possible.\n"); }
    GCPathKeyFrame* GetPrevKey() const { return GetSchemaValue<GCPathKeyFrame*>(m_ptr, "CPathKeyFrame", "m_pPrevKey"); }
    void SetPrevKey(GCPathKeyFrame* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PrevKey' is not possible.\n"); }
    float GetMoveSpeed() const { return GetSchemaValue<float>(m_ptr, "CPathKeyFrame", "m_flMoveSpeed"); }
    void SetMoveSpeed(float value) { SetSchemaValue(m_ptr, "CPathKeyFrame", "m_flMoveSpeed", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif