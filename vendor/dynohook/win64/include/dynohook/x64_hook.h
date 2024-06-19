#pragma once

#include <dynohook/hook.h>

namespace dyno {
	class DYNO_API x64Hook : public Hook {
	public:
		explicit x64Hook(const ConvFunc& convention);
		~x64Hook() override = default;

	protected:
		bool createBridge() override;
		bool createPostCallback() override;
		void writeModifyReturnAddress(Assembler& a) override;
		void writeCallHandler(Assembler& a, CallbackType type) const override;
		int32_t writeSaveScratchRegisters(Assembler& a) const override;
		void writeRestoreScratchRegisters(Assembler& a) const override;
		void writeSaveRegisters(Assembler& a, bool post) const override;
		void writeRestoreRegisters(Assembler& a, bool post) const override;
		void writeRegToMem(Assembler& a, const Register& reg, bool post) const override;
		void writeMemToReg(Assembler& a, const Register& reg, bool post) const override;
	};
}