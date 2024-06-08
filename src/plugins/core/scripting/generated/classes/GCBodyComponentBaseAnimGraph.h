class GCBodyComponentBaseAnimGraph;

#ifndef _gccbodycomponentbaseanimgraph_h
#define _gccbodycomponentbaseanimgraph_h

#include "../../../scripting.h"


#include "GCBaseAnimGraph.h"
#include "GCBaseAnimGraphController.h"

class GCBodyComponentBaseAnimGraph
{
private:
    void *m_ptr;

public:
    GCBodyComponentBaseAnimGraph() {}
    GCBodyComponentBaseAnimGraph(void *ptr) : m_ptr(ptr) {}

    GCBaseAnimGraphController GetAnimationController() const { return GetSchemaValue<GCBaseAnimGraphController>(m_ptr, "CBodyComponentBaseAnimGraph", "m_animationController"); }
    void SetAnimationController(GCBaseAnimGraphController value) { SetSchemaValue(m_ptr, "CBodyComponentBaseAnimGraph", "m_animationController", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif