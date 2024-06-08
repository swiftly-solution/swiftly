class GCAnimSequenceParams;

#ifndef _gccanimsequenceparams_h
#define _gccanimsequenceparams_h

#include "../../../scripting.h"




class GCAnimSequenceParams
{
private:
    void *m_ptr;

public:
    GCAnimSequenceParams() {}
    GCAnimSequenceParams(void *ptr) : m_ptr(ptr) {}

    float GetFadeInTime() const { return GetSchemaValue<float>(m_ptr, "CAnimSequenceParams", "m_flFadeInTime"); }
    void SetFadeInTime(float value) { SetSchemaValue(m_ptr, "CAnimSequenceParams", "m_flFadeInTime", false, value); }
    float GetFadeOutTime() const { return GetSchemaValue<float>(m_ptr, "CAnimSequenceParams", "m_flFadeOutTime"); }
    void SetFadeOutTime(float value) { SetSchemaValue(m_ptr, "CAnimSequenceParams", "m_flFadeOutTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif