#ifndef _gcompositematerialmatchfiltertype_t_h
#define _gcompositematerialmatchfiltertype_t_h

enum class CompositeMaterialMatchFilterType_t : uint64_t
{
    MATCH_FILTER_MATERIAL_ATTRIBUTE_EXISTS = 0x0,
    MATCH_FILTER_MATERIAL_SHADER = 0x1,
    MATCH_FILTER_MATERIAL_NAME_SUBSTR = 0x2,
    MATCH_FILTER_MATERIAL_ATTRIBUTE_EQUALS = 0x3,
    MATCH_FILTER_MATERIAL_PROPERTY_EXISTS = 0x4,
    MATCH_FILTER_MATERIAL_PROPERTY_EQUALS = 0x5,
};

#endif