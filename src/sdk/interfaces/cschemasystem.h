#ifndef _cschemasystem_h
#define _cschemasystem_h

#include "../../utils/virtual.h"
#include <tier0/platform.h>

struct CSchemaNetworkValue
{
    union
    {
        const char *m_sz_value;
        int m_n_value;
        float m_f_value;
        uintptr_t m_p_value;
    };
};

class SchemaClassInfoData_t;

class CSchemaSystemTypeScope
{
public:
    SchemaClassInfoData_t *FindDeclaredClass(const char *pClass)
    {
#ifdef _WIN32
        SchemaClassInfoData_t *rv = nullptr;
        CALL_VIRTUAL(void, 2, this, &rv, pClass);
        return rv;
#else
        return CALL_VIRTUAL(SchemaClassInfoData_t *, 2, this, pClass);
#endif
    }
};

class CSchemaSystem
{
public:
    auto FindTypeScopeForModule(const char *module)
    {
        return CALL_VIRTUAL(CSchemaSystemTypeScope *, 13, this, module, nullptr);
    }
};

#endif