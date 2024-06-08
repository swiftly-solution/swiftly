class GC_OP_RenderScreenVelocityRotate;

#ifndef _gcc_op_renderscreenvelocityrotate_h
#define _gcc_op_renderscreenvelocityrotate_h

#include "../../../scripting.h"




class GC_OP_RenderScreenVelocityRotate
{
private:
    void *m_ptr;

public:
    GC_OP_RenderScreenVelocityRotate() {}
    GC_OP_RenderScreenVelocityRotate(void *ptr) : m_ptr(ptr) {}

    float GetRotateRateDegrees() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderScreenVelocityRotate", "m_flRotateRateDegrees"); }
    void SetRotateRateDegrees(float value) { SetSchemaValue(m_ptr, "C_OP_RenderScreenVelocityRotate", "m_flRotateRateDegrees", false, value); }
    float GetForwardDegrees() const { return GetSchemaValue<float>(m_ptr, "C_OP_RenderScreenVelocityRotate", "m_flForwardDegrees"); }
    void SetForwardDegrees(float value) { SetSchemaValue(m_ptr, "C_OP_RenderScreenVelocityRotate", "m_flForwardDegrees", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif