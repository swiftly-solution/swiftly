#include "convars.h"

ConVar* FetchCVar(std::string cvarname)
{
    if (!g_pCVar)
        return nullptr;

    ConVarHandle cvarHandle = g_pCVar->FindConVar(cvarname.c_str());
    if (!cvarHandle.IsValid())
        return nullptr;

    return g_pCVar->GetConVar(cvarHandle);
}

std::any FetchCVarValue(std::string cvarname)
{
    ConVar* cvar = FetchCVar(cvarname);
    if (cvar) {
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
            char* val;
            memcpy(&val, &cvar->values, sizeof(val));
            return val;
        }
        else if (cvar->m_eVarType == EConVarType_Color)
        {
            Color val;
            memcpy(&val, &cvar->values, sizeof(val));
            return val;
        }
        else if (cvar->m_eVarType == EConVarType_Vector2)
        {
            Vector2D val;
            memcpy(&val, &cvar->values, sizeof(val));
            return val;
        }
        else if (cvar->m_eVarType == EConVarType_Vector3)
        {
            Vector val;
            memcpy(&val, &cvar->values, sizeof(val));
            return val;
        }
        else if (cvar->m_eVarType == EConVarType_Vector4)
        {
            Vector4D val;
            memcpy(&val, &cvar->values, sizeof(val));
            return val;
        }
        else if (cvar->m_eVarType == EConVarType_Qangle)
        {
            QAngle val;
            memcpy(&val, &cvar->values, sizeof(val));
            return val;
        }
        else {
            PRINTF("Unsupported ConVar type: %d. Returning null.\n", (int)cvar->m_eVarType);
            return nullptr;
        }
    }
    else if (fakeConvars.find(cvarname) != fakeConvars.end())
        return fakeConvars.at(cvarname)->GetValue();

    return nullptr;
}

EConVarType FetchCVarType(std::string cvarname)
{
    ConVar* cvar = FetchCVar(cvarname);

    if (cvar) return cvar->m_eVarType;
    else if (fakeConvars.find(cvarname) != fakeConvars.end()) return fakeConvars.at(cvarname)->GetType();
    else return EConVarType_Invalid;
}