class GIKSolverSettings_t;

#ifndef _gciksolversettings_t_h
#define _gciksolversettings_t_h

#include "../../../scripting.h"

#include "../types/GIKSolverType.h"


class GIKSolverSettings_t
{
private:
    void *m_ptr;

public:
    GIKSolverSettings_t() {}
    GIKSolverSettings_t(void *ptr) : m_ptr(ptr) {}

    IKSolverType GetSolverType() const { return GetSchemaValue<IKSolverType>(m_ptr, "IKSolverSettings_t", "m_SolverType"); }
    void SetSolverType(IKSolverType value) { SetSchemaValue(m_ptr, "IKSolverSettings_t", "m_SolverType", true, value); }
    int32_t GetNumIterations() const { return GetSchemaValue<int32_t>(m_ptr, "IKSolverSettings_t", "m_nNumIterations"); }
    void SetNumIterations(int32_t value) { SetSchemaValue(m_ptr, "IKSolverSettings_t", "m_nNumIterations", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif