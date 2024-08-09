#pragma once

#if DYNO_ARCH_X86 == 32

#include "x86MsCdecl.h"

namespace dyno {
    typedef x86MsCdecl x86GccCdecl;
}

#endif // DYNO_ARCH_X86