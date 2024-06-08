class GCPhysHingeAlias_phys_hinge_local;

#ifndef _gccphyshingealias_phys_hinge_local_h
#define _gccphyshingealias_phys_hinge_local_h

#include "../../../scripting.h"




class GCPhysHingeAlias_phys_hinge_local
{
private:
    void *m_ptr;

public:
    GCPhysHingeAlias_phys_hinge_local() {}
    GCPhysHingeAlias_phys_hinge_local(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif