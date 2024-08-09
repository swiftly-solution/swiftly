#pragma once

#include "convention.h"
#include "hook.h"
#include "vtable.h"
#include "detour.h"

namespace dyno {

    class HookManager {
    private:
        HookManager() = default;
        ~HookManager() = default;

    public:
        NONCOPYABLE(HookManager);

        /**
         * @brief Creates a detour hook for a given function.
         * If the function was already hooked, the existing Hook instance will be returned.
         * @param pFunc address to apply the hook to.
         * @param convention
         * @return NULL or the Hook instance.
         */
        Hook* hook(void* pFunc, const ConvFunc& convention);

        /**
         * @brief Creates a function hook inside the virtual function table.
         * If the function was already hooked, the existing Hook instance will be returned.
         * @param pClass address of the class to instantiate hook on.
         * @param index index of the function to hook inside the virtual function table. (starting at 0)
         * @param convention
         * @return NULL or the Hook instance.
         */
        Hook* hook(void* pClass, size_t index, const ConvFunc& convention);

        /**
         * @brief Removes all callbacks and restores the original function.
         * @param pFunc address to apply the hook to.
         * @return true if the function was hooked previously and is unhooked now. False otherwhise.
         */
        bool unhook(void* pFunc);

        /**
         * @brief Removes all callbacks and restores the original function.
         * @param pClass address of the class to instantiate hook on.
         * @param index index of the function to hook inside the virtual function table. (starting at 0)
         * @return true if the function was hooked previously and is unhooked now. False otherwhise.
         */
        bool unhook(void* pClass, size_t index);

        /**
         * @brief Finds the hook for a given function.
         * @param pFunc address to apply the hook to.
         * @return NULL or the found Hook instance.
         */
        Hook* find(void* pFunc) const;

        /**
         * @brief Finds the hook for a given class and virtual function index.
         * @param pClass address of the class to instantiate hook on.
         * @param index index of the function to hook inside the virtual function table. (starting at 0)
         * @return NULL or the found Hook instance.
         */
        Hook* find(void* pClass, size_t index) const;

        /**
         * @brief Removes all callbacks and restores all functions.
         */
        void unhookAll();

        /**
         * @brief Unhooks all previously hooked functions in the virtual function table.
         * @param pClass address of the class to instantiate hook on.
         */
        void unhookAll(void* pClass);

        /**
         * @brief Unhooks all previously virtual hooked functions.
         */
        void clearCache();

        /**
         * @return Returns a pointer to a static HookManager object.
         */
        static HookManager& Get();

    public:
        std::vector<std::unique_ptr<Detour>> m_detours;
        std::vector<std::unique_ptr<VTable>> m_vtables;
        std::map<void*, std::shared_ptr<VTHook>> m_vthooks;
    };
}