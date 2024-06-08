class GVMixEQ8Desc_t;

#ifndef _gcvmixeq8desc_t_h
#define _gcvmixeq8desc_t_h

#include "../../../scripting.h"


#include "GVMixFilterDesc_t.h"

class GVMixEQ8Desc_t
{
private:
    void *m_ptr;

public:
    GVMixEQ8Desc_t() {}
    GVMixEQ8Desc_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GVMixFilterDesc_t> GetStages() const { GVMixFilterDesc_t* outValue = GetSchemaValue<GVMixFilterDesc_t*>(m_ptr, "VMixEQ8Desc_t", "m_stages"); std::vector<GVMixFilterDesc_t> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetStages(std::vector<GVMixFilterDesc_t> value) { GVMixFilterDesc_t* outValue = GetSchemaValue<GVMixFilterDesc_t*>(m_ptr, "VMixEQ8Desc_t", "m_stages"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "VMixEQ8Desc_t", "m_stages", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif