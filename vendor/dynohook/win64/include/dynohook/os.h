// This file is used to not include os specific functions that might break other projects
// You should use it in sources

#pragma once

#include "platform.h"

#if DYNO_PLATFORM_WINDOWS

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define NTDDI_VERSION NTDDI_WIN10_RS4
#include <windows.h>

// From winerror.h, as this error isn't found in some SDKs:
//
// MessageId: ERROR_DYNAMIC_CODE_BLOCKED
//
// MessageText:
//
// The operation was blocked as the process prohibits dynamic code generation.
//
#ifndef ERROR_DYNAMIC_CODE_BLOCKED
#define ERROR_DYNAMIC_CODE_BLOCKED	   1655L
#endif

#elif DYNO_PLATFORM_LINUX

#include <sys/mman.h>
#include <unistd.h>

#elif DYNO_PLATFORM_APPLE

#include <mach/mach_init.h>
#include <mach/mach_vm.h>
#include <mach/vm_prot.h>
#include <mach/vm_map.h>

#else

#error "Platform is not supported!"

#endif