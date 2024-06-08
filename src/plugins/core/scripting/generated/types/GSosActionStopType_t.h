#ifndef _gsosactionstoptype_t_h
#define _gsosactionstoptype_t_h

enum class SosActionStopType_t : uint64_t
{
    SOS_STOPTYPE_NONE = 0x0,
    SOS_STOPTYPE_TIME = 0x1,
    SOS_STOPTYPE_OPVAR = 0x2,
};

#endif