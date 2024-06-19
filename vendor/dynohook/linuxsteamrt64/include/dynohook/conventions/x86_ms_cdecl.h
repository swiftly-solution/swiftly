#pragma once

#include <dynohook/convention.h>

/*
	Source: DynCall manual and Windows docs

	Registers:
		- eax = return value
		- edx = return value
		- esp = stack pointer
		- st0 = floating point return value

	Parameter passing:
		- stack parameter order: right-to-left
		- caller cleans up the stack
		- all arguments are pushed onto the stack
		- alignment: 4 bytes

	Return values:
		- return values of pointer or intergral type (<= 32 bits) are returned via the eax register
		- integers > 32 bits are returned via the eax and edx registers
		- floating pointer types are returned via the st0 register
*/
namespace dyno {
	class DYNO_API x86MsCdecl : public ICallingConvention {
	public:
		x86MsCdecl(std::vector<DataObject> arguments, DataObject returnType, size_t alignment = 4);
		~x86MsCdecl() override;

		regs_t getRegisters() override;
		void** getStackArgumentPtr(const Registers& registers) override;

		void* getArgumentPtr(size_t index, const Registers& registers) override;
		void onArgumentPtrChanged(size_t index, const Registers& registers, void* argumentPtr) override;

		void* getReturnPtr(const Registers& registers) override;
		void onReturnPtrChanged(const Registers& registers, void* returnPtr) override;

	private:
		void* m_returnBuffer;
	};
}