class GCNmClipNode;

#ifndef _gccnmclipnode_h
#define _gccnmclipnode_h

#include "../../../scripting.h"




class GCNmClipNode
{
private:
    void *m_ptr;

public:
    GCNmClipNode() {}
    GCNmClipNode(void *ptr) : m_ptr(ptr) {}

    int16_t GetPlayInReverseValueNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmClipNode", "m_nPlayInReverseValueNodeIdx"); }
    void SetPlayInReverseValueNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmClipNode", "m_nPlayInReverseValueNodeIdx", false, value); }
    int16_t GetResetTimeValueNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmClipNode", "m_nResetTimeValueNodeIdx"); }
    void SetResetTimeValueNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmClipNode", "m_nResetTimeValueNodeIdx", false, value); }
    bool GetSampleRootMotion() const { return GetSchemaValue<bool>(m_ptr, "CNmClipNode", "m_bSampleRootMotion"); }
    void SetSampleRootMotion(bool value) { SetSchemaValue(m_ptr, "CNmClipNode", "m_bSampleRootMotion", false, value); }
    bool GetAllowLooping() const { return GetSchemaValue<bool>(m_ptr, "CNmClipNode", "m_bAllowLooping"); }
    void SetAllowLooping(bool value) { SetSchemaValue(m_ptr, "CNmClipNode", "m_bAllowLooping", false, value); }
    int16_t GetDataSlotIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmClipNode", "m_nDataSlotIdx"); }
    void SetDataSlotIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmClipNode", "m_nDataSlotIdx", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif