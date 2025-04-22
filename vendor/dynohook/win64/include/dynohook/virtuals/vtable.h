#pragma once

#include <dynohook/virtuals/vhook.h>

namespace dyno {
	class VHookCache;

	class DYNO_API VTable final : public MemAccessor {
	public:
		VTable(void* pClass, std::shared_ptr<VHookCache> cache);
		~VTable() override;
		DYNO_NONCOPYABLE(VTable);

		std::shared_ptr<Hook> hook(int index, const ConvFunc& convention);
		
		bool unhook(int index);

		std::shared_ptr<Hook> find(int index) const;

		bool empty() const {
			return m_hooked.empty();
		}

		int getVTableIndex(void* pFunc);
		
	private:
		static int getVFuncCount(void** vtable);

		void*** m_class;
		void** m_origVtable;
		int m_vFuncCount;
		std::unique_ptr<void*[]> m_newVtable;

		std::shared_ptr<VHookCache> m_hookCache;

		std::unordered_map<int16_t, std::shared_ptr<VHook>> m_hooked;
	};

	class DYNO_API VHookCache {
	public:
		std::shared_ptr<VHook> get(void* pFunc, const ConvFunc& convention);
		void clear();
		void cleanup();

	private:
		std::unordered_map<void*, std::shared_ptr<VHook>> m_hooked;
	};
}