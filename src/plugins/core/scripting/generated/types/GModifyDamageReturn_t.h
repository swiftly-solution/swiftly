#ifndef _gmodifydamagereturn_t_h
#define _gmodifydamagereturn_t_h

enum class ModifyDamageReturn_t : uint64_t
{
    CONTINUE_TO_APPLY_DAMAGE = 0x0,
    ABORT_DO_NOT_APPLY_DAMAGE = 0x1,
};

#endif