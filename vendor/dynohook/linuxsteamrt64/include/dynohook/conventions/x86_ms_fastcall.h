#pragma once

#include <dynohook/convention.h>
#include "x86_ms_stdcall.h"

/*
	Source: DynCall manual and Windows docs

	Registers:
		- eax = return value
		- edx = return value
		- esp = stack pointer
		- st0 = floating point return value

	Parameter passing:
		- first parameter in ecx, second parameter in edx, rest on the stack
		- stack parameter order: right-to-left
		- callee cleans up the stack
		- alignment: 4 bytes

	Return values:
		- return values of pointer or intergral type (<= 32 bits) are returned via the eax register
		- integers > 32 bits are returned via the eax and edx registers
		- floating pointer types are returned via the st0 register
*/
namespace dyno {
	class DYNO_API x86MsFastcall : public x86MsStdcall {
	public:
		x86MsFastcall(std::vector<DataObject> arguments, DataObject returnType, size_t alignment = 4);
		~x86MsFastcall() override = default;
	};
}