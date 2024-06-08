class GCFuncTrainControls;

#ifndef _gccfunctraincontrols_h
#define _gccfunctraincontrols_h

#include "../../../scripting.h"




class GCFuncTrainControls
{
private:
    void *m_ptr;

public:
    GCFuncTrainControls() {}
    GCFuncTrainControls(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif