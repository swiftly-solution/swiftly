class GEntComponentInfo_t;

#ifndef _gcentcomponentinfo_t_h
#define _gcentcomponentinfo_t_h

#include "../../../scripting.h"


#include "GCEntityComponent.h"
#include "GCEntityComponentHelper.h"

class GEntComponentInfo_t
{
private:
    void *m_ptr;

public:
    GEntComponentInfo_t() {}
    GEntComponentInfo_t(void *ptr) : m_ptr(ptr) {}

    std::string GetName() const { return GetSchemaValue<char*>(m_ptr, "EntComponentInfo_t", "m_pName"); }
    void SetName(std::string value) { WriteSchemaPtrValue(m_ptr, "EntComponentInfo_t", "m_pName", true, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size()); }
    std::string GetCPPClassname() const { return GetSchemaValue<char*>(m_ptr, "EntComponentInfo_t", "m_pCPPClassname"); }
    void SetCPPClassname(std::string value) { WriteSchemaPtrValue(m_ptr, "EntComponentInfo_t", "m_pCPPClassname", true, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size()); }
    std::string GetNetworkDataReferencedDescription() const { return GetSchemaValue<char*>(m_ptr, "EntComponentInfo_t", "m_pNetworkDataReferencedDescription"); }
    void SetNetworkDataReferencedDescription(std::string value) { WriteSchemaPtrValue(m_ptr, "EntComponentInfo_t", "m_pNetworkDataReferencedDescription", true, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size()); }
    std::string GetNetworkDataReferencedPtrPropDescription() const { return GetSchemaValue<char*>(m_ptr, "EntComponentInfo_t", "m_pNetworkDataReferencedPtrPropDescription"); }
    void SetNetworkDataReferencedPtrPropDescription(std::string value) { WriteSchemaPtrValue(m_ptr, "EntComponentInfo_t", "m_pNetworkDataReferencedPtrPropDescription", true, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size()); }
    int32_t GetRuntimeIndex() const { return GetSchemaValue<int32_t>(m_ptr, "EntComponentInfo_t", "m_nRuntimeIndex"); }
    void SetRuntimeIndex(int32_t value) { SetSchemaValue(m_ptr, "EntComponentInfo_t", "m_nRuntimeIndex", true, value); }
    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "EntComponentInfo_t", "m_nFlags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "EntComponentInfo_t", "m_nFlags", true, value); }
    GCEntityComponentHelper* GetBaseClassComponentHelper() const { return GetSchemaValue<GCEntityComponentHelper*>(m_ptr, "EntComponentInfo_t", "m_pBaseClassComponentHelper"); }
    void SetBaseClassComponentHelper(GCEntityComponentHelper* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'BaseClassComponentHelper' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif