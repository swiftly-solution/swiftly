#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <atomic>
#include <iomanip>
#include <sstream>
#include <cassert>

namespace dyno {
	enum class Mode : bool {
		x86,
		x64
	};

	class MemAccessor;
	class DYNO_API Instruction {
	public:
		union Displacement {
			intptr_t  Relative;
			uintptr_t Absolute;
		};

		enum class OperandType : uint8_t {
			Displacement,
			Register,
			Immediate,
		};

		Instruction(const MemAccessor* accessor,
					uintptr_t address,
					Displacement displacement,
					uint8_t displacementOffset,
					bool isRelative,
					bool isIndirect,
					std::vector<uint8_t>&& bytes,
					std::string&& mnemonic,
					std::string&& opStr,
					Mode mode
				);

		uintptr_t getAbsoluteDestination() const {
			return m_displacement.Absolute;
		}

		uintptr_t getRelativeDestination() const {
			return m_address + m_displacement.Relative + size();
		}

		/**Get the address of where the instruction points if it's a branching instruction
		* @Notes: Handles eip/rip & immediate branches correctly
		* **/
		uintptr_t getDestination() const;

		void setDestination(uintptr_t dest);

		/**Get the address of the instruction in memory**/
		uintptr_t getAddress() const {
			return m_address;
		}

		/**Set a new address of the instruction in memory
		@Notes: Doesn't move the instruction, marks it for move on writeEncoding and relocates if appropriate**/
		void setAddress(uintptr_t address) {
			m_address = address;
		}

		/**Get the displacement from current address**/
		Displacement getDisplacement() const {
			return m_displacement;
		}

		/**Set where in the instruction bytes the offset is encoded**/
		void setDisplacementOffset(uint8_t offset) {
			m_dispOffset = offset;
		}

		void setBranching(const bool status) {
			m_isBranching = status;
		}

		void setCalling(const bool isCalling) {
			m_isCalling = isCalling;
		}

		/**Get the offset into the instruction bytes where displacement is encoded**/
		uint8_t getDisplacementOffset() const {
			return m_dispOffset;
		}

		/**Check if displacement is relative to eip/rip**/
		bool isDisplacementRelative() const {
			return m_isRelative;
		}

		/**Check if the instruction is a type with valid displacement**/
		bool hasDisplacement() const {
			return m_hasDisplacement;
		}

		void setHasDisplacement(bool hasDisplacement) {
			m_hasDisplacement = hasDisplacement;
		}

		bool isBranching() const {
			if (m_isBranching && m_isRelative) {
				assert(m_hasDisplacement);
			}
			return m_isBranching;
		}

		bool isCalling() const {
			return m_isCalling;
		}

		bool isIndirect() const {
			return m_isIndirect;
		}

		const std::vector<uint8_t>& getBytes() const {
			return m_bytes;
		}

		/**Get short symbol name of instruction**/
		const std::string& getMnemonic() const {
			return m_mnemonic;
		}

		/**Get symbol name and parameters**/
		std::string getFullName() const {
			return m_mnemonic + " " + m_opStr;
		}

		/** Displacement size in bytes **/
		void setDisplacementSize(uint8_t size){
			m_dispSize = size;
		}

		size_t getDispSize() const {
			return m_dispSize;
		}

		size_t size() const {
			return m_bytes.size();
		}

		void setRelativeDisplacement(intptr_t displacement);

		void setAbsoluteDisplacement(uintptr_t displacement);

		uint32_t getUID() const {
			return m_uid;
		}

		template<typename T>
		static T calculateRelativeDisplacement(uintptr_t from, uintptr_t to, uint8_t insSize) {
			if (to < from)
				return (T)(0 - (from - to) - insSize);
			return (T)(to - (from + insSize));
		}

		void setIndirect(const bool isIndirect) {
			m_isIndirect = isIndirect;
		}

		void setImmediate(uintptr_t immediate){
			m_hasImmediate = true;
			m_immediate = immediate;
		}

		bool hasImmediate() const {
			return m_hasImmediate;
		}

		uintptr_t getImmediate() const {
			return m_immediate;
		}

		uint8_t getImmediateSize() const {
			return m_immediateSize;
		}

		void setImmediateSize(uint8_t size) {
			m_immediateSize = size;
		}

		void setRegister(int reg) {
			m_register = reg;
		}

		int getRegister() const {
			return m_register;
		}

		bool hasRegister() const {
			return m_register != 0;
		}

		void addOperandType(OperandType type){
			m_operands.emplace_back(type);
		}

		const std::vector<OperandType>& getOperandTypes() const {
			return m_operands;
		}

		bool startsWithDisplacement() const;

	private:
		const MemAccessor* m_accessor;

		int           m_register;        // Register operand when displacement is present
		bool          m_isIndirect;      // Does this instruction get its destination via an indirect mem read (ff 25 ... jmp [jmp_dest]) (only filled for jmps / calls)
		bool          m_isCalling;       // Does this instruction is of a CALL type.
		bool          m_isBranching;     // Does this instruction jmp/call or otherwise change control flow
		bool          m_isRelative;      // Does the displacement need to be added to the address to retrieve where it points too?
		bool          m_hasDisplacement; // Does this instruction have the displacement fields filled (only rip/eip relative types are filled)
		bool          m_hasImmediate;    // Does this instruction have the immediate field filled?
		Displacement  m_displacement;    // Where an instruction points too (valid for jmp + call types, and RIP relative MEM types)

		uintptr_t     m_address;         // Address the instruction is at
		uintptr_t     m_immediate;       // Immediate op
		uint8_t       m_immediateSize;   // Immediate size, in bytes
		uint8_t       m_dispOffset;      // Offset into the byte array where displacement is encoded
		uint8_t       m_dispSize;        // Size of the displacement, in bytes

		Mode m_mode;
		uint32_t m_uid;

		std::vector<uint8_t> m_bytes;    // All the raw bytes of this instruction
		std::vector<OperandType> m_operands; // Types of all instruction operands
		std::string m_mnemonic;
		std::string m_opStr;

		inline static std::atomic_uint32_t s_counter = { 0 };
	};
	static_assert(std::is_nothrow_move_constructible<Instruction>::value, "dyno::Instruction should be noexcept move constructable");

	typedef std::vector<Instruction> insts_t;

	inline bool operator==(const Instruction& lhs, const Instruction& rhs) {
		return lhs.getUID() == rhs.getUID();
	}

	inline std::ostream& operator<<(std::ostream& os, const Instruction& obj) {
		std::stringstream byteStream;
		for (size_t i = 0; i < obj.size(); i++)
			byteStream << std::hex << std::setfill('0') << std::setw(2) << (unsigned)obj.getBytes()[i] << " ";

		os << std::hex << obj.getAddress() << " [" << obj.size() << "]: ";
		os << std::setfill(' ') << std::setw(40) << std::left << byteStream.str();
		os << obj.getFullName();

		if (obj.hasDisplacement() && obj.isDisplacementRelative())
			os << " -> " << obj.getDestination();
		os << std::dec;
		return os;
	}

	inline uint16_t calcInstsSz(const insts_t& insts) {
		uint16_t sz = 0;
		for (const auto& ins : insts)
			sz += (uint16_t)ins.size();
		return sz;
	}

	template<typename T>
	std::string instsToStr(const T& container) {
		std::stringstream ss;
		printInsts(ss, container);
		return ss.str();
	}

	template <typename T>
	inline std::ostream& printInsts(std::ostream& out, const T& container) {
		for (auto ii = container.cbegin(); ii != container.cend(); ii++)
			out << *ii << std::endl;
		return out;
	}

	inline std::ostream& operator<<(std::ostream& os, const insts_t& v) { return printInsts(os, v); }
}