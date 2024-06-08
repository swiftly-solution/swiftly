class GQuestProgress;

#ifndef _gcquestprogress_h
#define _gcquestprogress_h

#include "../../../scripting.h"




class GQuestProgress
{
private:
    void *m_ptr;

public:
    GQuestProgress() {}
    GQuestProgress(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif