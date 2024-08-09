#pragma once

#include "hook.h"

namespace dyno {
    class VTHook : public Hook {
    public:
        VTHook(void* pFunc, const ConvFunc& convention);
        ~VTHook() override;

        void* getOriginal() const override {
            return m_func;
        }

    private:
        // address of the original function
        void* m_func;

        // address of the page
        void* m_page;
    };
}
