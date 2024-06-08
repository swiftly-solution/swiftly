class GCFootTrajectories;

#ifndef _gccfoottrajectories_h
#define _gccfoottrajectories_h

#include "../../../scripting.h"


#include "GCFootTrajectory.h"

class GCFootTrajectories
{
private:
    void *m_ptr;

public:
    GCFootTrajectories() {}
    GCFootTrajectories(void *ptr) : m_ptr(ptr) {}

    std::vector<GCFootTrajectory> GetTrajectories() const { CUtlVector<GCFootTrajectory>* vec = GetSchemaValue<CUtlVector<GCFootTrajectory>*>(m_ptr, "CFootTrajectories", "m_trajectories"); std::vector<GCFootTrajectory> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTrajectories(std::vector<GCFootTrajectory> value) { SetSchemaValueCUtlVector<GCFootTrajectory>(m_ptr, "CFootTrajectories", "m_trajectories", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif