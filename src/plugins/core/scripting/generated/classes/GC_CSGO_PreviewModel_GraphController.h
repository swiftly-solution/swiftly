class GC_CSGO_PreviewModel_GraphController;

#ifndef _gcc_csgo_previewmodel_graphcontroller_h
#define _gcc_csgo_previewmodel_graphcontroller_h

#include "../../../scripting.h"




class GC_CSGO_PreviewModel_GraphController
{
private:
    void *m_ptr;

public:
    GC_CSGO_PreviewModel_GraphController() {}
    GC_CSGO_PreviewModel_GraphController(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif