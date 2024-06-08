class GCPlayerSprayDecalRenderHelper;

#ifndef _gccplayerspraydecalrenderhelper_h
#define _gccplayerspraydecalrenderhelper_h

#include "../../../scripting.h"




class GCPlayerSprayDecalRenderHelper
{
private:
    void *m_ptr;

public:
    GCPlayerSprayDecalRenderHelper() {}
    GCPlayerSprayDecalRenderHelper(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif