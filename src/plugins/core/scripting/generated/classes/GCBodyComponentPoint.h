class GCBodyComponentPoint;

#ifndef _gccbodycomponentpoint_h
#define _gccbodycomponentpoint_h

#include "../../../scripting.h"


#include "GCGameSceneNode.h"

class GCBodyComponentPoint
{
private:
    void *m_ptr;

public:
    GCBodyComponentPoint() {}
    GCBodyComponentPoint(void *ptr) : m_ptr(ptr) {}

    GCGameSceneNode GetSceneNode() const { return GetSchemaValue<GCGameSceneNode>(m_ptr, "CBodyComponentPoint", "m_sceneNode"); }
    void SetSceneNode(GCGameSceneNode value) { SetSchemaValue(m_ptr, "CBodyComponentPoint", "m_sceneNode", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif