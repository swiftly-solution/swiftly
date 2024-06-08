#ifndef _gpulsedomainvaluetype_t_h
#define _gpulsedomainvaluetype_t_h

enum class PulseDomainValueType_t : uint64_t
{
    INVALID = 0xffffffffffffffff,
    ENTITY_NAME = 0x0,
    PANEL_ID = 0x1,
    COUNT = 0x2,
};

#endif