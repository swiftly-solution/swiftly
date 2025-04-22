#pragma once

#include "prot.h"

namespace dyno {
	class MemAccessor;

	DYNO_API int TranslateProtection(ProtFlag flags);
	DYNO_API ProtFlag TranslateProtection(int prot);

	class DYNO_API MemProtector {
	public:
		MemProtector() = delete;
		MemProtector(uintptr_t address, size_t length, ProtFlag prot, MemAccessor& accessor, bool unsetOnDestroy = true);
		~MemProtector();
		
		ProtFlag originalProt() const {
			return m_origProtection;
		}

		bool isGood() const {
			return m_status;
		}

	private:
		MemAccessor& m_accessor;

		uintptr_t m_address;
		size_t m_length;
		bool m_status;
		bool m_unsetLater;
		
		ProtFlag m_origProtection{ ProtFlag::UNSET };
	};
}

//std::ostream& operator<<(std::ostream& os, dyno::ProtFlag v);