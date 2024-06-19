#pragma once

#include "convention.h"
#include "registers.h"
#include <functional>
#include <dynohook_export.h>

namespace dyno {
	enum class HookMode : uint8_t {
		UNKNOWN,
		Detour,
		VEHHOOK,
		VTableSwap,
		IAT,
		EAT
	};

	enum class CallbackType : bool {
		Pre,  // callback will be executed before the original function
		Post  // callback will be executed after the original function
	};

	enum class ReturnAction : int32_t {
		Ignored,  // handler didn't take any action
		Handled,  // we did something, but real function should still be called
		Override, // call real function, but use my return value
		Supercede // skip real function; use my return value
	};

	class IHook;
	using CallbackHandler = ReturnAction (*)(CallbackType, IHook&);
	using ConvFunc = std::function<ICallingConvention*()>;

	/**
	 * @brief Creates and manages hooks at the beginning of a function.
	 *
	 * This hooking method requires knowledge of parameters and calling convention of the target function.
	 */
	class DYNO_API IHook {
	public:
		/**
		 * @brief Adds a callback handler to the hook.
		 * @param type The callback type.
		 * @param handler The callback handler that should be added.
		 * @return True on success, false otherwise.
		 */
		virtual bool addCallback(CallbackType type, CallbackHandler handler) = 0;

		/**
		 * @brief Removes a callback handler to the hook.
		 * @param type The callback type.
		 * @param handler The callback handler that should be removed.
		 * @return True on success, false otherwise.
		 */
		virtual bool removeCallback(CallbackType type, CallbackHandler handler) = 0;

		/**
		 * @brief Checks if a callback handler is already added.
		 * @param type The callback type.
		 * @param handler The callback handler that should be checked.
		 * @return True on success, false otherwise.
		 */
		virtual bool isCallbackRegistered(CallbackType type, CallbackHandler handler) const = 0;

		/**
		 * @brief Checks if there are any callback handlers added to this hook.
		 * @return True on success, false otherwise.
		 */
		virtual bool areCallbacksRegistered() const = 0;

		template<class T>
		T getArgument(size_t index) {
			return *(T*) getCallingConvention().getArgumentPtr(index, getRegisters());
		}

		template<class T>
		void setArgument(size_t index, T value) {
			void* argumentPtr = getCallingConvention().getArgumentPtr(index, getRegisters());
			*(T*) argumentPtr = value;
			getCallingConvention().onArgumentPtrChanged(index, getRegisters(), argumentPtr);
		}

		template<class T>
		T getReturn() {
			return *(T*) getCallingConvention().getReturnPtr(getRegisters());
		}

		template<class T>
		void setReturn(T value) {
			void* returnPtr = getCallingConvention().getReturnPtr(getRegisters());
			*(T*) returnPtr = value;
			getCallingConvention().onReturnPtrChanged(getRegisters(), returnPtr);
		}

		virtual bool hook() = 0;
		virtual bool unhook() = 0;
		virtual bool rehook()  = 0;
		virtual bool setHooked(bool state) = 0;
		virtual bool isHooked() const = 0;
		virtual const uintptr_t& getTarget() const = 0;
		virtual const uintptr_t& getAddress() const = 0;
		virtual HookMode getMode() const = 0;

	protected:
		virtual ICallingConvention& getCallingConvention() = 0;
		virtual Registers& getRegisters() = 0;
	};
}