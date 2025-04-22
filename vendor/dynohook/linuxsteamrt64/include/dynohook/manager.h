#pragma once

#include "imanager.h"
#include "convention.h"
#include "virtuals/vtable.h"
#include "detours/nat_detour.h"

#include <asmjit/asmjit.h>
#include <unordered_map>

namespace dyno {
	class HookManager final : public IHookManager {
	private:
		HookManager();
		~HookManager() = default;

	public:
		DYNO_NONCOPYABLE(HookManager);

		std::shared_ptr<IHook> hookDetour(void* pFunc, const ConvFunc& convention) override;
		std::shared_ptr<IHook> hookVirtual(void* pClass, int index, const ConvFunc& convention) override;
		std::shared_ptr<IHook> hookVirtual(void* pClass, void* pFunc, const ConvFunc& convention) override;
		bool unhookDetour(void* pFunc) override;
		bool unhookVirtual(void* pClass, int index) override;
		bool unhookVirtual(void* pClass, void* pFunc) override;
		std::shared_ptr<IHook> findDetour(void* pFunc) const override;
		std::shared_ptr<IHook> findVirtual(void* pClass, int index) const override;
		std::shared_ptr<IHook> findVirtual(void* pClass, void* pFunc) const override;

		void unhookAll() override;
		void unhookAllVirtual(void* pClass) override;
		void clearCache() override;

		friend class IHookManager;

	public:
		std::shared_ptr<VHookCache> m_cache; // used as global storage to avoid creating same hooks
		std::unordered_map<void*, std::unique_ptr<VTable>> m_vtables;
		std::unordered_map<void*, std::shared_ptr<NatDetour>> m_detours;
		std::mutex m_mutex;
	};
}