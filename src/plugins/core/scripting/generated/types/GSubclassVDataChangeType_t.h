#ifndef _gsubclassvdatachangetype_t_h
#define _gsubclassvdatachangetype_t_h

enum class SubclassVDataChangeType_t : uint64_t
{
    SUBCLASS_VDATA_CREATED = 0x0,
    SUBCLASS_VDATA_SUBCLASS_CHANGED = 0x1,
    SUBCLASS_VDATA_RELOADED = 0x2,
};

#endif