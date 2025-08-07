#include "schema.h"

#include <memory/virtual/virtual.h>

#include <utils/utils.h>
#include <utils/platform/platform.h>
#include <entity2/entityinstance.h>
#include <ehandle.h>

#ifndef WIN_LINUX
#ifdef _WIN32
#define WIN_LINUX(win,linux) win
#else
#define WIN_LINUX(win,linux) linux
#endif
#endif

extern CSchemaSystem* g_pSchemaSystem2;

std::map<uint64_t, int32_t> offsetsCache;
std::map<uint64_t, bool> networkedCache;
std::set<uint32_t> structCache;
std::set<uint32_t> isClassLoaded;

static bool IsFieldNetworked(SchemaClassFieldData_t& field)
{
    static auto networkEnabled = hash_32_fnv1a_const("MNetworkEnable");
    for (int i = 0; i < field.m_nStaticMetadataCount; i++)
        if (networkEnabled == hash_32_fnv1a_const(field.m_pStaticMetadata[i].m_pszName))
            return true;

    return false;
}

bool IsStandardLayoutClass(SchemaClassInfoData_t* classData) {
    {
        auto pClass = classData;
        int classesWithFields = 0;
        do {
            classesWithFields += ((pClass->m_nSize > 1) || (pClass->m_nFieldCount != 0)) ? 1 : 0;

            if (classesWithFields > 1) return false;

            pClass = (pClass->m_pBaseClasses == nullptr) ? nullptr : pClass->m_pBaseClasses->m_pClass;
        } while (pClass != nullptr);
    }

    auto fields = classData->m_pFields;
    auto fieldsCount = classData->m_nFieldCount;
    for (uint16_t i = 0; i < fieldsCount; i++) {
        auto fieldType = fields[i].m_pType;
        if (fieldType->m_eTypeCategory == SchemaTypeCategory_t::SCHEMA_TYPE_DECLARED_CLASS) {
            CSchemaType_DeclaredClass* fClass = reinterpret_cast<CSchemaType_DeclaredClass*>(fieldType);
            if (fClass->m_pClassInfo && !IsStandardLayoutClass(fClass->m_pClassInfo)) return false;
        }
    }

    return true;
}

void PopulateClassData(const char* className, uint32_t classOffset)
{
    CSchemaSystemTypeScope* pType = g_pSchemaSystem2->FindTypeScopeForModule(MODULE_PREFIX "server" MODULE_EXT);
    if (!pType) return;

    auto classData = pType->FindDeclaredClass(className).Get();

    if (!classData) return;

    isClassLoaded.insert(classOffset);

    if (structCache.find(classOffset) == structCache.end())
        if (IsStandardLayoutClass(classData))
            structCache.insert(classOffset);

    short fieldsSize = classData->m_nFieldCount;
    SchemaClassFieldData_t* pFields = classData->m_pFields;

    for (short i = 0; i < fieldsSize; i++) {
        auto field = pFields[i];
        uint64_t offsetKey = ((uint64_t)classOffset) << 32 | hash_32_fnv1a_const(field.m_pszName);

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
    uint64_t fullOffset = ((uint64_t)classOffset) << 32 | hash_32_fnv1a_const(memberName);

    return offsetsCache[fullOffset];
}

int32_t sch::GetOffset(uint64_t path)
{
    return offsetsCache[path];
}

bool sch::IsNetworked(const char* className, const char* memberName)
{
    uint32_t classOffset = hash_32_fnv1a_const(className);
    uint64_t fullOffset = ((uint64_t)classOffset) << 32 | hash_32_fnv1a_const(memberName);

    return networkedCache[fullOffset];
}

bool sch::IsNetworked(uint64_t path)
{
    return networkedCache[path];
}

bool sch::IsStruct(const char* cName)
{
    return structCache.find(hash_32_fnv1a_const(cName)) != structCache.end();
}

bool sch::IsClassLoaded(const char* cName)
{
    return isClassLoaded.find(hash_32_fnv1a_const(cName)) != isClassLoaded.end();
}

void SetStateChanged(uintptr_t entityPtr, std::string className, std::string fieldName, int extraOffset)
{
    const char* cName = className.c_str();
    const char* fName = fieldName.c_str();

    if ((void*)entityPtr == nullptr) return;
    if (!sch::IsNetworked(cName, fName)) return;

    auto m_key = (uint32)sch::GetOffset(cName, fName);
    auto m_chain = sch::FindChainOffset(cName);

    if (m_chain) {
        entityPtr += m_chain;

        CEntityInstance* pEnt = reinterpret_cast<CNetworkVarChainer*>(entityPtr)->m_pEntity;

        if (pEnt)
            pEnt->NetworkStateChanged(NetworkStateChangedData(m_key, -1, reinterpret_cast<CNetworkVarChainer*>(entityPtr)->m_PathIndex));
    }
    else {
        auto isStruct = sch::IsStruct(cName);
        if (!isStruct) {
            reinterpret_cast<CEntityInstance*>(entityPtr)->NetworkStateChanged(NetworkStateChangedData(m_key));
        }
        else {
            NetworkStateChangedData data(m_key);
            CALL_VIRTUAL(void, WIN_LINUX(27, 28), (void*)entityPtr, &data);
        }
    }
}

void* schema::GetSchemaPtr(void* ptr, const char* className, const char* fieldName)
{
    auto m_key = sch::GetOffset(className, fieldName);

    return reinterpret_cast<void*>((uintptr_t)(ptr)+m_key);
}

void schema::WriteSchemaPtrValue(void* ptr, const char* className, const char* fieldName, byte* value, int size)
{
    const auto m_key = sch::GetOffset(className, fieldName);

    void* fieldPtr = reinterpret_cast<std::add_pointer_t<void>>((uintptr_t)(ptr)+m_key);

    Plat_WriteMemory(fieldPtr, value, size);

    SetStateChanged((uintptr_t)ptr, className, fieldName, 0);
}

void* schema::GetVData(void* instance)
{
    void* subclassPtr = schema::GetPropPtr<void>(instance, "CBaseEntity", "m_nSubclassID");
    return *(void**)((uintptr_t)subclassPtr + 4);
}