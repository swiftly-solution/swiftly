#pragma once

namespace dyno {

    class Memory {
    public:
        static void* AllocateMemory(void* address, size_t size);
        static void FreeMemory(void* address, size_t size);
        static size_t GetPageSize();
    };

    // unsafe enum by design to allow binary OR
    enum ProtFlag : uint8_t {
        UNSET = 0, // value means this give no information about protection state (un-read)
        X = 1 << 1,
        R = 1 << 2,
        W = 1 << 3,
        S = 1 << 4,
        P = 1 << 5,
        N = 1 << 6, // value equaling the linux flag PROT_UNSET (read the prot, and the prot is unset)
        RWX = R | W | X
    };

    int	TranslateProtection(ProtFlag flags);
    ProtFlag TranslateProtection(int prot);

    class MemoryProtect {
    public:
        MemoryProtect(void* addr, size_t size, ProtFlag flags);
        ~MemoryProtect();
        NONCOPYABLE(MemoryProtect);

    private:
        bool protect(void* addr, size_t size, ProtFlag flags);

        void* m_address;
        size_t m_size;
        ProtFlag m_flags;
        ProtFlag m_oldProtection;
    };

// Credit to Dogmatt on unknowncheats.me for IsValidPtr
#if DYNO_ARCH_X86 == 64
#define _PTR_MAX_VALUE (void*)0x000F000000000000
#elif DYNO_ARCH_X86 == 32
#define _PTR_MAX_VALUE (void*)0xFFF00000
#endif
#define _PTR_MIN_VALUE (void*)0x10000

    inline bool IsValidPtr(void* ptr) { return (ptr != nullptr) && (ptr >= _PTR_MIN_VALUE) && (ptr < _PTR_MAX_VALUE); }
}

dyno::ProtFlag operator|(dyno::ProtFlag lhs, dyno::ProtFlag rhs);
bool operator&(dyno::ProtFlag lhs, dyno::ProtFlag rhs);
//std::ostream& operator<<(std::ostream& os, dyno::ProtFlag v);