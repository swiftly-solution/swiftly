#pragma once

#include "platform.h"
#include <iostream>
#include <iomanip>
#include <cassert>

#include <dynohook_export.h>

namespace dyno {
	template<typename T>
	std::string int_to_hex(T i) {
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(sizeof(T) * 2) << std::hex
			   << (uintptr_t) i; // We cast to the highest possible int because uint8_t will be printed as char

		return stream.str();
	}

	//http://stackoverflow.com/questions/4840410/how-to-align-a-pointer-in-c
	static inline uintptr_t AlignUpwards(uintptr_t stack, size_t align) {
		assert(align > 0 && (align & (align - 1)) == 0); /* Power of 2 */
		assert(stack != 0);

		auto addr = stack;
		if (addr % align != 0)
			addr += align - (addr % align);
		assert(addr >= stack);
		return addr;
	}

	static inline uintptr_t AlignDownwards(uintptr_t stack, size_t align) {
		assert(align > 0 && (align & (align - 1)) == 0); /* Power of 2 */
		assert(stack != 0);

		auto addr = stack;
		addr -= addr % align;
		assert(addr <= stack);
		return addr;
	}

	//Credit to Dogmatt on unknowncheats.me for IsValidPtr
	// and https://docs.microsoft.com/en-us/windows-hardware/drivers/gettingstarted/virtual-address-spaces
	#if DYNO_ARCH_X86 == 64
	#define VALID_MAX_MEMORY_ADDRESS ((void*)0x000F000000000000)
	#else
	#define VALID_MAX_MEMORY_ADDRESS ((void*)0xFFF00000)
	#endif // DYNO_PLATFORM_WINDOWS
	#define VALID_MIN_MEMORY_ADDRESS ((void*)0x10000)

	inline bool isValidPtr(void* p) { return (p >= VALID_MIN_MEMORY_ADDRESS) && (p < VALID_MAX_MEMORY_ADDRESS) && p != nullptr; }

	inline bool isMatch(const char* addr, const char* pat, const char* msk) {
		size_t n = 0;
		while (addr[n] == pat[n] || msk[n] == (uint8_t)'?') {
			if (!msk[++n]) {
				return true;
			}
		}
		return false;
	}

#define INRANGE(x,a,b)	(x >= a && x <= b)
#define getBits(x)		(INRANGE(x,'0','9') ? (x - '0') : ((x&(~0x20)) - 'A' + 0xa))
#define getByte(x)		(getBits(x[0]) << 4 | getBits(x[1]))

	constexpr uint8_t FINDPATTERN_SCRATCH_SIZE = 64;

	// https://github.com/learn-more/findpattern-bench/blob/master/patterns/learn_more.h
	// must use space between bytes and ?? for wildcards. Do not add 0x prefix
	DYNO_API uintptr_t findPattern(uintptr_t rangeStart, size_t len, const char* pattern);
	DYNO_API uintptr_t findPattern_rev(uintptr_t rangeStart, size_t len, const char* pattern);
	DYNO_API uintptr_t getPatternSize(const char* pattern);

	DYNO_API bool boundedAllocSupported();
	DYNO_API uintptr_t boundAlloc(uintptr_t min, uintptr_t max, size_t size);
	DYNO_API uintptr_t boundAllocLegacy(uintptr_t min, uintptr_t max, size_t size);
	DYNO_API void boundAllocFree(uintptr_t address, size_t size);
	DYNO_API size_t getAllocationAlignment();
	DYNO_API size_t getPageSize();

#if DYNO_ARCH_X86 == 64
	DYNO_API uint64_t calc_2gb_below(uint64_t address);
	DYNO_API uint64_t calc_2gb_above(uint64_t address);
#endif // DYNO_ARCH_X86

	// we cannot return a char array from a function, therefore we need a wrapper
	template<size_t N>
	struct String {
		char c[N];
	};

	template<size_t N, size_t L>
	constexpr auto repeat_n(const char (&pattern)[L]) {
		static_assert(N != 0, "Size is empty!");
		static_assert(L != 3, "Length is invalid!");
		constexpr auto length = L - 1;
		constexpr auto size = N * length;
		constexpr auto last = size - 1;

		String<size> result = {};
		for (size_t i = 0; i < last; i += length) {
			for (size_t j = 0; j < length; j++) {
				result.c[i + j] = pattern[j];
			}
		}
		result.c[last] = '\0';
		return result;
	}

	template<size_t ...L>
	constexpr auto concat(const char (&...strings)[L]) {
		constexpr size_t N = (... + L) - sizeof...(L);
		String<N + 1> result = {};
		result.c[N] = '\0';

		char* dst = result.c;
		for (const char* src : {strings...}) {
			for (; *src != '\0'; src++, dst++) {
				*dst = *src;
			}
		}
		return result;
	}
}