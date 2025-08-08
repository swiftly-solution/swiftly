#ifndef soundevent_h
#define soundevent_h

#include <string>
#include <map>
#include <vector>
#include <variant.h>
#include <public/bitvec.h>
#include <mathlib/vector.h>
#include <sdk/components/CSingleRecipientFilter.h>

#define SOUNDEVENT_NAME_HASH_SEED 0x53524332
#define SOUNDEVENT_FIELD_NAME_HASH_SEED 0x31415926
/*
reversed from game, there's more type than the following,
but we only implement these for now, because we don't know what other types' serialization looks like,
and these should be sufficient in most case
*/
enum SosFieldType {
	SE_Bool = 1,
	SE_Int = 2,
	SE_UInt32 = 3,
	SE_UInt64 = 4,
	SE_Float = 8,
	SE_Float3 = 0xA
};

struct SosField {
	SosFieldType type;
	CVariant data;
};

class Soundevent {
private:
	std::string name;
	int sourceEntityIndex = -1;
	std::map<std::string, SosField> parameters;
	CRecipientFilter clients;

	SosField* GetField(std::string pszFieldName);
	void AddOrReplaceField(std::string pszFieldName, const SosField* field);

public:
	Soundevent();
	int Emit();

	void SetName(std::string name);
	std::string GetName();
	void SetSourceEntityIndex(int sourceEntityIndex);
	int GetSourceEntityIndex();

	void AddClient(int playerid);
	void RemoveClient(int playerId);
    void ClearClients();
    void AddClients();
	std::vector<int> GetClients();

	bool HasField(std::string pszFieldName);
	
	void SetBool(std::string pszFieldName, bool value);
	bool GetBool(std::string pszFieldName);
	void SetInt(std::string pszFieldName, int value);
	int GetInt(std::string pszFieldName);
	void SetUInt32(std::string pszFieldName, uint32_t value);
	uint32_t GetUInt32(std::string pszFieldName);
	void SetUInt64(std::string pszFieldName, uint64_t value);
	uint64_t GetUInt64(std::string pszFieldName);
	void SetFloat(std::string pszFieldName, float value);
	float GetFloat(std::string pszFieldName);
	void SetFloat3(std::string pszFieldName, Vector& value);
	Vector GetFloat3(std::string pszFieldName);

};

#endif