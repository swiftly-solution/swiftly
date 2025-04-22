#pragma once

#include <dynohook/convention.h>

/*
	Source: DynCall manual and Windows docs

	Registers:
		- rax = return value
		- rsp = stack pointer
		- xmm0 = floating point return value

	Parameter passing:
		- first parameter in rcx/xmm0, second parameter in rdx/xmm1, third parameter in r8/xmm2, forth parameter in r9/xmm3, rest on the stack
		- stack parameter order: right-to-left
		- caller cleans up the stack
		- alignment: 8 bytes
		- shadow space: 32 bytes (for arguments)

	Return values:
		- return values of pointer or intergral type (<= 64 bits) are returned via the rax register
		- integers > 64 bits are returned via the rax registers as pointers
		- floating pointer types are returned via the xmm0 register
*/
namespace dyno {
	class DYNO_API x64WindowsCall : public ICallingConvention {
	public:
		x64WindowsCall(std::vector<DataObject> arguments, DataObject returnType, size_t alignment = SIZE_QWORD);
		~x64WindowsCall() override = default;

		regs_t getRegisters() override;
		void** getStackArgumentPtr(const Registers &registers) override;

		void* getArgumentPtr(size_t index, const Registers& registers) override;
		void onArgumentPtrChanged(size_t index, const Registers& registers, void* argumentPtr) override;

		void* getReturnPtr(const Registers& registers) override;
		void onReturnPtrChanged(const Registers& registers, void* returnPtr) override;
	};
}