class GCCSPlayer_ViewModelServices;

#ifndef _gcccsplayer_viewmodelservices_h
#define _gcccsplayer_viewmodelservices_h

#include "../../../scripting.h"


#include "GCBaseViewModel.h"

class GCCSPlayer_ViewModelServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_ViewModelServices() {}
    GCCSPlayer_ViewModelServices(void *ptr) : m_ptr(ptr) {}

    GCBaseViewModel* GetViewModel() const { return GetSchemaValue<GCBaseViewModel*>(m_ptr, "CCSPlayer_ViewModelServices", "m_hViewModel"); }
    void SetViewModel(GCBaseViewModel* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'ViewModel' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif