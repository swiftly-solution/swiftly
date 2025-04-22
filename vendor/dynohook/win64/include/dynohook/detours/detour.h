#pragma once

#include <dynohook/disassembler.h>
#include <dynohook/mem_accessor.h>
#include <dynohook/mem_protector.h>
#include <dynohook/instruction.h>
#include <dynohook/nat_hook.h>
#include <optional>
#include <cassert>

namespace dyno {
	class DYNO_API Detour : public NatHook {
	public:
		Detour(uintptr_t fnAddress, const ConvFunc& convention, Mode mode);
		~Detour() override;

		bool unhook() override;

		/**
			This is for restoring hook bytes if a 3rd party uninstalled them.
			DO NOT call this after unhook(). This may only be called after hook()
			but before unhook()
		**/
		bool rehook() override;

		HookMode getMode() const override {
			return HookMode::Detour;
		}

		virtual Mode getArchType() const = 0;

		uint8_t getMaxDepth() const;

		void setMaxDepth(uint8_t maxDepth);

		void setIsFollowCallOnFnAddress(bool value);

		const uintptr_t& getTarget() const override {
			return m_fnAddress;
		}

		const uintptr_t& getAddress() const override {
			return m_trampoline;
		}

	protected:
		uintptr_t m_fnAddress;
		ZydisDisassembler m_disasm;
		uint8_t m_maxDepth{ 5 };
		bool m_isFollowCallOnFnAddress{ true };  // whether follow 'CALL' destination
		uint16_t m_trampolineSz{ 0 };
		uintptr_t m_trampoline{ 0 };
		insts_t m_originalInsts;

		/*
		 * Save the instructions used for the hook so that we can re-write in rehook()
		 * Note: There's a nop range we store too so that it doesn't need to be re-calculated
		 */
		insts_t m_hookInsts;
		uint16_t m_nopProlOffset{ 0 };
		uint16_t m_nopSize{ 0 };
		uint32_t m_hookSize{ 0 };

		/**
		 * Walks the given vector of instructions and sets roundedSz to the lowest size possible that doesn't split any instructions and is greater than minSz.
		 * If end of function is encountered before this condition an empty optional is returned. Returns instructions in the range start to adjusted end
		 */
		static std::optional<insts_t> calcNearestSz(const insts_t& functionInsts, uintptr_t minSz, uintptr_t& roundedSz);

		/**
		 * If function starts with a jump follow it until the first non-jump instruction, recursively. This handles already hooked functions
		 * and also compilers that emit jump tables on function call. Returns true if resolution was successful (nothing to resolve, or resolution worked),
		 * false if resolution failed.
		 */
		bool followJmp(insts_t& functionInsts, uint8_t curDepth = 0);

		/**
		 * Expand the prologue up to the address of the last jmp that points back into the prologue. This
		 * is necessary because we modify the location of things in the prologue, so re-entrant jmps point
		 * to the wrong place. Therefore we move all of it to the trampoline where there is ample space to
		 * relocate and create jmp tbl entries
		 */
		bool expandProlSelfJmps(insts_t& prol,
			const insts_t& func,
			uintptr_t& minProlSz,
			uintptr_t& roundProlSz
		);

		/**
		 * Insert nops from [Base, Base+size).
		 * Generates as many nop instructions as necessary to fill the give size.
		 * This function ensures that generated nops won't be reused as a code cave by Polyhook.
		 * Hence, it will never emit more than 8 0x90 single byte nops in a row.
		 */
		insts_t make_nops(uintptr_t address, uint16_t size) const;

		static void buildRelocationList(
			insts_t& prologue,
			uintptr_t roundProlSz,
			intptr_t delta,
			insts_t& instsNeedingEntry,
			insts_t& instsNeedingReloc,
			insts_t& instsNeedingTranslation
		);

		/**
		 * Corrects displacement for IP-relative instructions
		 * @return Jump table entries
		 */
		template<typename MakeJmpFn>
		insts_t relocateTrampoline(
			insts_t& prologue,
			uintptr_t jmpTblStart,
			const intptr_t delta,
			MakeJmpFn makeJmp,
			const insts_t& instsNeedingReloc,
			const insts_t& instsNeedingEntry
		) {
			uintptr_t jmpTblCurAddr = jmpTblStart;
			insts_t jmpTblEntries;

			// MIGHT NEED TO REDO ALL THIS JUMP TABLE STUFF IT's CONFUSING - needlessly
			for (auto& inst: prologue) {

				if (std::find(instsNeedingEntry.begin(), instsNeedingEntry.end(), inst) != instsNeedingEntry.end()) {
					assert(inst.hasDisplacement());
					// make an entry pointing to where inst did point to
					auto entry = makeJmp(jmpTblCurAddr, inst);

					// Move to next entry, some jmp types can emit more than one instruction
					jmpTblCurAddr += calcInstsSz(entry);

					writeEncoding(entry);
					jmpTblEntries.insert(jmpTblEntries.end(), entry.begin(), entry.end());
				} else if (std::find(instsNeedingReloc.begin(), instsNeedingReloc.end(), inst) != instsNeedingReloc.end()) {
					assert(inst.hasDisplacement());

					const uintptr_t instsOldDest = inst.getDestination();
					inst.setAddress(inst.getAddress() + delta);
					inst.setDestination(instsOldDest);
				} else {
					inst.setAddress(inst.getAddress() + delta);
				}

				writeEncoding(inst);
			}
			return jmpTblEntries;
		}
	};
}