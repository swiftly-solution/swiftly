class GAnimationSnapshot_t;

#ifndef _gcanimationsnapshot_t_h
#define _gcanimationsnapshot_t_h

#include "../../../scripting.h"




class GAnimationSnapshot_t
{
private:
    void *m_ptr;

public:
    GAnimationSnapshot_t() {}
    GAnimationSnapshot_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetEntIndex() const { return GetSchemaValue<int32_t>(m_ptr, "AnimationSnapshot_t", "m_nEntIndex"); }
    void SetEntIndex(int32_t value) { SetSchemaValue(m_ptr, "AnimationSnapshot_t", "m_nEntIndex", true, value); }
    CUtlString GetModelName() const { return GetSchemaValue<CUtlString>(m_ptr, "AnimationSnapshot_t", "m_modelName"); }
    void SetModelName(CUtlString value) { SetSchemaValue(m_ptr, "AnimationSnapshot_t", "m_modelName", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif