class GCPathMover;

#ifndef _gccpathmover_h
#define _gccpathmover_h

#include "../../../scripting.h"




class GCPathMover
{
private:
    void *m_ptr;

public:
    GCPathMover() {}
    GCPathMover(void *ptr) : m_ptr(ptr) {}

    float GetPathLength() const { return GetSchemaValue<float>(m_ptr, "CPathMover", "m_flPathLength"); }
    void SetPathLength(float value) { SetSchemaValue(m_ptr, "CPathMover", "m_flPathLength", false, value); }
    bool GetClosedLoop() const { return GetSchemaValue<bool>(m_ptr, "CPathMover", "m_bClosedLoop"); }
    void SetClosedLoop(bool value) { SetSchemaValue(m_ptr, "CPathMover", "m_bClosedLoop", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif