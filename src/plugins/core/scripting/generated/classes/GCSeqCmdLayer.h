class GCSeqCmdLayer;

#ifndef _gccseqcmdlayer_h
#define _gccseqcmdlayer_h

#include "../../../scripting.h"




class GCSeqCmdLayer
{
private:
    void *m_ptr;

public:
    GCSeqCmdLayer() {}
    GCSeqCmdLayer(void *ptr) : m_ptr(ptr) {}

    int16_t GetCmd() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdLayer", "m_cmd"); }
    void SetCmd(int16_t value) { SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_cmd", false, value); }
    int16_t GetLocalReference() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdLayer", "m_nLocalReference"); }
    void SetLocalReference(int16_t value) { SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_nLocalReference", false, value); }
    int16_t GetLocalBonemask() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdLayer", "m_nLocalBonemask"); }
    void SetLocalBonemask(int16_t value) { SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_nLocalBonemask", false, value); }
    int16_t GetDstResult() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdLayer", "m_nDstResult"); }
    void SetDstResult(int16_t value) { SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_nDstResult", false, value); }
    int16_t GetSrcResult() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdLayer", "m_nSrcResult"); }
    void SetSrcResult(int16_t value) { SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_nSrcResult", false, value); }
    bool GetSpline() const { return GetSchemaValue<bool>(m_ptr, "CSeqCmdLayer", "m_bSpline"); }
    void SetSpline(bool value) { SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_bSpline", false, value); }
    float GetVar1() const { return GetSchemaValue<float>(m_ptr, "CSeqCmdLayer", "m_flVar1"); }
    void SetVar1(float value) { SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_flVar1", false, value); }
    float GetVar2() const { return GetSchemaValue<float>(m_ptr, "CSeqCmdLayer", "m_flVar2"); }
    void SetVar2(float value) { SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_flVar2", false, value); }
    int16_t GetLineNumber() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqCmdLayer", "m_nLineNumber"); }
    void SetLineNumber(int16_t value) { SetSchemaValue(m_ptr, "CSeqCmdLayer", "m_nLineNumber", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif