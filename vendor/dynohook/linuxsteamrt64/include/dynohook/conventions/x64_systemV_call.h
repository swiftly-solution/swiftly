#pragma once

#include <dynohook/convention.h>

/*
	Source: DynCall manual and System V docs

	Registers:
		- rax = return value
		- rdx = return value
		- rsp = stack pointer
		- [xyz]mm0 = floating point return value
		- [xyz]mm1 = floating point return value

	Parameter passing:
		- rdi, rsi, rdx, rcx, r8, r9, rest on the stack
		- [xyz]mm0-[xyz]mm7 used for passing floating values
		- stack parameter order: right-to-left
		- caller cleans up the stack
		- alignment: 8 bytes

	Return values:
		- return values of pointer or intergral type (<= 64 bits) are returned via the rax register
		- integers > 64 bits are returned via the rax and rdx registers
		- floating pointer types are returned via the xmm0 and xmm1 register
*/
namespace dyno {
	class DYNO_API x64SystemVcall : public ICallingConvention {
	public:
		x64SystemVcall(std::vector<DataObject> arguments, DataObject returnType, size_t alignment = SIZE_QWORD);
		~x64SystemVcall() override;

		regs_t getRegisters() override;
		void** getStackArgumentPtr(const Registers &registers) override;

		void* getArgumentPtr(size_t index, const Registers& registers) override;
		void onArgumentPtrChanged(size_t index, const Registers& registers, void* argumentPtr) override;

		void* getReturnPtr(const Registers& registers) override;
		void onReturnPtrChanged(const Registers& registers, void* returnPtr) override;

	private:
		void* m_returnBuffer;
	};
}