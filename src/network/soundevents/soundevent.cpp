#include "soundevent.h"

#include <iomanip>

#include <core/entrypoint.h>
#include <memory/gamedata/gamedata.h>
#include <memory/virtual/virtual.h>
#include <sdk/components/CSingleRecipientFilter.h>

#include <public/networksystem/netmessage.h>
#include <public/tier1/generichash.h>
#include <public/steam/steamtypes.h>
#include <public/mathlib/vector.h>
#include <public/entity2/entitysystem.h>
#include <public/entity2/entityidentity.h>

#include <gameevents.pb.h>

#define GETCHECK_FIELD(return_value)								\
	SosField* field = this->GetField(pszFieldName);					\
	if (field == nullptr)											\
		return return_value;

#define CHECK_FIELD_TYPE(check_type, return_value)					\
    if (field->type != check_type) return return_value;

#define SET_FIELD(check_type, value)								\
	SosField field;													\
	field.type = check_type;										\
	field.data = value;												\
	this->AddOrReplaceField(pszFieldName, &field);

template<typename T>
void insert(std::vector<uint8_t>& vec, const T* value, int size = -1) {
    const char* bytes = reinterpret_cast<const char*>(value);
    
    for (size_t i = 0; i < (size == -1 ? sizeof(T) : size); ++i) {
        vec.push_back(bytes[i]);
    }
}

int Soundevent::Emit()
{
	// packed_param serialization
	std::vector<uint8_t> buffer;
	for (const auto& pair : this->parameters) {
		auto fieldName = pair.first;
		auto fieldData = &pair.second;
		auto data = &fieldData->data;
		uint32_t paramNameHash = MurmurHash2LowerCase(fieldName.c_str(), SOUNDEVENT_FIELD_NAME_HASH_SEED);
		insert(buffer, &paramNameHash);										// name hash
		buffer.push_back(fieldData->type);									// data type

		char size;
		switch (fieldData->type) {
			case SE_Bool:
				buffer.push_back(1);										// data size
				buffer.push_back(0);										// padding
				buffer.push_back(data->m_bool);								// data
				break;
			case SE_Int:
			case SE_UInt32:
			case SE_Float:
				buffer.push_back(4);
				buffer.push_back(0);
				insert(buffer, data, 4);	// insert in little endian order
				break;
			case SE_UInt64:
				buffer.push_back(8);
				buffer.push_back(0);
				insert(buffer, data, 8);
				break;
			case SE_Float3:
				buffer.push_back(12);
				buffer.push_back(0);
				insert(buffer, data->m_pVector, 12);
				break;
		}
	}

	auto soundeventHash = MurmurHash2LowerCase(this->name.c_str(), SOUNDEVENT_NAME_HASH_SEED);
	INetworkMessageInternal* pNetMsg = g_pNetworkMessages->FindNetworkMessageById(208);
    auto data = pNetMsg->AllocateMessage()->ToPB<CMsgSosStartSoundEvent>();

	uint32_t guid;
#ifdef _WIN32
	CALL_VIRTUAL(void, g_GameData.GetOffset("CSoundSystem_TakeGuid"), g_pSoundSystem, &guid);
#else
	guid = CALL_VIRTUAL(uint32_t, g_GameData.GetOffset("CSoundSystem_TakeGuid"), g_pSoundSystem);
#endif

	data->set_soundevent_hash(soundeventHash);
	data->set_source_entity_index(this->sourceEntityIndex);
	data->set_soundevent_guid(guid);
	data->set_packed_params(std::string(buffer.begin(), buffer.end()));
	
	g_pGameEventSystem->PostEventAbstract(-1, false, &this->clients, pNetMsg, data, 0);

	return guid;
}

Soundevent::Soundevent()
{
}

void Soundevent::SetName(std::string name) 
{
	this->name = name;
}

std::string Soundevent::GetName() 
{
	return this->name;
}

void Soundevent::SetSourceEntityIndex(int sourceEntityIndex) 
{
	this->sourceEntityIndex = sourceEntityIndex;
}

int Soundevent::GetSourceEntityIndex() 
{
	return this->sourceEntityIndex;
}

void Soundevent::AddClient(int playerid) 
{
	this->clients.AddRecipient(CPlayerSlot(playerid));
}

void Soundevent::RemoveClient(int playerid) 
{
	this->clients.RemoveRecipient(CPlayerSlot(playerid));
}

void Soundevent::ClearClients() 
{
	this->clients.RemoveAllPlayers();
}

void Soundevent::AddClients() 
{
	this->clients.AddAllPlayers();
}

std::vector<int> Soundevent::GetClients()
{
	std::vector<int> clns;
	auto recipients = this->clients.GetRecipients();
	if (this->clients.GetRecipientCount() == 0) return clns;

	for (int i = 0; i < 64; i++)
		if (recipients.IsBitSet(i))
            clns.push_back(i);

	return clns;
}

SosField* Soundevent::GetField(std::string pszFieldName)
{
	auto it = this->parameters.find(pszFieldName);
    return (it != this->parameters.end()) ? &it->second : nullptr;
}

void Soundevent::AddOrReplaceField(std::string pszFieldName, const SosField* field)
{
	this->parameters[pszFieldName] = *field;
}

bool Soundevent::HasField(std::string pszFieldName)
{
	return this->GetField(pszFieldName) != nullptr;
}

void Soundevent::SetBool(std::string pszFieldName, bool value)
{
	CVariant data(value);
	SET_FIELD(SE_Bool, data);
}

bool Soundevent::GetBool(std::string pszFieldName)
{
	GETCHECK_FIELD(false);
	CHECK_FIELD_TYPE(SE_Bool, false);

	return field->data.Get<bool>();
}

void Soundevent::SetInt(std::string pszFieldName, int value)
{
	CVariant data((int32)value);
	SET_FIELD(SE_Int, data);
}

int Soundevent::GetInt(std::string pszFieldName)
{
	GETCHECK_FIELD(0);
	CHECK_FIELD_TYPE(SE_Int, 0);

	return (int)field->data.Get<int32>();
}

void Soundevent::SetUInt32(std::string pszFieldName, uint32_t value)
{
	CVariant data((uint32)value);
	SET_FIELD(SE_UInt32, data);
}

uint32_t Soundevent::GetUInt32(std::string pszFieldName)
{
	GETCHECK_FIELD(0);
	CHECK_FIELD_TYPE(SE_UInt32, 0);

	return (uint32_t)field->data.Get<uint32>();
}

void Soundevent::SetUInt64(std::string pszFieldName, uint64_t value)
{
	CVariant data((uint64)value);
	SET_FIELD(SE_UInt64, data);
}

uint64_t Soundevent::GetUInt64(std::string pszFieldName)
{
	GETCHECK_FIELD(0);
	CHECK_FIELD_TYPE(SE_UInt64, 0);

	return (uint64_t)field->data.Get<uint64>();
}

void Soundevent::SetFloat(std::string pszFieldName, float value)
{
	CVariant data(value);
	SET_FIELD(SE_Float, data);
}

float Soundevent::GetFloat(std::string pszFieldName)
{
	GETCHECK_FIELD(0.0f);
	CHECK_FIELD_TYPE(SE_Float, 0.0f);

	return field->data.Get<float>();
}

void Soundevent::SetFloat3(std::string pszFieldName, Vector& value)
{
	CVariant data(value);
	SET_FIELD(SE_Float3, data);
}

Vector Soundevent::GetFloat3(std::string pszFieldName)
{
	Vector def;
	GETCHECK_FIELD(def);
	CHECK_FIELD_TYPE(SE_Float3, def);

	return field->data.Get<Vector>();
}