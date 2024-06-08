class GCNmGraphDefinition;

#ifndef _gccnmgraphdefinition_h
#define _gccnmgraphdefinition_h

#include "../../../scripting.h"


#include "GCNmGraphDefinition.h"

class GCNmGraphDefinition
{
private:
    void *m_ptr;

public:
    GCNmGraphDefinition() {}
    GCNmGraphDefinition(void *ptr) : m_ptr(ptr) {}

    std::vector<int16> GetPersistentNodeIndices() const { CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "CNmGraphDefinition", "m_persistentNodeIndices"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPersistentNodeIndices(std::vector<int16> value) { SetSchemaValueCUtlVector<int16>(m_ptr, "CNmGraphDefinition", "m_persistentNodeIndices", false, value); }
    int16_t GetRootNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmGraphDefinition", "m_nRootNodeIdx"); }
    void SetRootNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmGraphDefinition", "m_nRootNodeIdx", false, value); }
    std::vector<int16> GetVirtualParameterNodeIndices() const { CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "CNmGraphDefinition", "m_virtualParameterNodeIndices"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVirtualParameterNodeIndices(std::vector<int16> value) { SetSchemaValueCUtlVector<int16>(m_ptr, "CNmGraphDefinition", "m_virtualParameterNodeIndices", false, value); }
    std::vector<GCNmGraphDefinition> GetChildGraphSlots() const { CUtlVector<GCNmGraphDefinition>* vec = GetSchemaValue<CUtlVector<GCNmGraphDefinition>*>(m_ptr, "CNmGraphDefinition", "m_childGraphSlots"); std::vector<GCNmGraphDefinition> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetChildGraphSlots(std::vector<GCNmGraphDefinition> value) { SetSchemaValueCUtlVector<GCNmGraphDefinition>(m_ptr, "CNmGraphDefinition", "m_childGraphSlots", false, value); }
    std::vector<GCNmGraphDefinition> GetExternalGraphSlots() const { CUtlVector<GCNmGraphDefinition>* vec = GetSchemaValue<CUtlVector<GCNmGraphDefinition>*>(m_ptr, "CNmGraphDefinition", "m_externalGraphSlots"); std::vector<GCNmGraphDefinition> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetExternalGraphSlots(std::vector<GCNmGraphDefinition> value) { SetSchemaValueCUtlVector<GCNmGraphDefinition>(m_ptr, "CNmGraphDefinition", "m_externalGraphSlots", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif