#pragma once

#include "helpers.h"
#include <cstdint>
#include <memory>
#include <mutex>
#include <vector>
#include <unordered_map>

namespace dyno {
	class FBAllocator;
	class DYNO_API RangeAllocator {
	public:
		RangeAllocator(uint8_t blockSize, uint8_t blockCount);
		~RangeAllocator() = default;
		DYNO_NONCOPYABLE(RangeAllocator);

		char* allocate(uintptr_t min, uintptr_t max);
		void deallocate(uintptr_t addr);
		
	private:
		std::shared_ptr<FBAllocator> findOrInsertAllocator(uintptr_t min, uintptr_t max);

		uint8_t m_maxBlocks;
		uint8_t m_blockSize;
		std::mutex m_mutex;
		std::vector<std::shared_ptr<FBAllocator>> m_allocators;
		std::unordered_map<uintptr_t, std::shared_ptr<FBAllocator>> m_allocMap;
	};
}