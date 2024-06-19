#pragma once

#include <dynohook/detours/detour.h>

namespace dyno {
	class DYNO_API x86Detour final : public Detour {
	public:
		x86Detour(uintptr_t fnAddress, const ConvFunc& convention);
		~x86Detour() override = default;

		virtual bool hook() override;

		Mode getArchType() const override;

	protected:
		bool makeTrampoline(insts_t& prologue, insts_t& trampolineOut);
	};
}