#pragma once

#include "vthook.h"

namespace dyno {

    typedef std::function<std::shared_ptr<VTHook>(void*)> HookSupplier;

    class VTable {
    public:
        VTable(void* pClass);
        ~VTable();
        NONCOPYABLE(VTable);

        Hook* hook(const HookSupplier& supplier, size_t index);
        bool unhook(size_t index);

        Hook* find(size_t index) const;
        bool empty() const {
            return m_hooked.empty();
        }

        bool operator==(void* pClass) const {
            return m_class == pClass;
        }

    private:
        static size_t GetVFuncCount(void** vtable);

        void*** m_class;
        void** m_origVtable;
        size_t m_vFuncCount;
        std::unique_ptr<void*[]> m_newVtable;

        std::map<size_t, std::shared_ptr<VTHook>> m_hooked;
    };
}
