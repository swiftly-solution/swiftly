#ifndef _sdk_schema_h
#define _sdk_schema_h

#include <stdint.h>
#include <string>
#include <map>
#include <set>
#include <memory/gamedata/gamedata.h>
#include <schemasystem/schemasystem.h>
#include <vector>

extern void* gameRules;

#ifdef GetProp
#undef GetProp
#endif

#ifdef SetProp
#undef SetProp
#endif

void SetStateChanged(uintptr_t entityPtr, std::string className, std::string fieldName, int extraOffset);

namespace sch
{
    int32_t FindChainOffset(const char* className);
    
    int32_t GetOffset(const char* className, const char* memberName);
    int32_t GetOffset(uint64_t path);
    
    bool IsNetworked(const char* className, const char* memberName);
    bool IsNetworked(uint64_t path);

    bool IsStruct(const char* cName);
    bool IsClassLoaded(const char* cName);
};

namespace schema
{
    template<class T>
    T GetProp(void* entity, const char* className, const char* fieldName)
    {
        return *(T*)((uintptr_t)entity + sch::GetOffset(className, fieldName));
    }

    template<class T>
    T* GetPropPtr(void* entity, const char* className, const char* fieldName)
    {
        return (T*)((uintptr_t)entity + sch::GetOffset(className, fieldName));
    }

    void* GetSchemaPtr(void* ptr, const char* className, const char* fieldName);
    void WriteSchemaPtrValue(void* ptr, const char* className, const char* fieldName, byte* value, int size);
    void* GetVData(void* instance);

    template<class T>
    void SetProp(void* ptr, const char* className, const char* fieldName, T value)
    {
        auto m_key = sch::GetOffset(className, fieldName);

        *reinterpret_cast<std::add_pointer_t<T>>((uintptr_t)(ptr)+m_key) = value;

        if (gameRules != ptr) SetStateChanged((uintptr_t)ptr, className, fieldName, 0);
    }

    template <typename T>
    void SetPropCUtlVector(void* ptr, const char* className, const char* fieldName, std::vector<T> value)
    {
        auto m_key = sch::GetOffset(className, fieldName);

        SetStateChanged((uintptr_t)ptr, className, fieldName, 0);

        CUtlVector<T>* vec = reinterpret_cast<CUtlVector<T> *>((uintptr_t)(ptr)+m_key);
        vec->Purge();
        for (auto elem : value)
            vec->AddToTail(elem);

        SetStateChanged((uintptr_t)ptr, className, fieldName, 0);
    }
};

#endif