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

template <typename T>
T GetSchemaValue(void *ptr, const char *className, const char *fieldName)
{
    auto datatable_hash = hash_32_fnv1a_const(className);
    auto prop_hash = hash_32_fnv1a_const(fieldName);
    const auto m_key = sch::GetOffset(className, datatable_hash, fieldName, prop_hash);

    return *reinterpret_cast<std::add_pointer_t<T>>((uintptr_t)(ptr) + m_key.offset);
}

template <typename T>
T *GetSchemaValuePtr(void *ptr, const char *className, const char *fieldName)
{
    auto datatable_hash = hash_32_fnv1a_const(className);
    auto prop_hash = hash_32_fnv1a_const(fieldName);
    const auto m_key = sch::GetOffset(className, datatable_hash, fieldName, prop_hash);

    return reinterpret_cast<std::add_pointer_t<T>>((uintptr_t)(ptr) + m_key.offset);
}

void WriteSchemaPtrValue(void *ptr, const char *className, const char *fieldName, bool isStruct, byte *value, int size);

template <typename T>
void SetSchemaValue(void *ptr, const char *className, const char *fieldName, bool isStruct, T value)
{
    auto datatable_hash = hash_32_fnv1a_const(className);
    auto prop_hash = hash_32_fnv1a_const(fieldName);

    auto m_key = sch::GetOffset(className, datatable_hash, fieldName, prop_hash);
    auto m_chain = sch::FindChainOffset(className);

    if (m_chain != 0 && m_key.networked)
        g_Signatures->FetchSignature<NetworkSTChange>("NetworkStateChanged")((uintptr_t)(ptr) + m_chain, m_key.offset, 0xFFFFFFFF);
    else if (m_key.networked)
    {
        if (!isStruct)
            SetStateChanged((Z_CBaseEntity *)ptr, m_key.offset);
        else if (IsPlatformPosix())
            CALL_VIRTUAL(void, 1, ptr, m_key.offset, 0xFFFFFFFF, 0xFFFF);
    }
    *reinterpret_cast<std::add_pointer_t<T>>((uintptr_t)(ptr) + m_key.offset) = value;
}

template <typename T>
void SetSchemaValueCUtlVector(void *ptr, const char *className, const char *fieldName, bool isStruct, std::vector<T> value)
{
    auto datatable_hash = hash_32_fnv1a_const(className);
    auto prop_hash = hash_32_fnv1a_const(fieldName);

    auto m_key = sch::GetOffset(className, datatable_hash, fieldName, prop_hash);
    auto m_chain = sch::FindChainOffset(className);

    if (m_chain != 0 && m_key.networked)
        g_Signatures->FetchSignature<NetworkSTChange>("NetworkStateChanged")((uintptr_t)(ptr) + m_chain, m_key.offset, 0xFFFFFFFF);
    else if (m_key.networked)
    {
        if (!isStruct)
            SetStateChanged((Z_CBaseEntity *)ptr, m_key.offset);
        else if (IsPlatformPosix())
            CALL_VIRTUAL(void, 1, ptr, m_key.offset, 0xFFFFFFFF, 0xFFFF);
    }

    CUtlVector<T> *vec = reinterpret_cast<CUtlVector<T> *>((uintptr_t)(ptr) + m_key.offset);
    vec->Purge();
    for (auto elem : value)
        vec->AddToTail(elem);
}