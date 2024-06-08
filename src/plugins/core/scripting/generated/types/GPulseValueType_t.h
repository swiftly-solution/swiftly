#ifndef _gpulsevaluetype_t_h
#define _gpulsevaluetype_t_h

enum class PulseValueType_t : uint64_t
{
    PVAL_INVALID = 0xffffffffffffffff,
    PVAL_BOOL = 0x0,
    PVAL_INT = 0x1,
    PVAL_FLOAT = 0x2,
    PVAL_STRING = 0x3,
    PVAL_VEC3 = 0x4,
    PVAL_TRANSFORM = 0x5,
    PVAL_COLOR_RGB = 0x6,
    PVAL_EHANDLE = 0x7,
    PVAL_RESOURCE = 0x8,
    PVAL_SNDEVT_GUID = 0x9,
    PVAL_ENTITY_NAME = 0xa,
    PVAL_OPAQUE_HANDLE = 0xb,
    PVAL_TYPESAFE_INT = 0xc,
    PVAL_CURSOR_FLOW = 0xd,
    PVAL_ANY = 0xe,
    PVAL_SCHEMA_ENUM = 0xf,
    PVAL_PANORAMA_PANEL_HANDLE = 0x10,
    PVAL_TEST_HANDLE = 0x11,
    PVAL_COUNT = 0x12,
};

#endif