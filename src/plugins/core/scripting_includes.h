#pragma once

#include "../../common.h"
#include "../../entrypoint.h"
#include "../Plugin.h"
#include "../PluginManager.h"
#include "../../database/DatabaseManager.h"
#include "../../types/LogType.h"
#include "../../logs/Logger.h"
#include "../../sdk/schema.h"
#include "../../utils/plat.h"
#include "ehandle.h"

//////////////////////////////////////////////////////////////
/////////////////            Schema            //////////////
////////////////////////////////////////////////////////////

extern std::map<std::string, bool> BlockedCS2GuidelinesFields;

template <typename T>
T GetSchemaValue(void* ptr, const char* className, const char* fieldName)
{
    if (fieldName)
    {
        if (BlockedCS2GuidelinesFields.find(fieldName) != BlockedCS2GuidelinesFields.end() && g_Config->FetchValue<bool>("core.FollowCS2ServerGuidelines"))
        {
            PRINTF("Getting or setting %s::%s is not permitted due to CS2 Server Guidelines violation.\n", className, fieldName);
            PRINT("To get or set this value, switch to false the \"core.FollowCS2ServerGuidelines\" field.\n");
            PRINT("Note: Using non-compliant field values can result in a GSLT ban.\n");
            PRINT("Note: We are not providing any kind of support for people which are using these fields.\n");

            if constexpr (std::is_same<T, Vector>::value)
                return Vector(0, 0, 0);
            else if constexpr (std::is_same<T, QAngle>::value)
                return QAngle(0, 0, 0);
            else if constexpr (std::is_same<T, Vector2D>::value)
                return Vector2D(0, 0);
            else if constexpr (std::is_same<T, Vector4D>::value)
                return Vector4D(0, 0, 0, 0);
            else if constexpr (std::is_same<T, Color>::value)
                return Color(0, 0, 0, 0);
            else
                return (T)0;
        }
    }

    auto m_key = sch::GetOffset(className, fieldName);

    return *reinterpret_cast<std::add_pointer_t<T>>((uintptr_t)(ptr)+m_key);
}

template <typename T>
T* GetSchemaValuePtr(void* ptr, const char* className, const char* fieldName)
{
    if (BlockedCS2GuidelinesFields.find(fieldName) != BlockedCS2GuidelinesFields.end() && g_Config->FetchValue<bool>("core.FollowCS2ServerGuidelines"))
    {
        PRINTF("Getting or setting %s::%s is not permitted due to CS2 Server Guidelines violation.\n", className, fieldName);
        PRINT("To get or set this value, switch to false the \"core.FollowCS2ServerGuidelines\" field.\n");
        PRINT("Note: Using non-compliant field values can result in a GSLT ban.\n");
        PRINT("Note: We are not providing any kind of support for people which are using these fields.\n");
        return 0;
    }

    auto m_key = sch::GetOffset(className, fieldName);

    return reinterpret_cast<std::add_pointer_t<T>>((uintptr_t)(ptr)+m_key);
}

void* GetSchemaPtr(void* ptr, const char* className, const char* fieldName);

void WriteSchemaPtrValue(void* ptr, const char* className, const char* fieldName, bool isStruct, byte* value, int size);

template <typename T>
void SetSchemaValue(void* ptr, const char* className, const char* fieldName, bool isStruct, T value)
{
    if (BlockedCS2GuidelinesFields.find(fieldName) != BlockedCS2GuidelinesFields.end() && g_Config->FetchValue<bool>("core.FollowCS2ServerGuidelines"))
    {
        PRINTF("Getting or setting %s::%s is not permitted due to CS2 Server Guidelines violation.\n", className, fieldName);
        PRINT("To get or set this value, switch to false the \"core.FollowCS2ServerGuidelines\" field.\n");
        PRINT("Note: Using non-compliant field values can result in a GSLT ban.\n");
        PRINT("Note: We are not providing any kind of support for people which are using these fields.\n");
        return;
    }

    auto m_key = sch::GetOffset(className, fieldName);

    SetStateChanged((uintptr_t)ptr, className, fieldName, 0, isStruct);
    *reinterpret_cast<std::add_pointer_t<T>>((uintptr_t)(ptr)+m_key) = value;
}

template <typename T>
void SetSchemaValueCUtlVector(void* ptr, const char* className, const char* fieldName, bool isStruct, std::vector<T> value)
{
    if (BlockedCS2GuidelinesFields.find(fieldName) != BlockedCS2GuidelinesFields.end() && g_Config->FetchValue<bool>("core.FollowCS2ServerGuidelines"))
    {
        PRINTF("Getting or setting %s::%s is not permitted due to CS2 Server Guidelines violation.\n", className, fieldName);
        PRINT("To get or set this value, switch to false the \"core.FollowCS2ServerGuidelines\" field.\n");
        PRINT("Note: Using non-compliant field values can result in a GSLT ban.\n");
        PRINT("Note: We are not providing any kind of support for people which are using these fields.\n");
        return;
    }

    auto m_key = sch::GetOffset(className, fieldName);

    SetStateChanged((uintptr_t)ptr, className, fieldName, 0, isStruct);

    CUtlVector<T>* vec = reinterpret_cast<CUtlVector<T> *>((uintptr_t)(ptr)+m_key);
    vec->Purge();
    for (auto elem : value)
        vec->AddToTail(elem);

    SetStateChanged((uintptr_t)ptr, className, fieldName, 0, isStruct);
}