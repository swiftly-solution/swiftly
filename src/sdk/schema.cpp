#include "schema.h"
#include "interfaces/cschemasystem.h"
#include "../utils/plat.h"
#include "entity/CBaseEntity.h"

#include "../entrypoint.h"
#include "../common.h"
#include "../utils/utils.h"

#include <tier1/utlmap.h>

extern CSchemaSystem* g_pSchemaSystem2;

using SchemaKeyValueMap_t = CUtlMap<uint32_t, SchemaKey>;
using SchemaTableMap_t = CUtlMap<uint32_t, SchemaKeyValueMap_t*>;

typedef void (*StateChanged)(void*, CBaseEntity*, int, int, int);

static bool IsFieldNetworked(SchemaClassFieldData_t& field)
{
    static auto networkEnabled = hash_32_fnv1a_const("MNetworkEnable");
    for (int i = 0; i < field.m_nStaticMetadataCount; i++)
        if (networkEnabled == hash_32_fnv1a_const(field.m_pStaticMetadata[i].m_pszName))
            return true;

    return false;
}

static bool InitSchemaFieldsForClass(SchemaTableMap_t* tableMap, const char* className, uint32_t classKey)
{
    CSchemaSystemTypeScope* pType = g_pSchemaSystem2->FindTypeScopeForModule(MODULE_PREFIX "server" MODULE_EXT);

    if (!pType)
        return false;

    SchemaClassInfoData_t* pClassInfo = pType->FindDeclaredClass(className);

    if (!pClassInfo)
    {
        SchemaKeyValueMap_t* map = new SchemaKeyValueMap_t(0, 0, DefLessFunc(uint32_t));
        tableMap->Insert(classKey, map);
        return false;
    }

    short fieldsSize = pClassInfo->m_nFieldCount;
    SchemaClassFieldData_t* pFields = pClassInfo->m_pFields;

    SchemaKeyValueMap_t* keyValueMap = new SchemaKeyValueMap_t(0, 0, DefLessFunc(uint32_t));
    keyValueMap->EnsureCapacity(fieldsSize);
    tableMap->Insert(classKey, keyValueMap);

    for (int i = 0; i < fieldsSize; ++i)
    {
        SchemaClassFieldData_t& field = pFields[i];

        keyValueMap->Insert(hash_32_fnv1a_const(field.m_pszName), { field.m_nSingleInheritanceOffset, IsFieldNetworked(field) });
    }

    return true;
}

int16_t sch::FindChainOffset(const char* className)
{
    CSchemaSystemTypeScope* pType = g_pSchemaSystem2->FindTypeScopeForModule(MODULE_PREFIX "server" MODULE_EXT);

    if (!pType)
        return false;

    SchemaClassInfoData_t* pClassInfo = pType->FindDeclaredClass(className);

    do
    {
        SchemaClassFieldData_t* pFields = pClassInfo->m_pFields;
        short fieldsSize = pClassInfo->m_nFieldCount;
        for (int i = 0; i < fieldsSize; ++i)
        {
            SchemaClassFieldData_t& field = pFields[i];

            if (V_strcmp(field.m_pszName, "__m_pChainEntity") == 0)
            {
                return field.m_nSingleInheritanceOffset;
            }
        }
    } while ((pClassInfo = pClassInfo->m_pBaseClasses ? pClassInfo->m_pBaseClasses->m_pClass : nullptr) != nullptr);

    return 0;
}

SchemaKey sch::GetOffset(const char* className, uint32_t classKey, const char* memberName, uint32_t memberKey)
{
    static SchemaTableMap_t schemaTableMap(0, 0, DefLessFunc(uint32_t));
    int16_t tableMapIndex = schemaTableMap.Find(classKey);
    if (!schemaTableMap.IsValidIndex(tableMapIndex))
    {
        if (InitSchemaFieldsForClass(&schemaTableMap, className, classKey))
            return GetOffset(className, classKey, memberName, memberKey);

        return { 0, 0 };
    }

    SchemaKeyValueMap_t* tableMap = schemaTableMap[tableMapIndex];
    int16_t memberIndex = tableMap->Find(memberKey);
    if (!tableMap->IsValidIndex(memberIndex))
    {
        return { 0, 0 };
    }

    return tableMap->Element(memberIndex);
}

void SetStateChanged(uintptr_t entityPtr, std::string className, std::string fieldName, int extraOffset, bool isStruct)
{
    if ((CBaseEntity*)entityPtr == nullptr) return;

    auto datatable_hash = hash_32_fnv1a_const(className.c_str());
    auto prop_hash = hash_32_fnv1a_const(fieldName.c_str());

    auto m_key = sch::GetOffset(className.c_str(), datatable_hash, fieldName.c_str(), prop_hash);
    auto m_chain = sch::FindChainOffset(className.c_str());

    if (!m_key.networked) return;

    if (m_chain) {
        entityPtr += m_chain;
        CEntityInstance* pEntity = *reinterpret_cast<CEntityInstance**>(entityPtr);
        if (pEntity && (pEntity->m_pEntity->m_flags & EF_IS_CONSTRUCTION_IN_PROGRESS) == 0)
            pEntity->NetworkStateChanged(m_key.offset + extraOffset, -1, *reinterpret_cast<ChangeAccessorFieldPathIndex_t*>(entityPtr + 32));
    }
    else {
        if (!isStruct)
            reinterpret_cast<CEntityInstance*>(entityPtr)->NetworkStateChanged(m_key.offset + extraOffset);
        else
            CALL_VIRTUAL(void, 1, (CBaseEntity*)entityPtr, m_key.offset + extraOffset, 0xFFFFFFFF, 0xFFFF);
    }
}