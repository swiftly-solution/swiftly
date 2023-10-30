#include "../../../../common.h"

template <typename... Args>
std::string string_format(const std::string &format, Args... args)
{
    int size_s = snprintf(nullptr, 0, format.c_str(), args...) + 1; // Extra space for '\0'
    if (size_s <= 0)
        throw std::runtime_error("Error during formatting.");

    size_t size = static_cast<size_t>(size_s);
    std::unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args...);
    return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

ConVar *FetchCVar(const char *name)
{
    if (!g_pCVar)
        return nullptr;

    ConVarHandle *cvarHandle = &g_pCVar->FindConVar(name);
    if (!cvarHandle->IsValid())
        return nullptr;

    return g_pCVar->GetConVar(*cvarHandle);
}

SMM_API int scripting_Server_GetConvarInt(const char *name)
{

    ConVar *cvar = FetchCVar(name);
    if (cvar == nullptr)
        return 0;

    if (cvar->m_eVarType == EConVarType_Int32)
    {
        int val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else
        return 0;
}

SMM_API unsigned int scripting_Server_GetConvarUint(const char *name)
{

    ConVar *cvar = FetchCVar(name);
    if (cvar == nullptr)
        return 0;

    if (cvar->m_eVarType == EConVarType_UInt32)
    {
        unsigned int val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else
        return 0;
}

SMM_API bool scripting_Server_GetConvarBool(const char *name)
{

    ConVar *cvar = FetchCVar(name);
    if (cvar == nullptr)
        return false;

    if (cvar->m_eVarType == EConVarType_Bool)
    {
        bool val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else
        return false;
}

SMM_API float scripting_Server_GetConvarFloat(const char *name)
{

    ConVar *cvar = FetchCVar(name);
    if (cvar == nullptr)
        return 0.0f;

    if (cvar->m_eVarType == EConVarType_Float32)
    {
        float val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else
        return 0.0f;
}

SMM_API const char *scripting_Server_GetConvarString(const char *name)
{
    ConVar *cvar = FetchCVar(name);
    if (cvar == nullptr)
        return "";

    if (cvar->m_eVarType == EConVarType_String)
    {
        char *val;
        memcpy(&val, &cvar->values, sizeof(val));
        return val;
    }
    else
        return "";
}

SMM_API EConVarType scripting_Server_GetConvarType(const char *name)
{
    if (!g_pCVar)
        return EConVarType_Invalid;

    ConVarHandle *cvarHandle = &g_pCVar->FindConVar(name);
    if (!cvarHandle->IsValid())
        return EConVarType_Invalid;

    ConVar *cvar = g_pCVar->GetConVar(*cvarHandle);
    return cvar->m_eVarType;
}

SMM_API void scripting_Server_SetConvar(const char *name, ...)
{
    if (!g_pCVar)
        return;

    ConVarHandle *cvarHandle = &g_pCVar->FindConVar(name);
    if (!cvarHandle->IsValid())
        return;

    ConVar *cvar = g_pCVar->GetConVar(*cvarHandle);

    va_list ap;
    va_start(ap, 1);

    if (cvar->m_eVarType == EConVarType_Bool)
        engine->ServerCommand(string_format("%s %s", name, va_arg(ap, bool) == true ? "true" : "false").c_str());
    else if (cvar->m_eVarType == EConVarType_String)
        engine->ServerCommand(string_format("%s \"%s\"", name, va_arg(ap, const char *)).c_str());
    else if (cvar->m_eVarType == EConVarType_Int32)
        engine->ServerCommand(string_format("%s %d", name, va_arg(ap, int)).c_str());
    else if (cvar->m_eVarType == EConVarType_UInt32)
        engine->ServerCommand(string_format("%s %d", name, va_arg(ap, unsigned int)).c_str());
    else if (cvar->m_eVarType == EConVarType_Float32)
        engine->ServerCommand(string_format("%s %f", name, va_arg(ap, float)).c_str());

    va_end(ap);
}
