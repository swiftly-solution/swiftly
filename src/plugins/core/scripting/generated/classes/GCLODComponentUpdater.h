class GCLODComponentUpdater;

#ifndef _gcclodcomponentupdater_h
#define _gcclodcomponentupdater_h

#include "../../../scripting.h"




class GCLODComponentUpdater
{
private:
    void *m_ptr;

public:
    GCLODComponentUpdater() {}
    GCLODComponentUpdater(void *ptr) : m_ptr(ptr) {}

    int32_t GetServerLOD() const { return GetSchemaValue<int32_t>(m_ptr, "CLODComponentUpdater", "m_nServerLOD"); }
    void SetServerLOD(int32_t value) { SetSchemaValue(m_ptr, "CLODComponentUpdater", "m_nServerLOD", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif