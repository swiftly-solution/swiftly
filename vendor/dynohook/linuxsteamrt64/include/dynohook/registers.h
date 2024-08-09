#pragma once

namespace dyno {
    enum RegisterType : uint8_t {
        // no register at all.
        NONE,

        // ========================================================================
        // >> 8-bit General purpose registers
        // ========================================================================
        AL,
        CL,
        DL,
        BL,

#if DYNO_ARCH_X86 == 64
        SPL,
        BPL,
        SIL,
        DIL,
        R8B,
        R9B,
        R10B,
        R11B,
        R12B,
        R13B,
        R14B,
        R15B,
#endif // DYNO_ARCH_X86

        AH,
        CH,
        DH,
        BH,

        // ========================================================================
        // >> 16-bit General purpose registers
        // ========================================================================
        AX,
        CX,
        DX,
        BX,
        SP,
        BP,
        SI,
        DI,

#if DYNO_ARCH_X86 == 64
        R8W,
        R9W,
        R10W,
        R11W,
        R12W,
        R13W,
        R14W,
        R15W,
#endif // DYNO_ARCH_X86

        // ========================================================================
        // >> 32-bit General purpose registers
        // ========================================================================
        EAX,
        ECX,
        EDX,
        EBX,
        ESP,
        EBP,
        ESI,
        EDI,

#if DYNO_ARCH_X86 == 64
        R8D,
        R9D,
        R10D,
        R11D,
        R12D,
        R13D,
        R14D,
        R15D,
#endif // DYNO_ARCH_X86

        // ========================================================================
        // >> 64-bit General purpose registers
        // ========================================================================
#if DYNO_ARCH_X86 == 64
        RAX,
        RCX,
        RDX,
        RBX,
        RSP,
        RBP,
        RSI,
        RDI,

        R8,
        R9,
        R10,
        R11,
        R12,
        R13,
        R14,
        R15,
#endif // DYNO_ARCH_X86

        // ========================================================================
        // >> 64-bit MM (MMX) registers
        // ========================================================================
        MM0,
        MM1,
        MM2,
        MM3,
        MM4,
        MM5,
        MM6,
        MM7,

        // ========================================================================
        // >> 128-bit XMM registers
        // ========================================================================
        XMM0,
        XMM1,
        XMM2,
        XMM3,
        XMM4,
        XMM5,
        XMM6,
        XMM7,
#if DYNO_ARCH_X86 == 64
        XMM8,
        XMM9,
        XMM10,
        XMM11,
        XMM12,
        XMM13,
        XMM14,
        XMM15,
#ifdef DYNO_PLATFORM_AVX512
        XMM16,
        XMM17,
        XMM18,
        XMM19,
        XMM20,
        XMM21,
        XMM22,
        XMM23,
        XMM24,
        XMM25,
        XMM26,
        XMM27,
        XMM28,
        XMM29,
        XMM30,
        XMM31,
#endif // DYNO_PLATFORM_AVX512
#endif // DYNO_ARCH_X86

        // ========================================================================
        // >> 256-bit YMM registers
        // ========================================================================
#if DYNO_ARCH_X86 == 64
        YMM0,
        YMM1,
        YMM2,
        YMM3,
        YMM4,
        YMM5,
        YMM6,
        YMM7,
        YMM8,
        YMM9,
        YMM10,
        YMM11,
        YMM12,
        YMM13,
        YMM14,
        YMM15,
#ifdef DYNO_PLATFORM_AVX512
        YMM16,
        YMM17,
        YMM18,
        YMM19,
        YMM20,
        YMM21,
        YMM22,
        YMM23,
        YMM24,
        YMM25,
        YMM26,
        YMM27,
        YMM28,
        YMM29,
        YMM30,
        YMM31,
#endif // DYNO_PLATFORM_AVX512
#endif // DYNO_ARCH_X86

        // ========================================================================
        // >> 512-bit ZMM registers
        // ========================================================================
#ifdef DYNO_PLATFORM_AVX512
        ZMM0,
        ZMM1,
        ZMM2,
        ZMM3,
        ZMM4,
        ZMM5,
        ZMM6,
        ZMM7,
        ZMM8,
        ZMM9,
        ZMM10,
        ZMM11,
        ZMM12,
        ZMM13,
        ZMM14,
        ZMM15,
        ZMM16,
        ZMM17,
        ZMM18,
        ZMM19,
        ZMM20,
        ZMM21,
        ZMM22,
        ZMM23,
        ZMM24,
        ZMM25,
        ZMM26,
        ZMM27,
        ZMM28,
        ZMM29,
        ZMM30,
        ZMM31,
#endif // DYNO_PLATFORM_AVX512

        // ========================================================================
        // >> 16-bit Segment registers
        // ========================================================================
        CS,
        SS,
        DS,
        ES,
        FS,
        GS,

        // ========================================================================
        // >> 80-bit FPU registers
        // ========================================================================
#if DYNO_ARCH_X86 == 32
        ST0,
        ST1,
        ST2,
        ST3,
        ST4,
        ST5,
        ST6,
        ST7,
#endif // DYNO_ARCH_X86

        // ========================================================================
        // >> Maximum value of this enum.
        // ========================================================================
        REG_COUNT
    };

    enum RegisterSize : uint8_t {
        SIZE_INVALID = 0,
        SIZE_BYTE = 1,
        SIZE_WORD = 2,
        SIZE_DWORD = 4,
        SIZE_QWORD = 8,
        SIZE_TWORD = 10,
        SIZE_XMMWORD = 16,
        SIZE_YMMWORD = 32,
        SIZE_ZMMWORD = 64
    };

    struct RegisterInfo {
        std::string_view name;
        RegisterSize size;
        uint8_t alignment;
    };

    const RegisterInfo& RegisterTypeInfo(RegisterType regType);

    size_t RegisterTypeToSSEIndex(RegisterType regType);
    RegisterType SSEIndexToRegisterType(size_t index, size_t size = 0);

    class Register {
    public:
        Register(RegisterType type, RegisterSize size, uint8_t alignment = 0);
        ~Register();
        Register(const Register& other);
        Register(Register&& other) noexcept;
        Register& operator=(const Register&) = delete;
        Register& operator=(Register&&) = delete;

        void* operator*() const {
            return m_address;
        }

        template<class T>
        T getAddress() const {
            return (T) m_address;
        }

        template<class T>
        T getValue() const {
            return *(T*) m_address;
        }

        template<class T>
        void setValue(T value) {
            *(T*) m_address = value;
        }

        template<class T>
        T getPointerValue(size_t offset = 0) const {
            return *(T*) (getValue<uintptr_t>() + offset);
        }

        template<class T>
        void setPointerValue(T value, size_t offset = 0) {
            *(T*) (getValue<uintptr_t>() + offset) = value;
        }

        RegisterType getType() const {
            return m_type;
        }

        operator RegisterType() const {
            return m_type;
        }

    private:
        void* m_address;
        RegisterType m_type;
        RegisterSize m_size;
        uint8_t m_alignment;
    };

    class Registers {
    public:
        Registers(const std::vector<RegisterType>& registers);
        ~Registers() = default;
        NONCOPYABLE(Registers);

        ITERATABLE(Register, m_registers);

        const Register& operator[](RegisterType regType) const;
        const Register& at(RegisterType regType, bool reverse = false) const;

        size_t size() const {
            return m_registers.size();
        }

        static const std::vector<RegisterType>& ScratchList() {
            return s_Scratch;
        }

    private:
        std::vector<Register> m_registers;

        static Register s_None;
        static std::vector<RegisterType> s_Scratch;
    };

}

//std::ostream& operator<<(std::ostream& os, dyno::RegisterType v);