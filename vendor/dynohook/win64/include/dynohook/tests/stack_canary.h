#pragma once

#include <cstdint>

namespace dyno {
	class DYNO_API StackCanary {
	public:
		StackCanary();
		~StackCanary() noexcept(false);

		bool isStackGood();
		
	private:
		uint8_t buf[100];
	};
}