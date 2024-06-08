class Ghudtextparms_t;

#ifndef _gchudtextparms_t_h
#define _gchudtextparms_t_h

#include "../../../scripting.h"




class Ghudtextparms_t
{
private:
    void *m_ptr;

public:
    Ghudtextparms_t() {}
    Ghudtextparms_t(void *ptr) : m_ptr(ptr) {}

    Color GetColor1() const { return GetSchemaValue<Color>(m_ptr, "hudtextparms_t", "color1"); }
    void SetColor1(Color value) { SetSchemaValue(m_ptr, "hudtextparms_t", "color1", true, value); }
    Color GetColor2() const { return GetSchemaValue<Color>(m_ptr, "hudtextparms_t", "color2"); }
    void SetColor2(Color value) { SetSchemaValue(m_ptr, "hudtextparms_t", "color2", true, value); }
    uint8_t GetEffect() const { return GetSchemaValue<uint8_t>(m_ptr, "hudtextparms_t", "effect"); }
    void SetEffect(uint8_t value) { SetSchemaValue(m_ptr, "hudtextparms_t", "effect", true, value); }
    uint8_t GetChannel() const { return GetSchemaValue<uint8_t>(m_ptr, "hudtextparms_t", "channel"); }
    void SetChannel(uint8_t value) { SetSchemaValue(m_ptr, "hudtextparms_t", "channel", true, value); }
    float GetX() const { return GetSchemaValue<float>(m_ptr, "hudtextparms_t", "x"); }
    void SetX(float value) { SetSchemaValue(m_ptr, "hudtextparms_t", "x", true, value); }
    float GetY() const { return GetSchemaValue<float>(m_ptr, "hudtextparms_t", "y"); }
    void SetY(float value) { SetSchemaValue(m_ptr, "hudtextparms_t", "y", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif