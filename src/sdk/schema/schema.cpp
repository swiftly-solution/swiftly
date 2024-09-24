#include "schema.h"
#include "../interfaces/cschemasystem.h"
#include "../../utils/plat.h"
#include "../entity/CBaseEntity.h"

#include "../../entrypoint.h"
#include "../../common.h"
#include "../../utils/utils.h"

#include <map>

extern CSchemaSystem* g_pSchemaSystem2;
typedef void (*StateChanged)(void*, CBaseEntity*, int, int, int);

std::map<uint64_t, int32_t> offsetsCache;
std::map<uint64_t, bool> networkedCache;

static bool IsFieldNetworked(SchemaClassFieldData_t& field)
{
    static auto networkEnabled = hash_32_fnv1a_const("MNetworkEnable");
    for (int i = 0; i < field.m_nStaticMetadataCount; i++)
        if (networkEnabled == hash_32_fnv1a_const(field.m_pStaticMetadata[i].m_pszName))
            return true;

    return false;
}

void PopulateClassData(const char* className, uint32_t classOffset)
{
    CSchemaSystemTypeScope* pType = g_pSchemaSystem2->FindTypeScopeForModule(MODULE_PREFIX "server" MODULE_EXT);
    if(!pType) return;

    auto classData = pType->FindDeclaredClass(className);

    if(!classData) return;

    short fieldsSize = classData->m_nFieldCount;
    SchemaClassFieldData_t* pFields = classData->m_pFields;

    for(short i = 0; i < fieldsSize; i++) {
        auto field = pFields[i];
        uint64_t offsetKey = ((uint64_t) classOffset) << 32 | hash_32_fnv1a_const(field.m_pszName);
        offsetsCache.insert({ offsetKey, field.m_nSingleInheritanceOffset });
        networkedCache.insert({ offsetKey, IsFieldNetworked(field) });
    }
}

int32_t sch::FindChainOffset(const char* className)
{
    return sch::GetOffset(className, "__m_pChainEntity");
}

int32_t sch::GetOffset(const char* className, const char* memberName)
{
    uint32_t classOffset = hash_32_fnv1a_const(className);
    uint64_t fullOffset = ((uint64_t) classOffset) << 32 | hash_32_fnv1a_const(memberName);

    return offsetsCache[fullOffset];
}

int32_t sch::GetOffset(uint64_t path)
{
    return offsetsCache[path];
}

bool sch::IsNetworked(const char* className, const char* memberName)
{
    uint32_t classOffset = hash_32_fnv1a_const(className);
    uint64_t fullOffset = ((uint64_t) classOffset) << 32 | hash_32_fnv1a_const(memberName);

    return networkedCache[fullOffset];
}

bool sch::IsNetworked(uint64_t path)
{
    return networkedCache[path];
}

void SetStateChanged(uintptr_t entityPtr, std::string className, std::string fieldName, int extraOffset, bool isStruct)
{
    if ((CBaseEntity*)entityPtr == nullptr) return;
    if (!sch::IsNetworked(className.c_str(), fieldName.c_str())) return;

    auto m_key = sch::GetOffset(className.c_str(), fieldName.c_str());
    auto m_chain = sch::FindChainOffset(className.c_str());

    if (m_chain) {
        entityPtr += m_chain;
        CEntityInstance* pEntity = *reinterpret_cast<CEntityInstance**>(entityPtr);
        if (pEntity && (pEntity->m_pEntity->m_flags & EF_IS_CONSTRUCTION_IN_PROGRESS) == 0)
            pEntity->NetworkStateChanged(m_key + extraOffset, -1, *reinterpret_cast<ChangeAccessorFieldPathIndex_t*>(entityPtr + 32));
    }
    else {
        if (!isStruct)
            reinterpret_cast<CEntityInstance*>(entityPtr)->NetworkStateChanged(m_key + extraOffset);
        else
            CALL_VIRTUAL(void, 1, (CBaseEntity*)entityPtr, m_key + extraOffset, 0xFFFFFFFF, 0xFFFF);
    }
}