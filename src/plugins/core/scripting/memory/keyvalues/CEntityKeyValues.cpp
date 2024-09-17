#include "../../../scripting.h"
#include <entity2/entitykeyvalues.h>

PluginCEntityKeyValues::PluginCEntityKeyValues()
{
    this->keyVals = new CEntityKeyValues();
}

bool PluginCEntityKeyValues::GetBool( std::string key )
{
    return this->keyVals->GetBool(key.c_str());
}

int PluginCEntityKeyValues::GetInt( std::string key )
{
    return this->keyVals->GetInt(key.c_str());
}

uint PluginCEntityKeyValues::GetUint( std::string key )
{
    return this->keyVals->GetUint(key.c_str());
}

int64 PluginCEntityKeyValues::GetInt64( std::string key )
{
    return this->keyVals->GetInt64(key.c_str());
}

uint64 PluginCEntityKeyValues::GetUint64( std::string key )
{
    return this->keyVals->GetUint64(key.c_str());
}

float PluginCEntityKeyValues::GetFloat( std::string key )
{
    return this->keyVals->GetFloat(key.c_str());
}

double PluginCEntityKeyValues::GetDouble( std::string key )
{
    return this->keyVals->GetDouble(key.c_str());
}

std::string	PluginCEntityKeyValues::GetString( std::string key )
{
    return this->keyVals->GetString(key.c_str());
}

std::string	PluginCEntityKeyValues::GetPtr( std::string key )
{
    return string_format("%p", this->keyVals->GetPtr(key.c_str()));
}

unsigned int PluginCEntityKeyValues::GetStringToken( std::string key )
{
    return this->keyVals->GetStringToken(key.c_str()).m_nHashCode;
}

Color PluginCEntityKeyValues::GetColor( std::string key )
{
    return this->keyVals->GetColor(key.c_str());
}

Vector PluginCEntityKeyValues::GetVector( std::string key )
{
    return this->keyVals->GetVector(key.c_str());
}

Vector2D PluginCEntityKeyValues::GetVector2D( std::string key )
{
    return this->keyVals->GetVector2D(key.c_str());
}

Vector4D PluginCEntityKeyValues::GetVector4D( std::string key )
{
    return this->keyVals->GetVector4D(key.c_str());
}

QAngle PluginCEntityKeyValues::GetQAngle( std::string key )
{
    return this->keyVals->GetQAngle(key.c_str());
}

void PluginCEntityKeyValues::SetBool( std::string key, bool value )
{
    this->keyVals->SetBool(key.c_str(), value);
}

void PluginCEntityKeyValues::SetInt( std::string key, int value )
{
    this->keyVals->SetInt(key.c_str(), value);
}

void PluginCEntityKeyValues::SetUint( std::string key, uint value )
{
    this->keyVals->SetUint(key.c_str(), value);
}

void PluginCEntityKeyValues::SetInt64( std::string key, int64 value )
{
    this->keyVals->SetInt64(key.c_str(), value);
}

void PluginCEntityKeyValues::SetUint64( std::string key, uint64 value )
{
    this->keyVals->SetUint64(key.c_str(), value);
}

void PluginCEntityKeyValues::SetFloat( std::string key, float value )
{
    this->keyVals->SetFloat(key.c_str(), value);
}

void PluginCEntityKeyValues::SetDouble( std::string key, double value )
{
    this->keyVals->SetDouble(key.c_str(), value);
}

void PluginCEntityKeyValues::SetString( std::string key, std::string value )
{
    this->keyVals->SetString(key.c_str(), value.c_str());
}

void PluginCEntityKeyValues::SetPtr( std::string key, std::string value )
{
    this->keyVals->SetPtr(key.c_str(), (void*)(strtol(value.c_str(), nullptr, 16)));
}

void PluginCEntityKeyValues::SetStringToken( std::string key, unsigned int value )
{
    this->keyVals->SetStringToken(key.c_str(), CUtlStringToken(value));
}

void PluginCEntityKeyValues::SetColor( std::string key, Color value )
{
    this->keyVals->SetColor(key.c_str(), value);
}

void PluginCEntityKeyValues::SetVector( std::string key, Vector value )
{
    this->keyVals->SetVector(key.c_str(), value);
}

void PluginCEntityKeyValues::SetVector2D( std::string key, Vector2D value )
{
    this->keyVals->SetVector2D(key.c_str(), value);
}

void PluginCEntityKeyValues::SetVector4D( std::string key, Vector4D value )
{
    this->keyVals->SetVector4D(key.c_str(), value);
}

void PluginCEntityKeyValues::SetQAngle( std::string key, QAngle value )
{
    this->keyVals->SetQAngle(key.c_str(), value);
}

CEntityKeyValues* PluginCEntityKeyValues::GetKeyVals()
{
    return this->keyVals;
}