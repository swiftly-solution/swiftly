class GCompositeMaterial_t;

#ifndef _gccompositematerial_t_h
#define _gccompositematerial_t_h

#include "../../../scripting.h"


#include "GGeneratedTextureHandle_t.h"

class GCompositeMaterial_t
{
private:
    void *m_ptr;

public:
    GCompositeMaterial_t() {}
    GCompositeMaterial_t(void *ptr) : m_ptr(ptr) {}

    std::vector<GGeneratedTextureHandle_t> GetGeneratedTextures() const { CUtlVector<GGeneratedTextureHandle_t>* vec = GetSchemaValue<CUtlVector<GGeneratedTextureHandle_t>*>(m_ptr, "CompositeMaterial_t", "m_vecGeneratedTextures"); std::vector<GGeneratedTextureHandle_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetGeneratedTextures(std::vector<GGeneratedTextureHandle_t> value) { SetSchemaValueCUtlVector<GGeneratedTextureHandle_t>(m_ptr, "CompositeMaterial_t", "m_vecGeneratedTextures", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif