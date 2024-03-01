#include "schema.h"
#include "interfaces/cschemasystem.h"
#include "../utils/plat.h"
#include "entity/CBaseEntity.h"

#include <tier1/utlmap.h>

extern CSchemaSystem *g_pSchemaSystem2;

using SchemaKeyValueMap_t = CUtlMap<uint32_t, SchemaKey>;
using SchemaTableMap_t = CUtlMap<uint32_t, SchemaKeyValueMap_t *>;

typedef void (*StateChanged)(void *, Z_CBaseEntity *, int, int, int);

static bool IsFieldNetworked(SchemaClassFieldData_t &field)
{
    for (int i = 0; i < field.m_metadata_size; i++)
    {
        static auto networkEnabled = hash_32_fnv1a_const("MNetworkEnable");
        if (networkEnabled == hash_32_fnv1a_const(field.m_metadata[i].m_name))
            return true;
    }

    return false;
}

static bool InitSchemaFieldsForClass(SchemaTableMap_t *tableMap, const char *className, uint32_t classKey)
{
    CSchemaSystemTypeScope *pType = g_pSchemaSystem2->FindTypeScopeForModule(MODULE_PREFIX "server" MODULE_EXT);

    if (!pType)
        return false;

    SchemaClassInfoData_t *pClassInfo = pType->FindDeclaredClass(className);

    if (!pClassInfo)
    {
        SchemaKeyValueMap_t *map = new SchemaKeyValueMap_t(0, 0, DefLessFunc(uint32_t));
        tableMap->Insert(classKey, map);
        return false;
    }

    short fieldsSize = pClassInfo->GetFieldsSize();
    SchemaClassFieldData_t *pFields = pClassInfo->GetFields();

    SchemaKeyValueMap_t *keyValueMap = new SchemaKeyValueMap_t(0, 0, DefLessFunc(uint32_t));
    keyValueMap->EnsureCapacity(fieldsSize);
    tableMap->Insert(classKey, keyValueMap);

    for (int i = 0; i < fieldsSize; ++i)
    {
        SchemaClassFieldData_t &field = pFields[i];

        keyValueMap->Insert(hash_32_fnv1a_const(field.m_name), {field.m_offset, IsFieldNetworked(field)});
    }

    return true;
}

int16_t sch::FindChainOffset(const char *className)
{
    CSchemaSystemTypeScope *pType = g_pSchemaSystem2->FindTypeScopeForModule(MODULE_PREFIX "server" MODULE_EXT);

    if (!pType)
        return false;

    SchemaClassInfoData_t *pClassInfo = pType->FindDeclaredClass(className);

    do
    {
        SchemaClassFieldData_t *pFields = pClassInfo->GetFields();
        short fieldsSize = pClassInfo->GetFieldsSize();
        for (int i = 0; i < fieldsSize; ++i)
        {
            SchemaClassFieldData_t &field = pFields[i];

            if (V_strcmp(field.m_name, "__m_pChainEntity") == 0)
            {
                return field.m_offset;
            }
        }
    } while ((pClassInfo = pClassInfo->GetParent()) != nullptr);

    return 0;
}

SchemaKey sch::GetOffset(const char *className, uint32_t classKey, const char *memberName, uint32_t memberKey)
{
    static SchemaTableMap_t schemaTableMap(0, 0, DefLessFunc(uint32_t));
    int16_t tableMapIndex = schemaTableMap.Find(classKey);
    if (!schemaTableMap.IsValidIndex(tableMapIndex))
    {
        if (InitSchemaFieldsForClass(&schemaTableMap, className, classKey))
            return GetOffset(className, classKey, memberName, memberKey);

        return {0, 0};
    }

    SchemaKeyValueMap_t *tableMap = schemaTableMap[tableMapIndex];
    int16_t memberIndex = tableMap->Find(memberKey);
    if (!tableMap->IsValidIndex(memberIndex))
    {
        return {0, 0};
    }

    return tableMap->Element(memberIndex);
}

void SetStateChanged(Z_CBaseEntity *pEntity, int offset)
{
    if (pEntity->m_NetworkTransmitComponent())
    {
        g_Signatures->FetchSignature<StateChanged>("StateChanged")(pEntity->m_NetworkTransmitComponent(), pEntity, offset, -1, -1);

        pEntity->m_lastNetworkChange = engine->GetServerGlobals()->curtime;
        pEntity->m_isSteadyState().ClearAll();
    }
}
