#include "../scripting.h"
#include "../../../entrypoint.h"

ConVar *FetchCVar(std::string cvarname)
{
    if (!g_pCVar)
        return nullptr;

    ConVarHandle cvarHandle = g_pCVar->FindConVar(cvarname.c_str());
    if (!cvarHandle.IsValid())
        return nullptr;

    return g_pCVar->GetConVar(cvarHandle);
}

PluginConvars::PluginConvars(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

std::any PluginConvars::GetConvarValue(std::string cvarname)
{
    ConVar *cvar = FetchCVar(cvarname);
    if (!cvar)
        return nullptr;

    if (cvar->m_eVarType == EConVarType_Int16)
    {
        int16_t val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else if (cvar->m_eVarType == EConVarType_UInt16)
    {
        uint16_t val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else if (cvar->m_eVarType == EConVarType_UInt32)
    {
        uint32_t val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else if (cvar->m_eVarType == EConVarType_Int32)
    {
        int32_t val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else if (cvar->m_eVarType == EConVarType_UInt64)
    {
        uint64_t val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else if (cvar->m_eVarType == EConVarType_Int64)
    {
        int64_t val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else if (cvar->m_eVarType == EConVarType_Bool)
    {
        bool val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else if (cvar->m_eVarType == EConVarType_Float32)
    {
        float val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else if (cvar->m_eVarType == EConVarType_Float64)
    {
        double val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else if (cvar->m_eVarType == EConVarType_String)
    {
        char *val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }

    return 0;
}

luabridge::LuaRef PluginConvars::GetConvarValueLua(std::string cvarname, lua_State *L)
{
    return LuaSerializeData(GetConvarValue(cvarname), L);
}

int16_t PluginConvars::GetConvarType(std::string cvarname)
{
    ConVar *cvar = FetchCVar(cvarname);
    if (!cvar)
        return EConVarType::EConVarType_Invalid;

    return (int16_t)cvar->m_eVarType;
}

void PluginConvars::SetConvar(std::string cvarname, std::string value)
{
    ConVar *cvar = FetchCVar(cvarname);
    if (!cvar)
        return;

    if (cvar->m_eVarType == EConVarType_String)
        engine->ServerCommand(string_format("%s \"%s\"", cvarname.c_str(), value.c_str()).c_str());
    else
        engine->ServerCommand(string_format("%s %s", cvarname.c_str(), value.c_str()).c_str());
}