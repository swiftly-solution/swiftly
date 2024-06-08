class GCPredictedViewModel;

#ifndef _gccpredictedviewmodel_h
#define _gccpredictedviewmodel_h

#include "../../../scripting.h"




class GCPredictedViewModel
{
private:
    void *m_ptr;

public:
    GCPredictedViewModel() {}
    GCPredictedViewModel(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif