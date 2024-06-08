class GCParticleFunctionRenderer;

#ifndef _gccparticlefunctionrenderer_h
#define _gccparticlefunctionrenderer_h

#include "../../../scripting.h"


#include "GCParticleVisibilityInputs.h"

class GCParticleFunctionRenderer
{
private:
    void *m_ptr;

public:
    GCParticleFunctionRenderer() {}
    GCParticleFunctionRenderer(void *ptr) : m_ptr(ptr) {}

    GCParticleVisibilityInputs GetVisibilityInputs() const { return GetSchemaValue<GCParticleVisibilityInputs>(m_ptr, "CParticleFunctionRenderer", "VisibilityInputs"); }
    void SetVisibilityInputs(GCParticleVisibilityInputs value) { SetSchemaValue(m_ptr, "CParticleFunctionRenderer", "VisibilityInputs", false, value); }
    bool GetCannotBeRefracted() const { return GetSchemaValue<bool>(m_ptr, "CParticleFunctionRenderer", "m_bCannotBeRefracted"); }
    void SetCannotBeRefracted(bool value) { SetSchemaValue(m_ptr, "CParticleFunctionRenderer", "m_bCannotBeRefracted", false, value); }
    bool GetSkipRenderingOnMobile() const { return GetSchemaValue<bool>(m_ptr, "CParticleFunctionRenderer", "m_bSkipRenderingOnMobile"); }
    void SetSkipRenderingOnMobile(bool value) { SetSchemaValue(m_ptr, "CParticleFunctionRenderer", "m_bSkipRenderingOnMobile", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif