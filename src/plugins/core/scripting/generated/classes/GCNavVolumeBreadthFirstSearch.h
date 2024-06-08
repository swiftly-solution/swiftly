class GCNavVolumeBreadthFirstSearch;

#ifndef _gccnavvolumebreadthfirstsearch_h
#define _gccnavvolumebreadthfirstsearch_h

#include "../../../scripting.h"




class GCNavVolumeBreadthFirstSearch
{
private:
    void *m_ptr;

public:
    GCNavVolumeBreadthFirstSearch() {}
    GCNavVolumeBreadthFirstSearch(void *ptr) : m_ptr(ptr) {}

    Vector GetStartPos() const { return GetSchemaValue<Vector>(m_ptr, "CNavVolumeBreadthFirstSearch", "m_vStartPos"); }
    void SetStartPos(Vector value) { SetSchemaValue(m_ptr, "CNavVolumeBreadthFirstSearch", "m_vStartPos", false, value); }
    float GetSearchDist() const { return GetSchemaValue<float>(m_ptr, "CNavVolumeBreadthFirstSearch", "m_flSearchDist"); }
    void SetSearchDist(float value) { SetSchemaValue(m_ptr, "CNavVolumeBreadthFirstSearch", "m_flSearchDist", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif