#pragma once

/// https://github.com/steinwurf/platform

// here we create a number of defines to make it easy to choose between
// different compilers, operatings systems and CPU architectures.
// some information about the defines used can be found here:
// http://sourceforge.net/p/predef/wiki/Architectures/

// detect operating systems
#if defined(__linux__)
#define DYNO_PLATFORM_LINUX 1
#if defined(__ANDROID__)
#define DYNO_PLATFORM_ANDROID 1
#endif
#elif defined(_WIN32)
#define DYNO_PLATFORM_WINDOWS 1
#if defined(WINAPI_FAMILY)
#include <winapifamily.h>
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP)
#define DYNO_PLATFORM_WINDOWS_PHONE 1
#endif
#endif
#elif defined(__APPLE__)
#define DYNO_PLATFORM_APPLE 1
// detect iOS before MacOSX (__MACH__ is also defined for iOS)
#if defined(IPHONE)
#define DYNO_PLATFORM_IOS 1
#elif defined(__MACH__)
#define DYNO_PLATFORM_MAC 1
#endif
#elif defined(__EMSCRIPTEN__)
#define DYNO_PLATFORM_EMSCRIPTEN 1
#else
#error "Unable to determine operating system"
#endif

// detect compilers and CPU architectures
// note: clang also defines __GNUC__ since it aims to be compatible with GCC.
// therefore we need to check for __clang__ or __llvm__ first.
#if defined(__clang__) || defined(__llvm__)
#define DYNO_PLATFORM_CLANG 1
#define DYNO_PLATFORM_GCC_COMPATIBLE 1
#if defined(__i386__) || defined(__x86_64__)
#define DYNO_PLATFORM_X86 1
#define DYNO_PLATFORM_CLANG_X86 1
#define DYNO_PLATFORM_GCC_COMPATIBLE_X86 1
#elif defined(__arm__) || defined(__arm64__) || defined(__aarch64__)
#define DYNO_PLATFORM_ARM 1
#define DYNO_PLATFORM_CLANG_ARM 1
#define DYNO_PLATFORM_GCC_COMPATIBLE_ARM 1
#elif defined(__mips__)
#define DYNO_PLATFORM_MIPS 1
#define DYNO_PLATFORM_CLANG_MIPS 1
#define DYNO_PLATFORM_GCC_COMPATIBLE_MIPS 1
#elif defined(__asmjs__)
#define DYNO_PLATFORM_ASMJS 1
#define DYNO_PLATFORM_CLANG_ASMJS 1
#define DYNO_PLATFORM_GCC_COMPATIBLE_ASMJS 1
#endif
#elif defined(__GNUC__)
#define DYNO_PLATFORM_GCC 1
#define DYNO_PLATFORM_GCC_COMPATIBLE 1
#if defined(__i386__) || defined(__x86_64__)
#define DYNO_PLATFORM_X86 1
#define DYNO_PLATFORM_GCC_X86 1
#define DYNO_PLATFORM_GCC_COMPATIBLE_X86 1
#elif defined(__arm__) || defined(__arm64__) || defined(__aarch64__)
#define DYNO_PLATFORM_ARM 1
#define DYNO_PLATFORM_GCC_ARM 1
#define DYNO_PLATFORM_GCC_COMPATIBLE_ARM 1
#elif defined(__mips__)
#define DYNO_PLATFORM_MIPS 1
#define DYNO_PLATFORM_GCC_MIPS 1
#define DYNO_PLATFORM_GCC_COMPATIBLE_MIPS 1
#endif
#elif defined(_MSC_VER)
#define DYNO_PLATFORM_MSVC 1
#if defined(_M_IX86) || defined(_M_X64)
#define DYNO_PLATFORM_X86 1
#define DYNO_PLATFORM_MSVC_X86 1
#elif defined(_M_ARM) || defined(_M_ARMT)
#define DYNO_PLATFORM_ARM 1
#define DYNO_PLATFORM_MSVC_ARM 1
#endif
#else
#error "Unable to determine compiler"
#endif

