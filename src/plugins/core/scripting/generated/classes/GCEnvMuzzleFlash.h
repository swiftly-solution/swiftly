class GCEnvMuzzleFlash;

#ifndef _gccenvmuzzleflash_h
#define _gccenvmuzzleflash_h

#include "../../../scripting.h"




class GCEnvMuzzleFlash
{
private:
    void *m_ptr;

public:
    GCEnvMuzzleFlash() {}
    GCEnvMuzzleFlash(void *ptr) : m_ptr(ptr) {}

    float GetScale() const { return GetSchemaValue<float>(m_ptr, "CEnvMuzzleFlash", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "CEnvMuzzleFlash", "m_flScale", false, value); }
    CUtlSymbolLarge GetParentAttachment() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvMuzzleFlash", "m_iszParentAttachment"); }
    void SetParentAttachment(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CEnvMuzzleFlash", "m_iszParentAttachment", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif