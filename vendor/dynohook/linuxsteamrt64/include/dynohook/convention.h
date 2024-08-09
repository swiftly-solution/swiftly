#pragma once

#include "registers.h"

namespace dyno {
    enum class DataType : uint8_t {
        Void,
        Bool,
        Char,
        UChar,
        Short,
        UShort,
        Int,
        UInt,
        Long,
        ULong,
        LongLong,
        ULongLong,
        Float,
        Double,
        Pointer,
        String,
        M128,
        M256,
        M512,
        Object
    };

    struct DataObject {
        DataType type;
        RegisterType reg;
        uint16_t size;

        DataObject(DataType type, RegisterType reg = NONE, uint16_t size = 0) : type(type), reg(reg), size(size) {}

        bool isFlt() const { return type == DataType::Float || type == DataType::Double; }
        bool isVec() const { return type == DataType::M128 || type == DataType::M256 || type == DataType::M512; }
    };

    /**
     * Returns the size after applying alignment.
     * @param size The size that should be aligned.
     * @param alignment The alignment that should be used.
     * @return
     */
    inline size_t Align(size_t size, size_t alignment) {
        size_t unaligned = size % alignment;
        if (unaligned == 0)
            return size;

        return size + (alignment - unaligned);
    }

    /**
     * @brief Returns the size of a data type after applying alignment.
     * @param type The data type you would like to get the size of.
     * @param alignment The alignment that should be used.
     * @return
     */
    inline size_t GetDataTypeSize(DataType type, size_t alignment) {
        switch (type) {
            case DataType::Void:
                return 0;
            case DataType::Bool:
                return Align(sizeof(bool), alignment);
            case DataType::Char:
                return Align(sizeof(char), alignment);
            case DataType::UChar:
                return Align(sizeof(unsigned char), alignment);
            case DataType::Short:
                return Align(sizeof(short), alignment);
            case DataType::UShort:
                return Align(sizeof(unsigned short), alignment);
            case DataType::Int:
                return Align(sizeof(int), alignment);
            case DataType::UInt:
                return Align(sizeof(unsigned int), alignment);
            case DataType::Long:
                return Align(sizeof(long), alignment);
            case DataType::ULong:
                return Align(sizeof(unsigned long), alignment);
            case DataType::LongLong:
                return Align(sizeof(long long), alignment);
            case DataType::ULongLong:
                return Align(sizeof(unsigned long long), alignment);
            case DataType::Float:
                return Align(sizeof(float), alignment);
            case DataType::Double:
                return Align(sizeof(double), alignment);
            case DataType::Pointer:
                return Align(sizeof(void*), alignment);
            case DataType::String:
                return Align(sizeof(char*), alignment);
            case DataType::M128:
                return Align(sizeof(float) * 4, alignment);
            case DataType::M256:
                return Align(sizeof(float) * 8, alignment);
            case DataType::M512:
                return Align(sizeof(float) * 16, alignment);
            default:
                puts("[Warning] - Convention - Unknown data type.");
        }
        return 0;
    }

    /**
     * @brief This is the base class for every calling convention.
     *
     * Inherit from this class to create your own calling convention.
     */
    class CallingConvention {
    public:
        /**
         * @brief Initializes the calling convention.
         * @param arguments A list of DataType_t objects, which define the arguments of the function.
         * @param returnType The return type of the function.
         * @param alignment
         */
        CallingConvention(std::vector<DataObject> arguments, DataObject returnType, size_t alignment);
        virtual ~CallingConvention() = default;
        NONCOPYABLE(CallingConvention);

        /**
         * @brief This should return a list of RegisterType values. These registers will be saved for later access.
         * @return
         */
        virtual std::vector<RegisterType> getRegisters() = 0;

        /**
         * Returns a pointer to the memory at the stack.
         * @param registers A snapshot of all saved registers.
         * @return
         */
        virtual void** getStackArgumentPtr(const Registers& registers) = 0;

        /**
         * @brief Returns a pointer to the argument at the given index.
         * @param index The index of the argument.
         * @param registers A snapshot of all saved registers.
         * @return
         */
        virtual void* getArgumentPtr(size_t index, const Registers& registers) = 0;

        /**
         * @brief
         * @param index The index of the argument.
         * @param registers A snapshot of all saved registers.
         * @param argumentPtr A pointer to the argument at the given index.
         */
        virtual void onArgumentPtrChanged(size_t index, const Registers& registers, void* argumentPtr) = 0;

        /**
         * @brief Returns a pointer to the return value.
         * @param registers A snapshot of all saved registers.
         * @return
         */
        virtual void* getReturnPtr(const Registers& registers) = 0;

        /**
         *
         * @param registers A snapshot of all saved registers.
         * @param returnPtr A pointer to the return value.
         */
        virtual void onReturnPtrChanged(const Registers& registers, void* returnPtr) = 0;

        /**
         * @brief Save the return value in a seperate buffer, so we can restore it after calling the original function.
         * @param registers A snapshot of all saved registers.
         */
        virtual void saveReturnValue(const Registers& registers);

        /**
         * @brief
         * @param registers A snapshot of all saved registers.
         */
        virtual void restoreReturnValue(const Registers& registers);

        /**
         * @brief Save the value of arguments in a seperate buffer for the post callback.
         * Compiler optimizations might cause the registers or stack space to be reused
         * and overwritten during function execution if the value isn't needed anymore
         * at some point. This leads to different values in the post hook.
         * @param registers A snapshot of all saved registers.
         */
        virtual void saveCallArguments(const Registers& registers);

        /**
         * @brief Restore the value of arguments from a seperate buffer for the call.
         * @param registers A snapshot of all saved registers.
         */
        virtual void restoreCallArguments(const Registers& registers);

        /**
         * @brief Returns the number of bytes that should be added to the stack to clean up.
         * @return
         */
        virtual size_t getPopSize() {
            return 0;
        }

        /**
         * Returns the number of bytes for the buffer to store all the arguments that are passed in a stack in.
         * @return
         */
        size_t getArgStackSize() const {
            return m_stackSize;
        }

        /**
         * @brief Returns the number of bytes for the buffer to store all the arguments that are passed in a register in.
         * @return
         */
        size_t getArgRegisterSize() const {
            return m_registerSize;
        }

        const std::vector<DataObject>& getArguments() const {
            return m_arguments;
        }

        DataObject getReturn() const {
            return m_return;
        }

        size_t getAlignment() const {
            return m_alignment;
        }

    protected:
        void init();

    protected:
        std::vector<DataObject> m_arguments;
        DataObject m_return;
        size_t m_alignment;
        size_t m_stackSize;
        size_t m_registerSize;

        // save the return in case we call the original function and want to override the return again.
        std::vector<std::unique_ptr<uint8_t[]>> m_savedReturnBuffers;
        // save call arguments in case the function reuses the space and overwrites the values for the post hook.
        std::vector<std::unique_ptr<uint8_t[]>> m_savedCallArguments;
    };
}