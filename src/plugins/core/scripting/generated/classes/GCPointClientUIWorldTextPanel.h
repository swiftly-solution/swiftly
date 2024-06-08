class GCPointClientUIWorldTextPanel;

#ifndef _gccpointclientuiworldtextpanel_h
#define _gccpointclientuiworldtextpanel_h

#include "../../../scripting.h"




class GCPointClientUIWorldTextPanel
{
private:
    void *m_ptr;

public:
    GCPointClientUIWorldTextPanel() {}
    GCPointClientUIWorldTextPanel(void *ptr) : m_ptr(ptr) {}

    std::string GetMessageText() const { return GetSchemaValue<char*>(m_ptr, "CPointClientUIWorldTextPanel", "m_messageText"); }
    void SetMessageText(std::string value) { SetSchemaValue(m_ptr, "CPointClientUIWorldTextPanel", "m_messageText", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif