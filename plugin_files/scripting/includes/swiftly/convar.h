#ifndef _swiftly_convar_h
#define _swiftly_convar_h

#include "swiftly_memory.h"
#include "types.h"

union ConvarValue
{
    bool m_bValue;
    short m_i16Value;
    unsigned short m_u16Value;
    int m_i32Value;
    unsigned int m_u32Value;
    long long m_i64Value;
    unsigned long long m_u64Value;
    float m_flValue;
    double m_dbValue;
    const char *m_szValue;
};

enum ConvarType : short
{
    ConVarType_Invalid = -1,
    ConVarType_Bool,
    ConVarType_Int16,
    ConVarType_UInt16,
    ConVarType_Int32,
    ConVarType_UInt32,
    ConVarType_Int64,
    ConVarType_UInt64,
    ConVarType_Float32,
    ConVarType_Float64,
    ConVarType_String,
    ConVarType_Color,
    ConVarType_Vector2,
    ConVarType_Vector3,
    ConVarType_Vector4,
    ConVarType_Qangle
};

typedef int (*ServerGetConvarInt)(const char *);
typedef unsigned int (*ServerGetConvarUint)(const char *);
typedef bool (*ServerGetConvarBool)(const char *);
typedef float (*ServerGetConvarFloat)(const char *);
typedef const char *(*ServerGetConvarString)(const char *);

typedef ConvarType (*ServerGetConvarType)(const char *);

typedef void (*ServerSetConvar)(const char *, ...);

class Convars
{
private:
    const char *InternalFetchConvarString(const char *name)
    {
        void *getCVarStringfunc = FetchFunctionPtr(nullptr, "scripting_Server_GetConvarString");
        if (getCVarStringfunc == nullptr)
            return nullptr;

        return (reinterpret_cast<ServerGetConvarString>(getCVarStringfunc))(name);
    }

    int InternalFetchConvarInt(const char *name)
    {
        void *getCVarIntfunc = FetchFunctionPtr(nullptr, "scripting_Server_GetConvarInt");
        if (getCVarIntfunc == nullptr)
            return 0;

        return (reinterpret_cast<ServerGetConvarInt>(getCVarIntfunc))(name);
    }

    unsigned int InternalFetchConvarUint(const char *name)
    {
        void *getCVarUintfunc = FetchFunctionPtr(nullptr, "scripting_Server_GetConvarUint");
        if (getCVarUintfunc == nullptr)
            return 0;

        return (reinterpret_cast<ServerGetConvarUint>(getCVarUintfunc))(name);
    }

    bool InternalFetchConvarBool(const char *name)
    {
        void *getCVarBoolfunc = FetchFunctionPtr(nullptr, "scripting_Server_GetConvarBool");
        if (getCVarBoolfunc == nullptr)
            return 0;

        return (reinterpret_cast<ServerGetConvarBool>(getCVarBoolfunc))(name);
    }

    float InternalFetchConvarFloat(const char *name)
    {
        void *getCVarFloatfunc = FetchFunctionPtr(nullptr, "scripting_Server_GetConvarFloat");
        if (getCVarFloatfunc == nullptr)
            return 0;

        return (reinterpret_cast<ServerGetConvarFloat>(getCVarFloatfunc))(name);
    }

    ConvarType InternalFetchConvarType(const char *name)
    {
        void *getCVarTypefunc = FetchFunctionPtr(nullptr, "scripting_Server_GetConvarType");
        if (getCVarTypefunc == nullptr)
            return ConVarType_Invalid;

        return reinterpret_cast<ServerGetConvarType>(getCVarTypefunc)(name);
    }

    template <typename T>
    void InternalSetConvar(const char *name, T value)
    {
        void *setCvarfunc = FetchFunctionPtr(nullptr, "scripting_Server_SetConvar");
        if (setCvarfunc == nullptr)
            return;

        reinterpret_cast<ServerSetConvar>(setCvarfunc)(name, value);
    }

public:
    const char *GetConvarString(const char *name)
    {
        if (this->InternalFetchConvarType(name) == ConVarType_String)
            return this->InternalFetchConvarString(name);
        else
            return "";
    }

    int GetConvarInt(const char *name)
    {
        if (this->InternalFetchConvarType(name) == ConVarType_Int32)
            return this->InternalFetchConvarInt(name);
        else
            return 0;
    }
    unsigned int GetConvarUInt(const char *name)
    {
        if (this->InternalFetchConvarType(name) == ConVarType_UInt32)
            return this->InternalFetchConvarUint(name);
        else
            return 0;
    }

    float GetConvarFloat(const char *name)
    {
        if (this->InternalFetchConvarType(name) == ConVarType_Float32)
            return this->InternalFetchConvarFloat(name);
        else
            return 0.0f;
    }
    bool GetConvarBool(const char *name)
    {
        if (this->InternalFetchConvarType(name) == ConVarType_Bool)
            return this->InternalFetchConvarBool(name);
        else
            return false;
    }

    template <typename T>
    void SetConvar(const char *name, T value)
    {
        this->InternalSetConvar(name, value);
    }

    ConvarType GetConvarType(const char *name)
    {
        return this->InternalFetchConvarType(name);
    }
};

#endif