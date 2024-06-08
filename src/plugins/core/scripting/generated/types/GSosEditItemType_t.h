#ifndef _gsosedititemtype_t_h
#define _gsosedititemtype_t_h

enum class SosEditItemType_t : uint64_t
{
    SOS_EDIT_ITEM_TYPE_SOUNDEVENTS = 0x0,
    SOS_EDIT_ITEM_TYPE_SOUNDEVENT = 0x1,
    SOS_EDIT_ITEM_TYPE_LIBRARYSTACKS = 0x2,
    SOS_EDIT_ITEM_TYPE_STACK = 0x3,
    SOS_EDIT_ITEM_TYPE_OPERATOR = 0x4,
    SOS_EDIT_ITEM_TYPE_FIELD = 0x5,
};

#endif