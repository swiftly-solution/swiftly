#pragma once

#include <cstdint>
#include <type_traits>

namespace dyno {

	// unsafe enum by design to allow binary OR
	enum ProtFlag : uint8_t {
		UNSET = 0, // value means this give no information about protection state (un-read)
		X = 1 << 1,
		R = 1 << 2,
		W = 1 << 3,
		S = 1 << 4,
		P = 1 << 5,
		N = 1 << 6, // value equaling the linux flag PROT_UNSET (read the prot, and the prot is unset)
		RWX = R | W | X
	};

	inline ProtFlag operator|(ProtFlag lhs, ProtFlag rhs) {
		using underlying = typename std::underlying_type<ProtFlag>::type;
		return static_cast<ProtFlag> (
			static_cast<underlying>(lhs) |
			static_cast<underlying>(rhs)
		);
	}

	inline bool operator&(ProtFlag lhs, ProtFlag rhs) {
		using underlying = typename std::underlying_type<ProtFlag>::type;
		return static_cast<underlying>(lhs) &
			   static_cast<underlying>(rhs);
	}
};