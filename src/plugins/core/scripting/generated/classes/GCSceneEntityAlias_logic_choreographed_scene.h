class GCSceneEntityAlias_logic_choreographed_scene;

#ifndef _gccsceneentityalias_logic_choreographed_scene_h
#define _gccsceneentityalias_logic_choreographed_scene_h

#include "../../../scripting.h"




class GCSceneEntityAlias_logic_choreographed_scene
{
private:
    void *m_ptr;

public:
    GCSceneEntityAlias_logic_choreographed_scene() {}
    GCSceneEntityAlias_logic_choreographed_scene(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif