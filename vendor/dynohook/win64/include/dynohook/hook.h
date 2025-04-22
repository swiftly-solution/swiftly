#pragma once

#include "mem_accessor.h"
#include "ihook.h"
#include "platform.h"

#include <asmjit/asmjit.h>
#include <mutex>

namespace dyno {
	/**
	 * Creates and manages hooks at the beginning of a function.
	 * This hooking method requires knowledge of parameters and calling convention of the target function.
	 */
	class DYNO_API Hook : public MemAccessor, public IHook {
	public:
		explicit Hook(const ConvFunc& convention);
		~Hook() override = default;
		DYNO_NONCOPYABLE(Hook)

		bool addCallback(CallbackType type, CallbackHandler handler) override;
		bool removeCallback(CallbackType type, CallbackHandler handler) override;
		bool isCallbackRegistered(CallbackType type, CallbackHandler handler) const override;
		bool areCallbacksRegistered() const override;

		bool rehook() override {
			return true;
		}

		bool setHooked(bool state) override {
			if (m_hooked == state)
				return true;

			return state ? hook() : unhook();
		}

		bool isHooked() const override {
			return m_hooked;
		}

		const uintptr_t& getBridge() const {
			return m_fnBridge;
		}

	protected:
		virtual bool createBridge() = 0;
		virtual bool createPostCallback() = 0;

		ICallingConvention& getCallingConvention() override {
			return *m_callingConvention;
		}
		Registers& getRegisters() override {
			return m_registers;
		}

		typedef asmjit::x86::Assembler Assembler;

		virtual void writeModifyReturnAddress(Assembler& a) = 0;
		virtual void writeCallHandler(Assembler& a, CallbackType type) const = 0;
		virtual int32_t writeSaveScratchRegisters(Assembler& a) const = 0;
		virtual void writeRestoreScratchRegisters(Assembler& a) const = 0;
		virtual void writeSaveRegisters(Assembler& a, bool post) const = 0;
		virtual void writeRestoreRegisters(Assembler& a, bool post) const = 0;
		virtual void writeRegToMem(Assembler& a, const Register& reg, [[maybe_unused]] bool post) const = 0;
		virtual void writeMemToReg(Assembler& a, const Register& reg, [[maybe_unused]] bool post) const = 0;

DYNO_OPTS_OFF
		DYNO_NOINLINE ReturnAction DYNO_CDECL callbackHandler(CallbackType type);
		DYNO_NOINLINE void* DYNO_CDECL getReturnAddress(void* stackPtr);
		DYNO_NOINLINE void DYNO_CDECL setReturnAddress(void* retAddr, void* stackPtr);
DYNO_OPTS_ON

	protected:
		asmjit::JitRuntime m_asmjit_rt;
		std::mutex m_mutex;

		// address storage
		uintptr_t m_fnBridge{ 0 };
		uintptr_t m_newRetAddr{ 0 };
		size_t m_fnBridgeSize{ 0 };
		size_t m_newRetAddrSize{ 0 };

		// interface if the calling convention
		std::unique_ptr<ICallingConvention> m_callingConvention;

		// register storage
		Registers m_registers;

		// save the last return action of the pre callbackHander for use in the post handler.
		std::vector<ReturnAction> m_lastPreReturnAction;

		// individual return's stack for stack pointers
		std::unordered_map<void*, std::vector<void*>> m_retAddr;

		// callbacks list
		std::unordered_map<CallbackType, std::vector<CallbackHandler>> m_handlers;

		bool m_hooked{ false };
	};
}