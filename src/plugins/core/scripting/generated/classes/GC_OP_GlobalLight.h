class GC_OP_GlobalLight;

#ifndef _gcc_op_globallight_h
#define _gcc_op_globallight_h

#include "../../../scripting.h"




class GC_OP_GlobalLight
{
private:
    void *m_ptr;

public:
    GC_OP_GlobalLight() {}
    GC_OP_GlobalLight(void *ptr) : m_ptr(ptr) {}

    float GetScale() const { return GetSchemaValue<float>(m_ptr, "C_OP_GlobalLight", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "C_OP_GlobalLight", "m_flScale", false, value); }
    bool GetClampLowerRange() const { return GetSchemaValue<bool>(m_ptr, "C_OP_GlobalLight", "m_bClampLowerRange"); }
    void SetClampLowerRange(bool value) { SetSchemaValue(m_ptr, "C_OP_GlobalLight", "m_bClampLowerRange", false, value); }
    bool GetClampUpperRange() const { return GetSchemaValue<bool>(m_ptr, "C_OP_GlobalLight", "m_bClampUpperRange"); }
    void SetClampUpperRange(bool value) { SetSchemaValue(m_ptr, "C_OP_GlobalLight", "m_bClampUpperRange", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif