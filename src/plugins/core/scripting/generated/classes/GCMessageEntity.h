class GCMessageEntity;

#ifndef _gccmessageentity_h
#define _gccmessageentity_h

#include "../../../scripting.h"




class GCMessageEntity
{
private:
    void *m_ptr;

public:
    GCMessageEntity() {}
    GCMessageEntity(void *ptr) : m_ptr(ptr) {}

    int32_t GetRadius() const { return GetSchemaValue<int32_t>(m_ptr, "CMessageEntity", "m_radius"); }
    void SetRadius(int32_t value) { SetSchemaValue(m_ptr, "CMessageEntity", "m_radius", false, value); }
    CUtlSymbolLarge GetMessageText() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMessageEntity", "m_messageText"); }
    void SetMessageText(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CMessageEntity", "m_messageText", false, value); }
    bool GetDrawText() const { return GetSchemaValue<bool>(m_ptr, "CMessageEntity", "m_drawText"); }
    void SetDrawText(bool value) { SetSchemaValue(m_ptr, "CMessageEntity", "m_drawText", false, value); }
    bool GetDeveloperOnly() const { return GetSchemaValue<bool>(m_ptr, "CMessageEntity", "m_bDeveloperOnly"); }
    void SetDeveloperOnly(bool value) { SetSchemaValue(m_ptr, "CMessageEntity", "m_bDeveloperOnly", false, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CMessageEntity", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CMessageEntity", "m_bEnabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif