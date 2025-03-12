#include "convars.h"

ConVarRefAbstract FetchCVar(std::string cvarname)
{
    ConVarRefAbstract obj(cvarname.c_str());
    return obj;
}

std::any FetchCVarValue(std::string cvarname)
{
    ConVarRefAbstract cvar = FetchCVar(cvarname);
    CSplitScreenSlot server(0);
    if (cvar.IsValidRef()) {
        CVValue_t* v = cvar.GetConVarData()->Value(server);
        if (cvar.GetType() == EConVarType_Int16)
        {
            int16_t val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_UInt16)
        {
            uint16_t val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_UInt32)
        {
            uint32_t val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_Int32)
        {
            int32_t val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_UInt64)
        {
            uint64_t val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_Int64)
        {
            int64_t val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_Bool)
        {
            bool val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_Float32)
        {
            float val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_Float64)
        {
            double val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_String)
        {
            char* val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_Color)
        {
            Color val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_Vector2)
        {
            Vector2D val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_Vector3)
        {
            Vector val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_Vector4)
        {
            Vector4D val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else if (cvar.GetType() == EConVarType_Qangle)
        {
            QAngle val;
            memcpy(&val, v, sizeof(val));
            return val;
        }
        else {
            PRINTF("Unsupported ConVar type: %d. Returning null.\n", (int)cvar.GetType());
            return nullptr;
        }
    }
    else if (FakeConvarExists(cvarname))
        return GetFakeConvar(cvarname)->GetValue();

    return nullptr;
}

EConVarType FetchCVarType(std::string cvarname)
{
    ConVarRefAbstract cvar = FetchCVar(cvarname);

    if (cvar.IsValidRef()) return cvar.GetType();
    else if (FakeConvarExists(cvarname)) return GetFakeConvar(cvarname)->GetType();
    else return EConVarType_Invalid;
}