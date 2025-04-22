#pragma once

#include "platform.h"

#if DYNO_ARCH_X86 == 32
#include <dynohook/x86_hook.h>
#elif DYNO_ARCH_X86 == 64
#include <dynohook/x64_hook.h>
#endif

namespace dyno {
#if DYNO_ARCH_X86 == 32
	using NatHook = x86Hook;
#elif DYNO_ARCH_X86 == 64
	using NatHook = x64Hook;
#endif
}