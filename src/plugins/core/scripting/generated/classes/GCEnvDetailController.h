class GCEnvDetailController;

#ifndef _gccenvdetailcontroller_h
#define _gccenvdetailcontroller_h

#include "../../../scripting.h"




class GCEnvDetailController
{
private:
    void *m_ptr;

public:
    GCEnvDetailController() {}
    GCEnvDetailController(void *ptr) : m_ptr(ptr) {}

    float GetFadeStartDist() const { return GetSchemaValue<float>(m_ptr, "CEnvDetailController", "m_flFadeStartDist"); }
    void SetFadeStartDist(float value) { SetSchemaValue(m_ptr, "CEnvDetailController", "m_flFadeStartDist", false, value); }
    float GetFadeEndDist() const { return GetSchemaValue<float>(m_ptr, "CEnvDetailController", "m_flFadeEndDist"); }
    void SetFadeEndDist(float value) { SetSchemaValue(m_ptr, "CEnvDetailController", "m_flFadeEndDist", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif