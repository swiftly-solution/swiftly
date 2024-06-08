class GCCSPlayer_BuyServices;

#ifndef _gcccsplayer_buyservices_h
#define _gcccsplayer_buyservices_h

#include "../../../scripting.h"


#include "GSellbackPurchaseEntry_t.h"

class GCCSPlayer_BuyServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_BuyServices() {}
    GCCSPlayer_BuyServices(void *ptr) : m_ptr(ptr) {}

    std::vector<GSellbackPurchaseEntry_t> GetSellbackPurchaseEntries() const { CUtlVector<GSellbackPurchaseEntry_t>* vec = GetSchemaValue<CUtlVector<GSellbackPurchaseEntry_t>*>(m_ptr, "CCSPlayer_BuyServices", "m_vecSellbackPurchaseEntries"); std::vector<GSellbackPurchaseEntry_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSellbackPurchaseEntries(std::vector<GSellbackPurchaseEntry_t> value) { SetSchemaValueCUtlVector<GSellbackPurchaseEntry_t>(m_ptr, "CCSPlayer_BuyServices", "m_vecSellbackPurchaseEntries", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif