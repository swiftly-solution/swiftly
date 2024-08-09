#pragma once

#if DYNO_ARCH_X86 == 32

#include "dynohook/convention.h"
#include "x86MsCdecl.h"

namespace dyno {
    typedef x86MsCdecl x86GccThiscall;
}

#endif // DYNO_ARCH_X86