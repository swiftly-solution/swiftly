#pragma once

#include "instruction.h"
#include "prot.h"
#include <memory>

#define MEMORY_ROUND(_numToRound_, _multiple_) \
	(_numToRound_ & (((size_t)-1) ^ (_multiple_ - 1)))

// Round _numToRound_ to the next higher _multiple_
#define MEMORY_ROUND_UP(_numToRound_, _multiple_) \
	((_numToRound_ + (_multiple_ - 1)) & (((size_t)-1) ^ (_multiple_ - 1)))

namespace dyno {
	/// Overriding these routines can allow cross-process/cross-arch hooks
	class DYNO_API MemAccessor {
	public:
		virtual ~MemAccessor() = default;

		/**
		 * Defines a memory read/write routine that may fail ungracefully. It's expected
		 * this library will only ever use this routine in cases that are expected to succeed.
		 */
		virtual bool mem_copy(uintptr_t dest, uintptr_t src, size_t size) const;

		/**
		 * Defines a memory write routine that will not throw exceptions, and can handle potential
		 * writes to NO_ACCESS or otherwise innaccessible memory pages. Defaults to writeprocessmemory.
		 * Must fail gracefully
		 */
		virtual bool safe_mem_write(uintptr_t dest, uintptr_t src, size_t size, size_t& written) const noexcept;

		/**
		 * Defines a memory read routine that will not throw exceptions, and can handle potential
		 * reads from NO_ACCESS or otherwise innaccessible memory pages. Defaults to readprocessmemory.
		 * Must fail gracefully
		 */
		virtual bool safe_mem_read(uintptr_t src, uintptr_t dest, size_t size, size_t& read) const noexcept;

		virtual ProtFlag mem_protect(uintptr_t dest, size_t size, ProtFlag newProtection, bool& status) const;

	public:
		void writeEncoding(const insts_t& instructions);

		/**
		 * Write the raw bytes of the given instruction into the memory specified by the
		 * instruction's address. If the address value of the instruction has been changed
		 * since the time it was decoded this will copy the instruction to a new memory address.
		 * This will not automatically do any code relocation, all relocation logic should
		 * first modify the byte array, and then call write encoding, proper order to relocate
		 * an instruction should be disasm instructions -> set relative/absolute displacement() ->
		 */
		void writeEncoding(const Instruction& instruction);

	protected:

		/**
		 * Write a 25 byte absolute jump. This is preferred since it doesn't require an indirect memory holder.
		 * We first sub rsp by 128 bytes to avoid the red-zone stack space. This is specific to unix only afaik.
		 */
		insts_t makex64PreferredJump(uintptr_t address, uintptr_t destination);

		/**
		 * Write an indirect style 6byte jump. Address is where the jmp instruction will be located, and
		 * destHolder should point to the memory location that *CONTAINS* the address to be jumped to.
		 * Destination should be the value that is written into destHolder, and be the address of where
		 * the jmp should land.
		 */
		insts_t makex64MinimumJump(uintptr_t address, uintptr_t destination, uintptr_t destHolder);
		insts_t makex86Jmp(uintptr_t address, uintptr_t destination);
		insts_t makex64Jump(uintptr_t address, uintptr_t destination);
		insts_t makeAgnosticJmp(uintptr_t address, uintptr_t destination);

		insts_t makex64DestHolder(uintptr_t destination, uintptr_t destHolder);

	};
}