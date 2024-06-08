class GCGlowSprite;

#ifndef _gccglowsprite_h
#define _gccglowsprite_h

#include "../../../scripting.h"




class GCGlowSprite
{
private:
    void *m_ptr;

public:
    GCGlowSprite() {}
    GCGlowSprite(void *ptr) : m_ptr(ptr) {}

    Vector GetColor() const { return GetSchemaValue<Vector>(m_ptr, "CGlowSprite", "m_vColor"); }
    void SetColor(Vector value) { SetSchemaValue(m_ptr, "CGlowSprite", "m_vColor", false, value); }
    float GetHorzSize() const { return GetSchemaValue<float>(m_ptr, "CGlowSprite", "m_flHorzSize"); }
    void SetHorzSize(float value) { SetSchemaValue(m_ptr, "CGlowSprite", "m_flHorzSize", false, value); }
    float GetVertSize() const { return GetSchemaValue<float>(m_ptr, "CGlowSprite", "m_flVertSize"); }
    void SetVertSize(float value) { SetSchemaValue(m_ptr, "CGlowSprite", "m_flVertSize", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif