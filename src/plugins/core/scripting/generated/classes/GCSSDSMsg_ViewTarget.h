class GCSSDSMsg_ViewTarget;

#ifndef _gccssdsmsg_viewtarget_h
#define _gccssdsmsg_viewtarget_h

#include "../../../scripting.h"




class GCSSDSMsg_ViewTarget
{
private:
    void *m_ptr;

public:
    GCSSDSMsg_ViewTarget() {}
    GCSSDSMsg_ViewTarget(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CSSDSMsg_ViewTarget", "m_Name"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_Name", false, value); }
    uint64_t GetTextureId() const { return GetSchemaValue<uint64_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_TextureId"); }
    void SetTextureId(uint64_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_TextureId", false, value); }
    int32_t GetWidth() const { return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nWidth"); }
    void SetWidth(int32_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nWidth", false, value); }
    int32_t GetHeight() const { return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nHeight"); }
    void SetHeight(int32_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nHeight", false, value); }
    int32_t GetRequestedWidth() const { return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nRequestedWidth"); }
    void SetRequestedWidth(int32_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nRequestedWidth", false, value); }
    int32_t GetRequestedHeight() const { return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nRequestedHeight"); }
    void SetRequestedHeight(int32_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nRequestedHeight", false, value); }
    int32_t GetNumMipLevels() const { return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nNumMipLevels"); }
    void SetNumMipLevels(int32_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nNumMipLevels", false, value); }
    int32_t GetDepth() const { return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nDepth"); }
    void SetDepth(int32_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nDepth", false, value); }
    int32_t GetMultisampleNumSamples() const { return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nMultisampleNumSamples"); }
    void SetMultisampleNumSamples(int32_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nMultisampleNumSamples", false, value); }
    int32_t GetFormat() const { return GetSchemaValue<int32_t>(m_ptr, "CSSDSMsg_ViewTarget", "m_nFormat"); }
    void SetFormat(int32_t value) { SetSchemaValue(m_ptr, "CSSDSMsg_ViewTarget", "m_nFormat", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif