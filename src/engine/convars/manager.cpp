#include "manager.h"

#include <utils/common.h>
#include <embedder/src/Embedder.h>

#define NEW_CVAR(data_type, default_value) \
    cvarptr = (void*)(new CConVar<data_type>(cvar_name.c_str(), flags, description.c_str(), AnyCastOr<data_type>(defaultValue, default_value), min, AnyCastOr<data_type>(min_value, default_value), max, AnyCastOr<data_type>(max_value, default_value)))

#define NEW_CVAR_CLASS(data_type, str, default_value) \
    cvarptr = (void*)(new CConVar<data_type>(cvar_name.c_str(), flags, description.c_str(), AnyCastClassData<data_type>(defaultValue, str, default_value), min, AnyCastClassData<data_type>(min_value, str, default_value), max, AnyCastClassData<data_type>(max_value, str, default_value)))

#define FREE_CVAR(data_type) \
    delete (CConVar<data_type>*)cvarptr;

EConVarType ConvarManager::GetConvarType(std::string cvar_name)
{
    ConVarRefAbstract cvar(cvar_name.c_str());

    if (!cvar.IsValidRef()) return EConVarType_Invalid;
    return cvar.GetType();
}

ConvarManager::~ConvarManager()
{
    for (auto it = cvarsMap.begin(); it != cvarsMap.end(); ++it)
        DeleteConvar(it->first);
}

std::any ConvarManager::GetConvarValue(std::string cvar_name)
{
    ConVarRefAbstract cvar(cvar_name.c_str());
    CSplitScreenSlot server(0);
    if (!cvar.IsConVarDataValid()) return nullptr;

    if (cvar.GetType() == EConVarType_Int16)
    {
        return cvar.GetAs<int16>(server);
    }
    else if (cvar.GetType() == EConVarType_UInt16)
    {
        return cvar.GetAs<uint16>(server);
    }
    else if (cvar.GetType() == EConVarType_UInt32)
    {
        return cvar.GetAs<uint32>(server);
    }
    else if (cvar.GetType() == EConVarType_Int32)
    {
        return cvar.GetAs<int32>(server);
    }
    else if (cvar.GetType() == EConVarType_UInt64)
    {
        return cvar.GetAs<uint64>(server);
    }
    else if (cvar.GetType() == EConVarType_Int64)
    {
        return cvar.GetAs<int64>(server);
    }
    else if (cvar.GetType() == EConVarType_Bool)
    {
        return cvar.GetAs<bool>(server);
    }
    else if (cvar.GetType() == EConVarType_Float32)
    {
        return (float)cvar.GetAs<float32>(server);
    }
    else if (cvar.GetType() == EConVarType_Float64)
    {
        return (double)cvar.GetAs<float64>(server);
    }
    else if (cvar.GetType() == EConVarType_String)
    {
        return cvar.GetString(server).String();
    }
    else if (cvar.GetType() == EConVarType_Color)
    {
        return cvar.GetAs<Color>(server);
    }
    else if (cvar.GetType() == EConVarType_Vector2)
    {
        return cvar.GetAs<Vector2D>(server);
    }
    else if (cvar.GetType() == EConVarType_Vector3)
    {
        return cvar.GetAs<Vector>(server);
    }
    else if (cvar.GetType() == EConVarType_Vector4)
    {
        return cvar.GetAs<Vector4D>(server);
    }
    else if (cvar.GetType() == EConVarType_Qangle)
    {
        return cvar.GetAs<QAngle>(server);
    }
    else {
        PRINTF("Unsupported ConVar type: %d. Returning null.\n", (int)cvar.GetType());
        return nullptr;
    }
}

void ConvarManager::SetConvarValue(std::string cvar_name, std::any value)
{
    ConVarRefAbstract cvar(cvar_name.c_str());
    CSplitScreenSlot server(0);
    if (!cvar.IsConVarDataValid()) return;

    try {
        if (cvar.GetType() == EConVarType_Int16)
        {
            cvar.SetAs<int16>(std::any_cast<int16_t>(value), server);
        }
        else if (cvar.GetType() == EConVarType_UInt16)
        {
            cvar.SetAs<uint16>(std::any_cast<uint16_t>(value), server);
        }
        else if (cvar.GetType() == EConVarType_UInt32)
        {
            cvar.SetAs<uint32>(std::any_cast<uint32_t>(value), server);
        }
        else if (cvar.GetType() == EConVarType_Int32)
        {
            cvar.SetAs<int32>(std::any_cast<int32_t>(value), server);
        }
        else if (cvar.GetType() == EConVarType_UInt64)
        {
            cvar.SetAs<uint64>(std::any_cast<uint64_t>(value), server);
        }
        else if (cvar.GetType() == EConVarType_Int64)
        {
            cvar.SetAs<int64>(std::any_cast<int64_t>(value), server);
        }
        else if (cvar.GetType() == EConVarType_Bool)
        {
            cvar.SetAs<bool>(std::any_cast<bool>(value), server);
        }
        else if (cvar.GetType() == EConVarType_Float32)
        {
            cvar.SetAs<float32>((float32)(std::any_cast<float>(value)), server);
        }
        else if (cvar.GetType() == EConVarType_Float64)
        {
            cvar.SetAs<float64>((float64)(std::any_cast<double>(value)), server);
        }
        else if (cvar.GetType() == EConVarType_String)
        {
            if (value.type() == typeid(char*)) cvar.SetString(CUtlString(std::any_cast<char*>(value)), server);
            else if (value.type() == typeid(const char*)) cvar.SetString(CUtlString(std::any_cast<const char*>(value)), server);
            else if (value.type() == typeid(std::string)) cvar.SetString(CUtlString(std::any_cast<std::string>(value).c_str()), server);
        }
        else if (cvar.GetType() == EConVarType_Color)
        {
            cvar.SetAs<Color>(std::any_cast<ClassData*>(value)->GetData<Color>("Color_ptr"), server);
        }
        else if (cvar.GetType() == EConVarType_Vector2)
        {
            cvar.SetAs<Vector2D>(std::any_cast<ClassData*>(value)->GetData<Vector2D>("Vector2D_ptr"), server);
        }
        else if (cvar.GetType() == EConVarType_Vector3)
        {
            cvar.SetAs<Vector>(std::any_cast<ClassData*>(value)->GetData<Vector>("vector_ptr"), server);
        }
        else if (cvar.GetType() == EConVarType_Vector4)
        {
            cvar.SetAs<Vector4D>(std::any_cast<ClassData*>(value)->GetData<Vector4D>("Vector4D_ptr"), server);
        }
        else if (cvar.GetType() == EConVarType_Qangle)
        {
            cvar.SetAs<QAngle>(std::any_cast<ClassData*>(value)->GetData<QAngle>("QAngle_ptr"), server);
        }
    }
    catch (std::bad_any_cast& e) {}
}

void ConvarManager::CreateConvar(std::string cvar_name, EConVarType type, std::string description, int flags, std::any defaultValue, bool min, std::any min_value, bool max, std::any max_value)
{
    ConVarRefAbstract cvar(cvar_name.c_str());
    if (cvar.IsValidRef()) return;

    void* cvarptr = nullptr;
    if (type == EConVarType_Int16)
    {
        NEW_CVAR(int16, 0);
    }
    else if (type == EConVarType_UInt16)
    {
        NEW_CVAR(uint16, 0);
    }
    else if (type == EConVarType_UInt32)
    {
        NEW_CVAR(uint32, 0);
    }
    else if (type == EConVarType_Int32)
    {
        NEW_CVAR(int32, 0);
    }
    else if (type == EConVarType_UInt64)
    {
        NEW_CVAR(uint64, 0);
    }
    else if (type == EConVarType_Int64)
    {
        NEW_CVAR(int64, 0);
    }
    else if (type == EConVarType_Bool)
    {
        NEW_CVAR(bool, false);
    }
    else if (type == EConVarType_Float32)
    {
        NEW_CVAR(float32, 0.0f);
    }
    else if (type == EConVarType_Float64)
    {
        NEW_CVAR(float64, 0.0f);
    }
    else if (type == EConVarType_Color)
    {
        NEW_CVAR_CLASS(Color, "Color_ptr", Color(0, 0, 0, 0));
    }
    else if (type == EConVarType_Vector2)
    {
        NEW_CVAR_CLASS(Vector2D, "Vector2D_ptr", Vector2D(0.0f, 0.0f));
    }
    else if (type == EConVarType_Vector3)
    {
        NEW_CVAR_CLASS(Vector, "vector_ptr", Vector(0.0f, 0.0f, 0.0f));
    }
    else if (type == EConVarType_Vector4)
    {
        NEW_CVAR_CLASS(Vector4D, "Vector4D_ptr", Vector4D(0.0f, 0.0f, 0.0f, 0.0f));
    }
    else if (type == EConVarType_Qangle)
    {
        NEW_CVAR_CLASS(QAngle, "QAngle_ptr", QAngle(0.0f, 0.0f, 0.0f));
    }
    else if (type == EConVarType_String)
    {
        cvarptr = (void*)(new CConVar<CUtlString>(cvar_name.c_str(), flags, description.c_str(), AnyCastOr<const char*>(defaultValue, ""), min, AnyCastOr<const char*>(min_value, ""), max, AnyCastOr<const char*>(min_value, "")));
    }

    if (!cvarptr) return;

    cvarsMap.insert({ cvar_name, cvarptr });
}

void ConvarManager::DeleteConvar(std::string cvar_name)
{
    if (cvarsMap.find(cvar_name) == cvarsMap.end()) return;

    void* cvarptr = cvarsMap.at(cvar_name);
    ConVarRefAbstract cvar(cvar_name.c_str());

    if (cvar.GetType() == EConVarType_Int16)
    {
        FREE_CVAR(int16);
    }
    else if (cvar.GetType() == EConVarType_UInt16)
    {
        FREE_CVAR(uint16);
    }
    else if (cvar.GetType() == EConVarType_UInt32)
    {
        FREE_CVAR(uint32);
    }
    else if (cvar.GetType() == EConVarType_Int32)
    {
        FREE_CVAR(int32);
    }
    else if (cvar.GetType() == EConVarType_UInt64)
    {
        FREE_CVAR(uint64);
    }
    else if (cvar.GetType() == EConVarType_Int64)
    {
        FREE_CVAR(int64);
    }
    else if (cvar.GetType() == EConVarType_Bool)
    {
        FREE_CVAR(bool);
    }
    else if (cvar.GetType() == EConVarType_Float32)
    {
        FREE_CVAR(float32);
    }
    else if (cvar.GetType() == EConVarType_Float64)
    {
        FREE_CVAR(float64);
    }
    else if (cvar.GetType() == EConVarType_String)
    {
        FREE_CVAR(CUtlString);
    }
    else if (cvar.GetType() == EConVarType_Color)
    {
        FREE_CVAR(Color);
    }
    else if (cvar.GetType() == EConVarType_Vector2)
    {
        FREE_CVAR(Vector2D);
    }
    else if (cvar.GetType() == EConVarType_Vector3)
    {
        FREE_CVAR(Vector);
    }
    else if (cvar.GetType() == EConVarType_Vector4)
    {
        FREE_CVAR(Vector4D);
    }
    else if (cvar.GetType() == EConVarType_Qangle)
    {
        FREE_CVAR(QAngle);
    }
    else
    {
        free(cvarptr);
    }
}

std::map<std::string, void*> ConvarManager::GetCvarMap()
{
    return cvarsMap;
}