// define macros for supported CPU instruction sets
#if defined(DYNO_PLATFORM_GCC_COMPATIBLE)
#if defined(__MMX__)
#define DYNO_PLATFORM_MMX 1
#endif
#if defined(__SSE__)
#define DYNO_PLATFORM_SSE 1
#endif
#if defined(__SSE2__)
#define DYNO_PLATFORM_SSE2 1
#endif
#if defined(__SSE3__)
#define DYNO_PLATFORM_SSE3 1
#endif
#if defined(__SSSE3__)
#define DYNO_PLATFORM_SSSE3 1
#endif
#if defined(__SSE4_1__)
#define DYNO_PLATFORM_SSE41 1
#endif
#if defined(__SSE4_2__)
#define DYNO_PLATFORM_SSE42 1
#endif
#if defined(__PCLMUL__)
#define DYNO_PLATFORM_PCLMUL 1
#endif
#if defined(__AVX__)
#define DYNO_PLATFORM_AVX 1
#endif
#if defined(__AVX2__)
#define DYNO_PLATFORM_AVX2 1
#endif
#if defined(__ARM_NEON__) || defined(__ARM_NEON)
#define DYNO_PLATFORM_NEON 1
#endif
// first, check the PLATFORM_WINDOWS_PHONE define, because
// the X86 instructions sets are not supported on the Windows Phone emulator
#elif defined(DYNO_PLATFORM_WINDOWS_PHONE)
#if defined(DYNO_PLATFORM_MSVC_ARM)
// NEON introduced in VS2012
#if (_MSC_VER >= 1700)
#define DYNO_PLATFORM_NEON 1
#endif
#endif
#elif defined(DYNO_PLATFORM_MSVC_X86)
// MMX, SSE and SSE2 introduced in VS2003
#if (_MSC_VER >= 1310)
#define DYNO_PLATFORM_MMX 1
#define DYNO_PLATFORM_SSE 1
#define DYNO_PLATFORM_SSE2 1
#endif
// SSE3 introduced in VS2005
#if (_MSC_VER >= 1400)
#define DYNO_PLATFORM_SSE3 1
#endif
// SSSE3, SSE4.1, SSE4.2, PCLMUL introduced in VS2008
#if (_MSC_VER >= 1500)
#define DYNO_PLATFORM_SSSE3 1
#define DYNO_PLATFORM_SSE41 1
#define DYNO_PLATFORM_SSE42 1
#define DYNO_PLATFORM_PCLMUL 1
#endif
// AVX and AVX2 introduced in VS2012
#if (_MSC_VER >= 1700)
#define DYNO_PLATFORM_AVX 1
#define DYNO_PLATFORM_AVX2 1
#endif
#endif
#if defined(__AVX512F__)
#define DYNO_PLATFORM_AVX512 1
#endif

// define macros for architecture type
#if DYNO_PLATFORM_X86
#if UINTPTR_MAX == UINT64_MAX
#define DYNO_ARCH_X86 64
#elif UINTPTR_MAX == UINT32_MAX
#define DYNO_ARCH_X86 32
#else
#error "Unable to determine architecture type"
#endif
#endif

// function attributes
#if !defined(DYNO_BUILD_DEBUG) && defined(__GNUC__)
#define DYNO_FORCE_INLINE inline __attribute__((__always_inline__))
#elif !defined(DYNO_BUILD_DEBUG) && DYNO_PLATFORM_MSVC
#define DYNO_FORCE_INLINE __forceinline
#else
#define DYNO_FORCE_INLINE inline
#endif

#if DYNO_PLATFORM_GCC
#define DYNO_NOINLINE __attribute__((__noinline__))
#define DYNO_NORETURN __attribute__((__noreturn__))
#define DYNO_NAKED	__attribute__((naked))
#elif DYNO_PLATFORM_MSVC
#define DYNO_NOINLINE __declspec(noinline)
#define DYNO_NORETURN __declspec(noreturn)
#define DYNO_NAKED	__declspec(naked)
#else
#define DYNO_NOINLINE
#define DYNO_NORETURN
#define DYNO_NAKED
#endif

// calling conventions
#if DYNO_ARCH_X86 == 32 && DYNO_PLATFORM_GCC
#define DYNO_CDECL __attribute__((__cdecl__))
#define DYNO_STDCALL __attribute__((__stdcall__))
#define DYNO_FASTCALL __attribute__((__fastcall__))
#define DYNO_THISCALL __attribute__((__thiscall__))
#define DYNO_REGPARM(N) __attribute__((__regparm__(N)))
#elif DYNO_ARCH_X86 == 32 && DYNO_PLATFORM_MSVC
#define DYNO_CDECL __cdecl
#define DYNO_STDCALL __stdcall
#define DYNO_FASTCALL __fastcall
#define DYNO_THISCALL __thiscall
#define DYNO_REGPARM(N)
#else
#define DYNO_CDECL
#define DYNO_STDCALL
#define DYNO_FASTCALL
#define DYNO_THISCALL
#define DYNO_REGPARM(N)
#endif

#if DYNO_ARCH_X86 && DYNO_PLATFORM_WINDOWS && DYNO_PLATFORM_MSVC
#define DYNO_VECTORCALL __vectorcall
#elif DYNO_ARCH_X86 && DYNO_PLATFORM_WINDOWS
#define DYNO_VECTORCALL __attribute__((__vectorcall__))
#else
#define DYNO_VECTORCALL
#endif

// optimization
#if DYNO_PLATFORM_GCC_COMPATIBLE && !(defined(DYNO_PLATFORM_CLANG) && DYNO_PLATFORM_CLANG)
#define DYNO_OPTS_OFF _Pragma("GCC push_options") _Pragma("GCC optimize (\"O0\")")
#define DYNO_OPTS_ON _Pragma("GCC pop_options")
#elif DYNO_PLATFORM_MSVC
#define DYNO_OPTS_OFF __pragma(optimize("", off))
#define DYNO_OPTS_ON __pragma(optimize("", on))
#else
#define DYNO_OPTS_OFF
#define DYNO_OPTS_ON
#endif

#define DYNO_UNUSED(a) (void)a
