class GCFuncTankTrain;

#ifndef _gccfunctanktrain_h
#define _gccfunctanktrain_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCFuncTankTrain
{
private:
    void *m_ptr;

public:
    GCFuncTankTrain() {}
    GCFuncTankTrain(void *ptr) : m_ptr(ptr) {}

    GCEntityIOOutput GetOnDeath() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFuncTankTrain", "m_OnDeath"); }
    void SetOnDeath(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFuncTankTrain", "m_OnDeath", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif