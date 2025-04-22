// https://www.codeproject.com/Articles/1272619/A-Fixed-Block-Memory-Allocator-in-C
//
// The fb_allocator is a fixed block memory allocator that handles a 
// single block size. 
//
#pragma once

#include "mem_accessor.h"

typedef void* ALLOC_HANDLE;

typedef struct  {
	void* pNext;
} ALLOC_Block;

typedef struct {
	const char* name;
	const char* pPool;
	const size_t objectSize;
	const size_t blockSize;
	const uint32_t maxBlocks;
	ALLOC_Block* pHead;
	uint16_t poolIndex;
	uint16_t blocksInUse;
	uint16_t maxBlocksInUse;
	uint16_t allocations;
	uint16_t deallocations;
} ALLOC_Allocator;

// Align fixed blocks on X-byte boundary based on CPU architecture.
// Set value to 1, 2, 4 or 8.
#define ALLOC_MEM_ALIGN (1)

// Get the maximum between a or b
#define ALLOC_MAX(a,b) (((a)>(b))?(a):(b))

// Ensure the memory block size is: (a) is aligned on desired boundary and (b) at
// least the size of a ALLOC_Allocator*. 
#define ALLOC_BLOCK_SIZE(_size_) \
	(ALLOC_MAX((MEMORY_ROUND_UP(_size_, ALLOC_MEM_ALIGN)), sizeof(ALLOC_Allocator*)))

// Defines block memory, allocator instance and a handle. On the example below, 
// the ALLOC_Allocator instance is myAllocatorObj and the handle is myAllocator.
// _name_ - the allocator name
// _size_ - fixed memory block size in bytes
// _objects_ - number of fixed memory blocks 
// e.g. ALLOC_DEFINE(myAllocator, 32, 10)
#define ALLOC_DEFINE(_name_, _size_, _objects_) \
	static char _name_##Memory[ALLOC_BLOCK_SIZE(_size_) * (_objects_)] = { 0 }; \
	static ALLOC_Allocator _name_##Obj = { #_name_, _name_##Memory, _size_, \
		ALLOC_BLOCK_SIZE(_size_), _objects_, NULL, 0, 0, 0, 0, 0 }; \
	static ALLOC_HANDLE _name_ = &_name_##Obj;

namespace dyno {
	// wrapper over fb_allocator in C, with heap backing from VirtualAlloc2 to enforce range
	class DYNO_API FBAllocator final {
	public:
		FBAllocator(uintptr_t min, uintptr_t max, uint8_t blockSize, uint8_t blockCount);
		~FBAllocator();
		
		bool initialize();

		char* allocate();

		char* callocate(uint8_t num);

		void deallocate(char* mem);

		bool inRange(uintptr_t addr) const;

		bool intersectsRange(uintptr_t min, uintptr_t max) const;

		// if a range intersections, by what % of the given range is the overlap
		uint8_t intersectionLoadFactor(uintptr_t min, uintptr_t max) const;
		
	private:
		bool m_alloc2Supported;
		uint8_t m_usedBlocks;
		uint8_t m_maxBlocks;
		uint8_t m_blockSize;
		uintptr_t m_min;
		uintptr_t m_max;
		uintptr_t m_dataPool;

		std::unique_ptr<ALLOC_Allocator> m_allocator;
	};
}
