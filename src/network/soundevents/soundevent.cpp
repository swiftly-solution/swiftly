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
    if (field->GetType() != check_type) return return_value;

#define SET_FIELD(check_type, value)								\
	SosField field(check_type, &value);								\
	this->AddOrReplaceField(pszFieldName, field);

#define RETURN_FIELD(return_type)										\
	return *reinterpret_cast<const return_type*>(field->GetData());

void insert(std::vector<uint8_t>& vec, const void* value, uint8_t size) {
    const char* bytes = reinterpret_cast<const char*>(value);
    
	for (int i = 0; i < size; i++) {
        vec.push_back(bytes[i]);
    }
}

uint32_t Soundevent::Emit()
{
	// packed_param serialization
	std::vector<uint8_t> buffer;
	for (const auto& pair : this->parameters) {
		auto fieldName = pair.first;
		auto fieldData = &pair.second;
		uint32_t paramNameHash = MurmurHash2LowerCase(fieldName.c_str(), SOUNDEVENT_FIELD_NAME_HASH_SEED);
		insert(buffer, &paramNameHash, 4);													// name hash
		buffer.push_back(fieldData->GetType());												// data type
		buffer.push_back(SosFieldTypeSize(fieldData->GetType()));							// data size
		buffer.push_back(0);																// padding
		insert(buffer, fieldData->GetData(), SosFieldTypeSize(fieldData->GetType()));		// data
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
	data->set_seed(guid);
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

void Soundevent::SetRecipientFilter(CRecipientFilter filter)
{
	this->clients = filter;
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

void Soundevent::AddOrReplaceField(std::string pszFieldName, const SosField field)
{
	this->parameters[pszFieldName] = field;
}

bool Soundevent::HasField(std::string pszFieldName)
{
	return this->GetField(pszFieldName) != nullptr;
}

void Soundevent::SetBool(std::string pszFieldName, bool value)
{
	SET_FIELD(SE_Bool, value);
}

bool Soundevent::GetBool(std::string pszFieldName)
{
	GETCHECK_FIELD(false);
	CHECK_FIELD_TYPE(SE_Bool, false);
	RETURN_FIELD(bool);
}

void Soundevent::SetInt(std::string pszFieldName, int value)
{
	SET_FIELD(SE_Int, value);
}

int Soundevent::GetInt(std::string pszFieldName)
{
	GETCHECK_FIELD(0);
	CHECK_FIELD_TYPE(SE_Int, 0);
	RETURN_FIELD(int);
}

void Soundevent::SetUInt32(std::string pszFieldName, uint32_t value)
{
	SET_FIELD(SE_UInt32, value);
}

uint32_t Soundevent::GetUInt32(std::string pszFieldName)
{
	GETCHECK_FIELD(0);
	CHECK_FIELD_TYPE(SE_UInt32, 0);
	RETURN_FIELD(uint32_t);
}

void Soundevent::SetUInt64(std::string pszFieldName, uint64_t value)
{
	SET_FIELD(SE_UInt64, value);
}

uint64_t Soundevent::GetUInt64(std::string pszFieldName)
{
	GETCHECK_FIELD(0);
	CHECK_FIELD_TYPE(SE_UInt64, 0);
	RETURN_FIELD(uint64_t);
}

void Soundevent::SetFloat(std::string pszFieldName, float value)
{
	SET_FIELD(SE_Float, value);
}

float Soundevent::GetFloat(std::string pszFieldName)
{
	GETCHECK_FIELD(0.0f);
	CHECK_FIELD_TYPE(SE_Float, 0.0f);
	RETURN_FIELD(float);
}

void Soundevent::SetFloat3(std::string pszFieldName, Vector& value)
{
	SET_FIELD(SE_Float3, value);
}

Vector Soundevent::GetFloat3(std::string pszFieldName)
{
	Vector def(0, 0, 0);
	GETCHECK_FIELD(def);
	CHECK_FIELD_TYPE(SE_Float3, def);
	RETURN_FIELD(Vector);
}