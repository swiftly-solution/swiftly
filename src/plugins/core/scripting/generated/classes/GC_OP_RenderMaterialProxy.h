class GC_OP_RenderMaterialProxy;

#ifndef _gcc_op_rendermaterialproxy_h
#define _gcc_op_rendermaterialproxy_h

#include "../../../scripting.h"

#include "../types/GMaterialProxyType_t.h"
#include "../types/GParticleColorBlendType_t.h"
#include "GMaterialVariable_t.h"
#include "GCParticleCollectionFloatInput.h"
#include "GCPerParticleFloatInput.h"

class GC_OP_RenderMaterialProxy
{
private:
    void *m_ptr;

public:
    GC_OP_RenderMaterialProxy() {}
    GC_OP_RenderMaterialProxy(void *ptr) : m_ptr(ptr) {}

    int32_t GetMaterialControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RenderMaterialProxy", "m_nMaterialControlPoint"); }
    void SetMaterialControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RenderMaterialProxy", "m_nMaterialControlPoint", false, value); }
    MaterialProxyType_t GetProxyType() const { return GetSchemaValue<MaterialProxyType_t>(m_ptr, "C_OP_RenderMaterialProxy", "m_nProxyType"); }
    void SetProxyType(MaterialProxyType_t value) { SetSchemaValue(m_ptr, "C_OP_RenderMaterialProxy", "m_nProxyType", false, value); }
    std::vector<GMaterialVariable_t> GetMaterialVars() const { CUtlVector<GMaterialVariable_t>* vec = GetSchemaValue<CUtlVector<GMaterialVariable_t>*>(m_ptr, "C_OP_RenderMaterialProxy", "m_MaterialVars"); std::vector<GMaterialVariable_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMaterialVars(std::vector<GMaterialVariable_t> value) { SetSchemaValueCUtlVector<GMaterialVariable_t>(m_ptr, "C_OP_RenderMaterialProxy", "m_MaterialVars", false, value); }
    GCParticleCollectionFloatInput GetMaterialOverrideEnabled() const { return GetSchemaValue<GCParticleCollectionFloatInput>(m_ptr, "C_OP_RenderMaterialProxy", "m_flMaterialOverrideEnabled"); }
    void SetMaterialOverrideEnabled(GCParticleCollectionFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderMaterialProxy", "m_flMaterialOverrideEnabled", false, value); }
    GCPerParticleFloatInput GetAlpha() const { return GetSchemaValue<GCPerParticleFloatInput>(m_ptr, "C_OP_RenderMaterialProxy", "m_flAlpha"); }
    void SetAlpha(GCPerParticleFloatInput value) { SetSchemaValue(m_ptr, "C_OP_RenderMaterialProxy", "m_flAlpha", false, value); }
    ParticleColorBlendType_t GetColorBlendType() const { return GetSchemaValue<ParticleColorBlendType_t>(m_ptr, "C_OP_RenderMaterialProxy", "m_nColorBlendType"); }
    void SetColorBlendType(ParticleColorBlendType_t value) { SetSchemaValue(m_ptr, "C_OP_RenderMaterialProxy", "m_nColorBlendType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif