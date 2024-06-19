#pragma once

#include "convention.h"
#include <type_traits>

namespace dyno {
	template<typename T>
	constexpr DataType GetType() {
		if constexpr (std::is_same_v<T, void>) return DataType::Void;
		else if constexpr (std::is_same_v<T, bool>) return DataType::Bool;
		else if constexpr (std::is_same_v<T, int8_t>) return DataType::Int8;
		else if constexpr (std::is_same_v<T, uint8_t>) return DataType::UInt8;
		else if constexpr (std::is_same_v<T, int16_t>) return DataType::Int16;
		else if constexpr (std::is_same_v<T, uint16_t>) return DataType::UInt16;
		else if constexpr (std::is_same_v<T, int32_t>) return DataType::Int32;
		else if constexpr (std::is_same_v<T, uint32_t>) return DataType::UInt32;
		else if constexpr (std::is_same_v<T, int64_t>) return DataType::Int64;
		else if constexpr (std::is_same_v<T, uint64_t> || std::is_same_v<T, unsigned long>) return DataType::UInt64;
		else if constexpr (std::is_same_v<T, float>) return DataType::Float;
		else if constexpr (std::is_same_v<T, double>) return DataType::Double;
		else if constexpr (std::is_same_v<T, const char*>) return DataType::String;
		else if constexpr (std::is_same_v<T, const wchar_t*>) return DataType:: WString;
		else if constexpr (std::is_pointer<T>::value || std::is_reference_v<T>) return DataType::Pointer;
		else {
			if (sizeof(T) > sizeof(uint64_t)) {
				return DataType::Pointer;
			} else if constexpr (sizeof(T) > sizeof(uint32_t)) {
				return DataType::UInt64;
			} else if constexpr (sizeof(T) > sizeof(uint16_t)) {
				return DataType::UInt32;
			} else if constexpr (sizeof(T) > sizeof(uint8_t)) {
				return DataType::UInt16;
			} else if constexpr (sizeof(T) > sizeof(bool)) {
				return DataType::UInt8;
			}
			return DataType::Bool;
		}
	}

	template<typename Function>
	struct function_traits;

	template<typename Ret, typename... Args>
	struct function_traits<Ret(*)(Args...)> {
		static constexpr size_t arity = sizeof...(Args);

		static std::array<DataObject, arity> args() {
			return { GetType<Args>() ...};
		}

		static DataObject ret() {
			return GetType<Ret>();
		}
	};

	template<typename Class, typename Ret, typename... Args>
	struct function_traits<Ret(Class::*)(Args...)> {
		static constexpr size_t arity = sizeof...(Args);

		static std::array<DataObject, arity + 1> args() {
			std::array<DataObject, arity> originalArgs = { GetType<Args>() ... };
			std::array<DataObject, arity + 1> result;
			result[0] = DataType::Pointer;
			std::copy(originalArgs.begin(), originalArgs.end(), result.begin() + 1);
			return result;
		}

		static DataObject ret() {
			return GetType<Ret>();
		}
	};
	
	template <typename Class, typename Ret, typename... Args>
	class function_traits<Ret (Class::*)(Args...) const> : public function_traits<Ret (Class::*)(Args...)> {};
	template <typename Class, typename Ret, typename... Args>
	class function_traits<Ret (Class::*)(Args...) volatile> : public function_traits<Ret (Class::*)(Args...)> {};
	template <typename Class, typename Ret, typename... Args>
	class function_traits<Ret (Class::*)(Args...) const volatile> : public function_traits<Ret (Class::*)(Args...)> {};


	template<typename Ret, typename... Args>
	struct function_traits<Ret(Args...)> {
		static constexpr size_t arity = sizeof...(Args);

		static std::array<DataObject, arity> args() {
			return { GetType<Args>() ...};
		}

		static DataObject ret() {
			return GetType<Ret>();
		}
	};
	
	template<class Ret, class... ArgTypes>
	class function_traits<Ret(ArgTypes...) const> : public function_traits<Ret(ArgTypes...)> {};
	template<class Ret, class... ArgTypes>
	class function_traits<Ret(ArgTypes...) volatile> : public function_traits<Ret(ArgTypes...)> {};
	template<class Ret, class... ArgTypes>
	class function_traits<Ret(ArgTypes...) const volatile> : public function_traits<Ret(ArgTypes...)> {};
}