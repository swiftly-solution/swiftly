#pragma once

#include "ihook.h"

#include <memory>
#include <mutex>

namespace dyno {
	class IHookManager {
	public:
		/**
		* @brief Creates a detour hook for a given function.
		* If the function was already hooked, the existing Hook instance will be returned.
		* @param pFunc address to apply the hook to.
		* @param convention
		* @return NULL or the Hook instance.
		*/
		virtual std::shared_ptr<IHook> hookDetour(void* pFunc, const ConvFunc& convention) = 0;

		/**
		 * @brief Creates a function hook inside the virtual function table.
		 * If the function was already hooked, the existing Hook instance will be returned.
		 * @param pClass address of the class to instantiate hook on.
		 * @param index index of the function to hook inside the virtual function table. (starting at 0)
		 * @param convention
		 * @return NULL or the Hook instance.
		 */
		virtual std::shared_ptr<IHook> hookVirtual(void* pClass, int index, const ConvFunc& convention) = 0;

		/**
		 * @brief Creates a function hook inside the virtual function table.
		 * If the function was already hooked, the existing Hook instance will be returned.
		 * @param pClass address of the class to instantiate hook on.
		 * @param pFunc address of virtual member function. Like (void*&) &IClass::PureVirtualMethod.
		 * @param convention
		 * @return NULL or the Hook instance.
		 */
		virtual std::shared_ptr<IHook> hookVirtual(void* pClass, void* pFunc, const ConvFunc& convention) = 0;

		/**
		 * @brief Removes all callbacks and restores the original function.
		 * @param pFunc
		 * @return true if the function was hooked previously and is unhooked now. False otherwhise.
		 */
		virtual bool unhookDetour(void* pFunc) = 0;

		/**
		 * @brief Removes all callbacks and restores the original function.
		 * @param pClass
		 * @param index
		 * @return true if the function was hooked previously and is unhooked now. False otherwhise.
		 */
		virtual bool unhookVirtual(void* pClass, int index) = 0;

		/**
		 * @brief Removes all callbacks and restores the original function.
		 * @param pClass
		 * @param pFunc
		 * @return true if the function was hooked previously and is unhooked now. False otherwhise.
		 */
		virtual bool unhookVirtual(void* pClass, void* pFunc) = 0;

		/**
		 * @brief Finds the hook for a given function.
		 * @param pFunc
		 * @return NULL or the found Hook instance.
		 */
		virtual std::shared_ptr<IHook> findDetour(void* pFunc) const = 0;

		/**
		 * @brief Finds the hook for a given class and virtual function index.
		 * @param pClass
		 * @param index
		 * @return NULL or the found Hook instance.
		 */
		virtual std::shared_ptr<IHook> findVirtual(void* pClass, int index) const = 0;

		/**
		 * @brief Finds the hook for a given class and virtual function ptr.
		 * @param pFunc
		 * @return NULL or the found Hook instance.
		 */
		virtual std::shared_ptr<IHook> findVirtual(void* pClass, void* pFunc) const = 0;

		/**
		 * @brief Removes all callbacks and restores all functions.
		 */
		virtual void unhookAll() = 0;

		/**
		 * @brief Unhooks all previously hooked functions in the virtual function table.
		 * @param pClass
		 */
		virtual void unhookAllVirtual(void* pClass) = 0;

		/**
		 * @brief Unhooks previously hooked virtual functions which not in use anymore.
		 */
		virtual void clearCache() = 0;

		/**
		 * @brief Gets a reference to the singleton instance of the HookManager.
		 *
		 * The HookManager is a static class that manages hooks for certain operations.
		 * This method provides access to the singleton instance of the HookManager.
		 *
		 * @return A reference to the singleton instance of the HookManager.
		 *
		 * @note The HookManager follows the Singleton pattern, ensuring that only one
		 * instance exists throughout the program's execution.
		 *
		 * Example usage:
		 * @code
		 * // Get a reference to the HookManager instance
		 * IHookManager& hookManager = IHookManager::Get();
		 * // Use the hookManager reference to manage hooks
		 * // ...
		 * @endcode
		 */
		DYNO_API static IHookManager& Get();
	};
}