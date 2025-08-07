#include "soundevent.h"

#include <public/const.h>
#include <public/bitvec.h>
#include <public/steam/steamtypes.h>

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
	this->clients.Set(playerid);
}

void Soundevent::RemoveClient(int playerid) 
{
	this->clients.Clear(playerid);
}

void Soundevent::ClearClients() 
{
	this->clients.ClearAll();
}

void Soundevent::AddClients() 
{
	this->clients.SetAll();
}

std::vector<int> Soundevent::GetClients()
{
	std::vector<int> clns;
	if (this->clients.IsAllClear()) return clns;

	for (int i = 0; i < 64; i++)
		if (this->clients.IsBitSet(i))
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
	CVariant data(value);
	SET_FIELD(SE_Int, (int32)data);
}

int Soundevent::GetInt(std::string pszFieldName)
{
	GETCHECK_FIELD(0);
	CHECK_FIELD_TYPE(SE_Int, 0);

	return (int)field->data.Get<int32>();
}