class GAnimationDecodeDebugDumpElement_t;

#ifndef _gcanimationdecodedebugdumpelement_t_h
#define _gcanimationdecodedebugdumpelement_t_h

#include "../../../scripting.h"




class GAnimationDecodeDebugDumpElement_t
{
private:
    void *m_ptr;

public:
    GAnimationDecodeDebugDumpElement_t() {}
    GAnimationDecodeDebugDumpElement_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetEntityIndex() const { return GetSchemaValue<int32_t>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_nEntityIndex"); }
    void SetEntityIndex(int32_t value) { SetSchemaValue(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_nEntityIndex", true, value); }
    CUtlString GetModelName() const { return GetSchemaValue<CUtlString>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_modelName"); }
    void SetModelName(CUtlString value) { SetSchemaValue(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_modelName", true, value); }
    std::vector<CUtlString> GetPoseParams() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_poseParams"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPoseParams(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_poseParams", true, value); }
    std::vector<CUtlString> GetDecodeOps() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_decodeOps"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDecodeOps(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_decodeOps", true, value); }
    std::vector<CUtlString> GetInternalOps() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_internalOps"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInternalOps(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_internalOps", true, value); }
    std::vector<CUtlString> GetDecodedAnims() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_decodedAnims"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDecodedAnims(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "AnimationDecodeDebugDumpElement_t", "m_decodedAnims", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif