class GViewAngleServerChange_t;

#ifndef _gcviewangleserverchange_t_h
#define _gcviewangleserverchange_t_h

#include "../../../scripting.h"

#include "../types/GFixAngleSet_t.h"


class GViewAngleServerChange_t
{
private:
    void *m_ptr;

public:
    GViewAngleServerChange_t() {}
    GViewAngleServerChange_t(void *ptr) : m_ptr(ptr) {}

    FixAngleSet_t GetType() const { return GetSchemaValue<FixAngleSet_t>(m_ptr, "ViewAngleServerChange_t", "nType"); }
    void SetType(FixAngleSet_t value) { SetSchemaValue(m_ptr, "ViewAngleServerChange_t", "nType", true, value); }
    QAngle GetAngle() const { return GetSchemaValue<QAngle>(m_ptr, "ViewAngleServerChange_t", "qAngle"); }
    void SetAngle(QAngle value) { SetSchemaValue(m_ptr, "ViewAngleServerChange_t", "qAngle", true, value); }
    uint32_t GetIndex() const { return GetSchemaValue<uint32_t>(m_ptr, "ViewAngleServerChange_t", "nIndex"); }
    void SetIndex(uint32_t value) { SetSchemaValue(m_ptr, "ViewAngleServerChange_t", "nIndex", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif