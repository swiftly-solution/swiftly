#pragma once

#include "hook.h"

namespace dyno {
    class Detour : public Hook {
    public:
        Detour(void* pFunc, const ConvFunc& convention);
        ~Detour() override;

        void* getOriginal() const override {
            return m_trampoline;
        }

        bool operator==(void* pFunc) {
            return m_func == pFunc;
        }

    private:
        bool createTrampoline(bool restrictedRelocation);

    protected:
        // address of the original function
        void* m_func;

        // address of the trampoline
        void* m_trampoline;

        // instructions of the original function
        std::unique_ptr<uint8_t[]> m_originalBytes;

        // length of the original instructions
        size_t m_hookLength;
    };
}