class GC_Chicken_GraphController;

#ifndef _gcc_chicken_graphcontroller_h
#define _gcc_chicken_graphcontroller_h

#include "../../../scripting.h"




class GC_Chicken_GraphController
{
private:
    void *m_ptr;

public:
    GC_Chicken_GraphController() {}
    GC_Chicken_GraphController(void *ptr) : m_ptr(ptr) {}

    float GetSquatProbability() const { return GetSchemaValue<float>(m_ptr, "C_Chicken_GraphController", "m_flSquatProbability"); }
    void SetSquatProbability(float value) { SetSchemaValue(m_ptr, "C_Chicken_GraphController", "m_flSquatProbability", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif