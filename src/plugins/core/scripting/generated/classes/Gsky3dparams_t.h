class Gsky3dparams_t;

#ifndef _gcsky3dparams_t_h
#define _gcsky3dparams_t_h

#include "../../../scripting.h"


#include "Gfogparams_t.h"

class Gsky3dparams_t
{
private:
    void *m_ptr;

public:
    Gsky3dparams_t() {}
    Gsky3dparams_t(void *ptr) : m_ptr(ptr) {}

    int16_t GetScale() const { return GetSchemaValue<int16_t>(m_ptr, "sky3dparams_t", "scale"); }
    void SetScale(int16_t value) { SetSchemaValue(m_ptr, "sky3dparams_t", "scale", true, value); }
    Vector GetOrigin() const { return GetSchemaValue<Vector>(m_ptr, "sky3dparams_t", "origin"); }
    void SetOrigin(Vector value) { SetSchemaValue(m_ptr, "sky3dparams_t", "origin", true, value); }
    bool GetClip3DSkyBoxNearToWorldFar() const { return GetSchemaValue<bool>(m_ptr, "sky3dparams_t", "bClip3DSkyBoxNearToWorldFar"); }
    void SetClip3DSkyBoxNearToWorldFar(bool value) { SetSchemaValue(m_ptr, "sky3dparams_t", "bClip3DSkyBoxNearToWorldFar", true, value); }
    float GetClip3DSkyBoxNearToWorldFarOffset() const { return GetSchemaValue<float>(m_ptr, "sky3dparams_t", "flClip3DSkyBoxNearToWorldFarOffset"); }
    void SetClip3DSkyBoxNearToWorldFarOffset(float value) { SetSchemaValue(m_ptr, "sky3dparams_t", "flClip3DSkyBoxNearToWorldFarOffset", true, value); }
    Gfogparams_t GetFog() const { return GetSchemaValue<Gfogparams_t>(m_ptr, "sky3dparams_t", "fog"); }
    void SetFog(Gfogparams_t value) { SetSchemaValue(m_ptr, "sky3dparams_t", "fog", true, value); }
    WorldGroupId_t GetWorldGroupID() const { return GetSchemaValue<WorldGroupId_t>(m_ptr, "sky3dparams_t", "m_nWorldGroupID"); }
    void SetWorldGroupID(WorldGroupId_t value) { SetSchemaValue(m_ptr, "sky3dparams_t", "m_nWorldGroupID", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif