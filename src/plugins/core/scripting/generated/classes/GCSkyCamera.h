class GCSkyCamera;

#ifndef _gccskycamera_h
#define _gccskycamera_h

#include "../../../scripting.h"


#include "Gsky3dparams_t.h"
#include "GCSkyCamera.h"

class GCSkyCamera
{
private:
    void *m_ptr;

public:
    GCSkyCamera() {}
    GCSkyCamera(void *ptr) : m_ptr(ptr) {}

    Gsky3dparams_t GetSkyboxData() const { return GetSchemaValue<Gsky3dparams_t>(m_ptr, "CSkyCamera", "m_skyboxData"); }
    void SetSkyboxData(Gsky3dparams_t value) { SetSchemaValue(m_ptr, "CSkyCamera", "m_skyboxData", false, value); }
    CUtlStringToken GetSkyboxSlotToken() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "CSkyCamera", "m_skyboxSlotToken"); }
    void SetSkyboxSlotToken(CUtlStringToken value) { SetSchemaValue(m_ptr, "CSkyCamera", "m_skyboxSlotToken", false, value); }
    bool GetUseAngles() const { return GetSchemaValue<bool>(m_ptr, "CSkyCamera", "m_bUseAngles"); }
    void SetUseAngles(bool value) { SetSchemaValue(m_ptr, "CSkyCamera", "m_bUseAngles", false, value); }
    GCSkyCamera* GetNext() const { return GetSchemaValue<GCSkyCamera*>(m_ptr, "CSkyCamera", "m_pNext"); }
    void SetNext(GCSkyCamera* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Next' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif